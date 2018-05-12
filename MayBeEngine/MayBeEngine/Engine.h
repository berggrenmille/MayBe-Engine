#pragma once
#include "Window.h"


namespace MayBe
{
	namespace Core
	{
		class Engine
		{
		public:
			//Get Singleton instance
			static Engine* GetInstance();
			//Add a window to the window vector
			void AddWindowWithGLContext();
			//Pop a window from the window vector
			void RemoveWindow();
			//Update the engine
			void Tick();
			bool isRunning = true;

			~Engine();
		private:
			//Pointer to the singleton instance
			static std::unique_ptr<Engine> m_instance;
			//The Window vector is handled according to the FILO(First In Last Out) rule
			std::vector<Window*> m_windows;
			//Private constructor so no instance can be created outside of class
			Engine()
			{
			}
		};

	}
}
