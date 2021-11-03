#include "Window.h"

namespace WindowWrapper {

    void framebuffer_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

    Window::Window(int width, int height, const std::string& windowName)
        : m_Width(width)
        , m_Height(height)
        , m_Name(windowName)
        , m_pWindow(nullptr)
    {
        if (!glfwInit())
        {
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_pWindow = glfwCreateWindow(m_Width, m_Height, m_Name.c_str(), NULL, NULL);
        if (m_pWindow)
        {
            glfwMakeContextCurrent(m_pWindow);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                glfwDestroyWindow(m_pWindow);
                m_pWindow = nullptr;
                return;
            }

            glViewport(0, 0, 800, 600);
            glfwSetFramebufferSizeCallback(m_pWindow, framebuffer_size_callback);

            // configure global opengl state
            // -----------------------------
            glEnable(GL_DEPTH_TEST);
        }
    }

    Window::~Window() { glfwTerminate(); }

    void Window::RunRenderLoop(std::function<void()> f_UserRenderFunc)
    {
        if (!IsValid())
            return;

        while (!glfwWindowShouldClose(m_pWindow))
        {
            ProcessInputs();

            f_UserRenderFunc();

            glfwSwapBuffers(m_pWindow);
            glfwPollEvents();
        }
    }

    int Window::RegisterInputProcessor(std::function<void(GLFWwindow* window)> f_ProcessInput)
    {

        m_InputProcessors.insert({m_NextProcessorID, f_ProcessInput});
        return m_NextProcessorID++;
    }

    void Window::UnregisterInputProcessor(int id)
    {
        auto it = m_InputProcessors.find(id);
        if (it != m_InputProcessors.end())
        {
            m_InputProcessors.erase(it);
        }
    }

    void Window::ProcessInputs() {
        if (glfwGetKey(m_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_pWindow, true);

        for (auto& InputProcessor : m_InputProcessors)
        {
            InputProcessor.second(m_pWindow);
        }
    }

} // namespace WindowWrapper
