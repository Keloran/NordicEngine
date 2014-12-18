#include <NordicEngine/Window/Window.hpp>
#include <NordicEngine/Input/Input.hpp>
#include <NordicEngine/Exceptions/Exceptions.hpp>

namespace NordicArts {
    namespace NordicEngine {
        Window::Window() {
            initWindow();
        }
        Window::Window(Logger *pLogger) : m_pLogger(pLogger) {
            initWindow();
        }

        void Window::initWindow() {
            glfwSetErrorCallback(Window::errorHandler);

            // GLFW
            if (!glfwInit()) {
                throw new Exceptions("Can't initalize GLFW", true);
            }

            // GLEW
            glewExperimental = GL_TRUE;
            GLenum glewStatus = glewInit();
            if (glewStatus != GLEW_OK) {
                throw new Exceptions(glewGetErrorString(glewStatus), true);
            }
        }

        Window::~Window() {
            glfwDestroyWindow(m_pWindow);
            glfwTerminate();

            m_pWindow = nullptr;
            m_pLogger = nullptr;
        }

        int Window::createWindow(int iWidth, int iHeight, std::string cTitle) {
            m_pWindow = glfwCreateWindow(iWidth, iHeight, cTitle.c_str(), NULL, NULL);
            if (!m_pWindow) {
                glfwTerminate();
        
                throw new Exceptions("Can't create the window", true);
            }

            glfwMakeContextCurrent(m_pWindow);
            glfwSetKeyCallback(m_pWindow, Input::handleInput);

            return 0;
        }

        void Window::clear(Color oColor) {
        }

        void Window::setOpenGL() {
            setOpenGL(3, 2);
        }
        void Window::setOpenGL(int iMajor, int iMinor) {
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, iMajor);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, iMinor);
            glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        }

        void Window::setVSync(bool bEnable) {
            if (bEnable) {
                glfwSwapInterval(1);
            }
        }

        bool Window::isWindowOpen() const {
            return !glfwWindowShouldClose(m_pWindow);
        }

        void Window::draw() {
            return display();
        }
        void Window::display() {
            // Do Movements before redraw
            glfwPollEvents();

            // Redraw
            glfwSwapBuffers(m_pWindow);
        }

        void Window::errorHandler(int iError, const char *cDescription) {
            throw new Exceptions(cDescription, iError, true);
        }

        void Window::getFrameBufferSize(int *iWidth, int *iHeight) {
            m_iWidth    = *iWidth;
            m_iHeight   = *iHeight;

            glfwGetFramebufferSize(m_pWindow, iWidth, iHeight);
        }
    };
};
