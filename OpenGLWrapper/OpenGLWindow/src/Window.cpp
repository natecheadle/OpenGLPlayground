#include "Window.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

namespace OpenGLWrapper {

    void framebuffer_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

    Window::Window(int width, int height, const std::string& windowName)
        : m_Width(width)
        , m_Height(height)
        , m_Name(windowName)
        , m_pWindow(nullptr)
        , m_NextProcessorID(0)
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

    int Window::RegisterInputProcessor(std::function<void(Window* window)> f_ProcessInput)
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

    bool Window::IsKeyPressed(Key key) { return glfwGetKey(m_pWindow, TranslateKey(key)) == GLFW_PRESS; }
    
    double Window::GetCurrentTime() { return glfwGetTime(); }

    void Window::ProcessInputs()
    {
        if (glfwGetKey(m_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_pWindow, true);

        for (auto& InputProcessor : m_InputProcessors)
        {
            InputProcessor.second(this);
        }
    }

    int Window::TranslateKey(Key key)
    {
        switch (key)
        {
            // Numbers
        case Key::Zero: return GLFW_KEY_0;
        case Key::One: return GLFW_KEY_1;
        case Key::Two: return GLFW_KEY_2;
        case Key::Three: return GLFW_KEY_3;
        case Key::Four: return GLFW_KEY_4;
        case Key::Five: return GLFW_KEY_5;
        case Key::Six: return GLFW_KEY_6;
        case Key::Seven: return GLFW_KEY_7;
        case Key::Eight: return GLFW_KEY_8;
        case Key::Nine:
            return GLFW_KEY_9;

            // Letters
        case Key::A: return GLFW_KEY_A;
        case Key::B: return GLFW_KEY_B;
        case Key::C: return GLFW_KEY_C;
        case Key::D: return GLFW_KEY_D;
        case Key::E: return GLFW_KEY_E;
        case Key::F: return GLFW_KEY_F;
        case Key::G: return GLFW_KEY_G;
        case Key::H: return GLFW_KEY_H;
        case Key::I: return GLFW_KEY_I;
        case Key::J: return GLFW_KEY_J;
        case Key::K: return GLFW_KEY_K;
        case Key::L: return GLFW_KEY_L;
        case Key::M: return GLFW_KEY_M;
        case Key::N: return GLFW_KEY_N;
        case Key::O: return GLFW_KEY_O;
        case Key::P: return GLFW_KEY_P;
        case Key::Q: return GLFW_KEY_Q;
        case Key::R: return GLFW_KEY_R;
        case Key::S: return GLFW_KEY_S;
        case Key::T: return GLFW_KEY_T;
        case Key::U: return GLFW_KEY_U;
        case Key::V: return GLFW_KEY_V;
        case Key::W: return GLFW_KEY_W;
        case Key::X: return GLFW_KEY_X;
        case Key::Y: return GLFW_KEY_Y;
        case Key::Z: return GLFW_KEY_Z;

        // Arrow Keys
        case Key::Up: return GLFW_KEY_UP;
        case Key::Down: return GLFW_KEY_DOWN;
        case Key::Left: return GLFW_KEY_LEFT;
        case Key::Right: return GLFW_KEY_RIGHT;

        // Function Keys
        case Key::Escape: return GLFW_KEY_ESCAPE;
        case Key::Enter: return GLFW_KEY_ENTER;
        case Key::Tab: return GLFW_KEY_TAB;
        case Key::Backspace: return GLFW_KEY_BACKSPACE;
        case Key::Insert: return GLFW_KEY_INSERT;
        case Key::Delete: return GLFW_KEY_DELETE;
        }

        return 0;
    }

} // namespace OpenGLWrapper
