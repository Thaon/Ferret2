// Raay.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include "F2.h"

#include "Cube.cpp"

//undefinde main, to make the program compile, weird shit...
#undef main

bool quit;


int main(int argc, char *argv[])
{
	F2* game = new F2();

	//create entities
	std::shared_ptr<Cube> cube = std::make_shared<Cube>();

	//add them to the scene
	game->GetCurrentScene()->AddEntity(cube);

	game->Init(800, 600);
	game->Run(30);

	return 0;
}

