#pragma once
#include <GLFW/glfw3.h>
#include <memory>

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


	int GetWindowID() const;
	GLFWwindow* GetInternalWindow();
	bool HasMouseFocus() const;
	bool HasKeyboardFocus() const;
	bool IsMinimized() const;
	bool IsShown() const;

private:
	//Display Kernel
	std::unique_ptr<GLFWwindow*> m_internalWindow;
	int m_windowID;

	//Window properties
	int m_width;
	int m_height;

	bool m_mouseFocus;
	bool m_keyboardFocus;
	bool m_fullScreen;
	bool m_minimized;
	bool m_shown;

	
};
