#include "stdafx.h"
#include "RenderSystem.h"


RenderSystem::RenderSystem()
{
}


RenderSystem::~RenderSystem()
{
}

bool RenderSystem::Init()
{
	GLfloat LightModelAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LightModelAmbient);

	GLfloat LightAmbient[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);

	GLfloat LightDiffuse[] = { 0.75f, 0.75f, 0.75f, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);

	GLfloat MaterialAmbient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MaterialAmbient);

	GLfloat MaterialDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MaterialDiffuse);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	return true;
}

void RenderSystem::Render(std::shared_ptr<Scene> scene)
{
	for (std::shared_ptr<Entity> e : scene->GetEntities())
	{
		if (e->GetRenderer() != nullptr)
		{
			//we render the shit out of this entity!
			e->GetRenderer()->Draw();
		}
	}
}
