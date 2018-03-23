#include "stdafx.h"
#include "Display.h"

Window::Window(int width, int height)
	: m_internalWindow(nullptr), m_windowID(-1), m_width(width), m_height(height), m_mouseFocus(true), m_keyboardFocus(true), m_fullScreen(false), m_minimized(false), m_shown(true)
{}

//Init window
bool Window::Initialize()
{
	m_internalWindow = std::make_unique<GLFWwindow*>(glfwCreateWindow(m_width, m_height, "Test", nullptr, nullptr));
	if(!m_internalWindow.get())
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(GetInternalWindow());

	return true;
}

void Window::Destroy()
{
	glfwDestroyWindow(GetInternalWindow());
}

int Window::GetWidth() const
{
	
	return m_width;
}

int Window::GetHeight() const
{
	return m_width;
}

int Window::GetWindowID() const
{
	return m_windowID;
}

GLFWwindow* Window::GetInternalWindow()
{
	return *m_internalWindow.get();
}

bool Window::HasMouseFocus() const
{
	return m_mouseFocus;
}

bool Window::HasKeyboardFocus() const
{
	return m_keyboardFocus;
}

bool Window::IsMinimized() const
{
	return m_minimized;
}

bool Window::IsShown() const
{
	return m_shown;
}

