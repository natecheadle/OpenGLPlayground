#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <functional>
#include <map>
#include <string>

namespace WindowWrapper {
    class Window {
        int         m_Width;
        int         m_Height;
        std::string m_Name;
        GLFWwindow* m_pWindow;
        int         m_NextProcessorID;

        std::map<int, std::function<void(GLFWwindow* window)>> m_InputProcessors;

      public:
        Window(int width, int height, const std::string& windowName);
        ~Window();

        bool IsValid() { return m_pWindow != nullptr; }
        void RunRenderLoop(std::function<void()> f_UserRenderFunc);

        int  RegisterInputProcessor(std::function<void(GLFWwindow* window)> f_ProcessInput);
        void UnregisterInputProcessor(int id);

      private:
        void ProcessInputs();
    };
} // namespace WindowWrapper
