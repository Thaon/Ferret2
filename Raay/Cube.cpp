#include "stdafx.h"

#include "F2.h"

class Cube : public Entity
{
	void Start()
	{
		AddRenderer(std::make_shared<RenderComponent>());
		GetRenderer()->SetType(Type::cube); //example, cube is already set as default
	}
};