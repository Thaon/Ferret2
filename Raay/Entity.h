#pragma once
#include <vector>
#include <memory>

#include "RenderComponent.h"

class Entity
{
private:
	std::shared_ptr<RenderComponent> m_renderComponent = nullptr;

public:
	Entity();
	~Entity();

	//getters and setters
	std::shared_ptr<RenderComponent> GetRenderer() { return m_renderComponent; }
};

