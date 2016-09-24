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

	void Start() {};
	void Update() {};

	//getters and setters
	std::shared_ptr<RenderComponent> GetRenderer() { return m_renderComponent; }
	void AddRenderer(std::shared_ptr<RenderComponent> renderer) { m_renderComponent = renderer; }
};

