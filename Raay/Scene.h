#pragma once
#include "Entity.h"

class Scene
{
private:
	std::vector<std::shared_ptr<Entity>> m_entities;

public:
	Scene();
	~Scene();


	//getters and setters
	std::vector<std::shared_ptr<Entity>> GetEntities() { return m_entities; }
	void AddEntity(std::shared_ptr<Entity> entity) { m_entities.push_back(entity); }
};

