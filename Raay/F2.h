#pragma once

#include "stdafx.h"
#include <iostream>
#include "RenderSystem.h"

class F2
{
private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	SDL_Event m_sdlEvent;

	int m_width;
	int m_height;

	bool m_isRunning;

	std::unique_ptr<RenderSystem> m_renderSys;


	std::vector<std::shared_ptr<Scene>> m_sceneManager;
	std::shared_ptr<Scene> m_currentScene;


	void PollInput();

public:
	F2();
	~F2();

	bool Init(int w, int h);
	void Run(float deltaTime);

	//getters and setters
	std::shared_ptr<Scene> GetCurrentScene() { return m_currentScene; }
	std::vector<std::shared_ptr<Scene>> GetAllScenes() { return m_sceneManager; }
};

