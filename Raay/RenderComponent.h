#pragma once

// OpenGL headers
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>

// SDL headers
#include <SDL_main.h>
#include <SDL.h>
#include <SDL_opengl.h>

enum Type { cube };

class RenderComponent
{
private:
	Type m_type = Type::cube;

public:
	RenderComponent();
	~RenderComponent();

	void Draw();

	//getters and setters
	void SetType(Type t) { m_type = t; }
};

