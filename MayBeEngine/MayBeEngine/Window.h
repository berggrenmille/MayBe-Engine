#pragma once
#include <GLFW/glfw3.h>
#include <memory>
namespace MayBe
{
	namespace Core
	{
		class Window
		{
		public:
			//Init internals
			Window(int width, int height);

			bool Initialize();
			void Destroy();

			//Get window properties
			int GetWidth() const;
			int GetHeight() const;
			int GetWindowId() const;
			GLFWwindow* GetInternalWindow() const;
			bool HasMouseFocus() const;
			bool HasKeyboardFocus() const;
			bool IsMinimized() const;
			bool IsShown() const;

		private:
			//Important shit
			GLFWwindow* m_internalWindow; //Pointer to glfw's window wrapper
			int m_windowId; //The window's unique id

			//Window properties
			int m_width; //The window's width
			int m_height; //The window's height
			bool m_mouseFocus;
			bool m_keyboardFocus;
			bool m_fullScreen;
			bool m_minimized;
			bool m_shown;
		};
	}
}
