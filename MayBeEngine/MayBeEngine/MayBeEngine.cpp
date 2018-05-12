// MayBeEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"

using namespace MayBe::Core;

int main()
{
	Engine::GetInstance()->AddWindowWithGLContext();
	while(Engine::GetInstance()->isRunning)
		Engine::GetInstance()->Tick();
	
	
    return 0;
}

