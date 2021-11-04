#include "Keys.h"

#include <functional>
#include <map>
#include <string>

typedef struct GLFWwindow GLFWwindow;

namespace OpenGLWrapper {
    class Window {

        int         m_Width;
        int         m_Height;
        std::string m_Name;
        GLFWwindow* m_pWindow;
        int         m_NextProcessorID;

        std::map<int, std::function<void(Window* window)>> m_InputProcessors;

      public:
        Window(int width, int height, const std::string& windowName);
        ~Window();

        bool IsValid() { return m_pWindow != nullptr; }
        void RunRenderLoop(std::function<void()> f_UserRenderFunc);

        int  RegisterInputProcessor(std::function<void(Window* window)> f_ProcessInput);
        void UnregisterInputProcessor(int id);

        bool IsKeyPressed(Key key);
        double GetCurrentTime();

      private:
        void ProcessInputs();
        static int TranslateKey(Key key);
    };
} // namespace OpenGLWrapper
