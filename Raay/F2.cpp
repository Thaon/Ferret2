#include "stdafx.h"
#include "F2.h"


F2::F2()
{
}


F2::~F2()
{
}

bool F2::Init(int w, int h)
{
	//Use OpenGL 3.1 core
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Initialize video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		// Display error message
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		// Create window
		m_window = SDL_CreateWindow("F2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (m_window == NULL)
		{
			// Display error message
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			// Create OpenGL context
			m_glContext = SDL_GL_CreateContext(m_window);

			if (m_glContext == NULL)
			{
				// Display error message
				printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				return false;
			}
			else
			{
				// Initialize glew
				glewInit();

				//get the first scene
				m_sceneManager = std::vector<std::shared_ptr<Scene>>();
				m_sceneManager.push_back(std::make_shared<Scene>());
				m_currentScene = m_sceneManager[0]; //shared since the scene is passed to the RenderSystem!!!

				//initialise all entities
				for (std::shared_ptr<Entity> e : m_currentScene->GetEntities())
				{
					e->Start();
				}

				//create all the systems
				m_renderSys = std::make_unique<RenderSystem>();
				m_renderSys->Init();

			}
		}
	}
}

void F2::Run(float deltaTime)
{
	while (m_isRunning)
	{
		while (SDL_PollEvent(&m_sdlEvent) != 0)
		{
			// Esc button is pressed
			if (m_sdlEvent.type == SDL_QUIT)
			{
				m_isRunning = false;
			}

			//get input here and send to the input manager
		}

		// Set background color as cornflower blue
		glClearColor(0.39f, 0.58f, 0.93f, 1.f);
		// Clear color buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Render each one of the entities
		m_renderSys->Render(m_currentScene);
		// Update window with OpenGL rendering
		SDL_GL_SwapWindow(m_window);
	}

	//Destroy window
	SDL_DestroyWindow(m_window);
	m_window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
