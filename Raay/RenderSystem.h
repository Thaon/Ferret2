#pragma once

#include "RenderComponent.h"
#include "Scene.h"


class RenderSystem
{
private:

public:
	RenderSystem();
	~RenderSystem();

	bool Init();
	void Render(std::shared_ptr<Scene> scene);
};

