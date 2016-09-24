#pragma once

#include "stdafx.h"
#include <iostream>
// OpenGL headers
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>

// SDL headers
#include <SDL_main.h>
#include <SDL.h>
#include <SDL_opengl.h>

class F2
{
private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	SDL_Event m_sdlEvent;
	bool m_isRunning;

	void Render();
	void PollInput();

public:
	F2();
	~F2();

	bool Init(int w, int h);
	void Run();

	//getters and setters
};

