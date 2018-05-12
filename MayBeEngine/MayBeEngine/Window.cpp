#include "stdafx.h"
#include "Window.h"
#include <iostream>
using namespace MayBe::Core;

Window::Window(int width, int height)
	: m_internalWindow(nullptr), m_windowId(-1), m_width(width), m_height(height), m_mouseFocus(true), m_keyboardFocus(true), m_fullScreen(false), m_minimized(false), m_shown(true)
{}

//Init window
bool Window::Initialize()
{
	m_internalWindow = glfwCreateWindow(m_width, m_height, "Test", NULL, NULL);
	if(m_internalWindow == nullptr)
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(GetInternalWindow());
	std::cout << "test";
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

int Window::GetWindowId() const
{
	return m_windowId;
}

GLFWwindow* Window::GetInternalWindow() const
{
	return m_internalWindow;
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

