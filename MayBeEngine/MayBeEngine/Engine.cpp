#include "stdafx.h"
#include "Engine.h"
#include <iostream>
using namespace MayBe::Core;

std::unique_ptr<Engine> Engine::m_instance = nullptr;

Engine* Engine::GetInstance()
{
	if (!m_instance)
	{
		m_instance = std::make_unique<Engine>(Engine());
	}
	return m_instance.get();
}

void Engine::AddWindowWithGLContext()
{
	m_windows.push_back(new Window(1280,720));
	if(m_windows[m_windows.size()-1]->Initialize() == false)
	{
		RemoveWindow();
	}
}

void Engine::RemoveWindow()
{
	//The Window vector is handled according to the FILO rule
	m_windows.back()->Destroy();
	delete m_windows.back();
	m_windows.pop_back();
}


void Engine::Tick()
{
	glfwShowWindow(m_windows[0]->GetInternalWindow());
}

Engine::~Engine()
{
	int i = m_windows.size();
	if(i > 0)
	{
		for (int j = 0; j < i; ++j)
		{
			m_windows.back()->Destroy();
			delete m_windows.back();
			m_windows.pop_back();
		}
	}
	
}


