#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Obstacle.h"

	Game::Game()
	{
		numObjects = 0;
		play = true;

		AddObject(new Obstacle(5, 5, "O", Red , 0));

		AddObject(new Player(10, 10, "P", Green, 0, "bob"));

		




	}

	void Game::SpawnObs()
	{

	}

	void Game::Update()
	{
		for (size_t i = 0; i < objects.size(); i++)
		{
			objects[i]->Update();
		}
	}

	void Game::Render()
	{
		for (size_t i = 0; i < objects.size(); i++)
		{
			objects[i]->Render();
		}
	}

	void Game::AddObject(Base* inBase)
	{
		objects.push_back(inBase);
		numObjects++;

	}

	void Game::start()
	{
		while (play) {

			
			
				Update();
				Console::Lock(true);
				Console::Clear();

				Render();
				//Display objects here

				Console::Lock(false);
				Sleep(20);


			

			if (GetAsyncKeyState(VK_ESCAPE)) {
				for (size_t i = 0; i < objects.size(); i++)
				{
					delete objects[i];
				}
				
				play = false;
			}
		}
	}


	Game::~Game()
	{

		
	}

