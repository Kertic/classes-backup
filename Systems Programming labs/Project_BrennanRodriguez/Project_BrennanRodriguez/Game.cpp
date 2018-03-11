#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Obstacle.h"
#include <ctime>
#include <sstream>

	Game::Game()
	{


		




	}

	void Game::SpawnObs()//Spawns the obstacles
	{
		//Spawn an obstacle with a random color, and a switch statement based on the random direction. This will be placed
		//In the GameLoop part of the game, because it already is delaying on a consistent tick.
		int randIntColor = rand() % 3;
		System::ConsoleColor randColor;

		switch (randIntColor)
		{
		case 0:
			randColor = System::ConsoleColor::Red;
			break;
		case 1:
			randColor = System::ConsoleColor::Green;
			break;
		case 2:
			randColor = System::ConsoleColor::Blue;
			break;
		default:
			break;
		}


		//Spawn the objects with a random direction
		int randDir = (rand() % (difficulty ));
		switch (randDir)
		{
		case 0:
			AddObject(new Obstacle(Console::WindowWidth() / 2, 0, "O", randColor, 0));
			break;
		case 1:
			AddObject(new Obstacle(Console::WindowWidth(), Console::WindowHeight() / 2, "O", randColor, 1));
			break;
		case 2:
			AddObject(new Obstacle(Console::WindowWidth() / 2, Console::WindowHeight(), "O", randColor, 2));
			break;
		case 3: 
			AddObject(new Obstacle(0, Console::WindowHeight() / 2, "O", randColor, 3));
			break;
		default:
			break;
		}

	}

	void Game::Update()
	{
		for (size_t i = 0; i < objects.size(); i++)
		{
			objects[i]->Update();
			//If the object is intersecting with the box, and its color is the same as the box, mark it toDie and add 10 to the score
			int x = objects[i]->GetX();
			int y = objects[i]->GetY();
			if (x == Console::WindowWidth() / 2 - 5 || x == Console::WindowWidth() / 2 + 5 || y == Console::WindowWidth() / 2 - 5 || y == Console::WindowWidth() / 2 + 5)//If the objects x OR y is on either side of the shield
			{
				if (objects[i]->GetColor() == shieldColor)//If the objects are the same color as the shield
				{
					objects[i]->SetToDie(true);
					score += 10;
					//
				}
				else//if its not the same color
				{
					objects[i]->SetToDie(true);
					SetLives(GetLives() - 1);
					//Play hurt sound here
				}
			}
			if (objects[i]->GetToDie() == true)
			{
				objects.erase(objects.begin() + i);
				i--;
				numObjects--;
				
			}
		}
		if (lives <= 0)
		{
			play = false;
		}

	}

	void Game::Render()
	{
		
		shieldColor = objects[0]->GetColor();
		Console::ForegroundColor(shieldColor);
		Console::DrawBox(Console::WindowWidth() / 2 - 5, Console::WindowWidth() / 2 - 5,  10,  10, true);
		Console::ResetColor();
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

	void Game::start()//The main game loop
	{


		//We put innitialization code in the loop, so every time start is called, it essentially restarts everything
		SetScore(0);
		SetLives(3);
		numObjects = 0;
		play = true;
		gameSpeedDelay = 100;//This is the amount of time between each tic
		difficulty = 1;//Difficulty has a min of 1 and a max of 4, difficulty corresponds to the different possible directions
		slowness = 7;//this is the delay in tics between spawns
		shieldColor = White;
		playerName = "";



		AddObject(new Player(Console::WindowWidth() / 2, Console::WindowHeight() / 2, "P", White, 0, "Player"));
		numObjects--;
		//End of of constructors


		int runCounter = 0;
		int spawnDelay = 0;
		int delayTicks = slowness;
		srand((int)time(0));
		MainMenu();
		play = true;
		while (play) {

			
			if (spawnDelay == 0)
			{
				SpawnObs();
				spawnDelay++;
				spawnDelay = spawnDelay % delayTicks;
			}
			else
			{
				spawnDelay++;
				spawnDelay = spawnDelay % delayTicks;
			}
			    
				Update();

				Console::Lock(true);
				Console::Clear();
				Render();
				SetScore(score);
				SetLives(lives);
				//Display objects here
				Console::Lock(false);
				Sleep(gameSpeedDelay);


			

			if (GetAsyncKeyState(VK_ESCAPE)) {//For quitting out using ESC
				for (size_t i = 0; i < objects.size(); i++)
				{
					delete objects[i];
				}
				
				play = false;
			}

			//increase the speed by 1ms every 20 ticks
			runCounter++;
			if (runCounter % 20 == 0)
			{
				gameSpeedDelay--;
				
				
			}
		}
		EndOfGame();
	}

	void Game::SetScore(int inScore)
	{
		if (inScore >= 0)
		{
			score = inScore;
		}
		else
		{
			score = 0;
		}

		Console::SetCursorPosition(0, 0);
		Console::ForegroundColor(Cyan);
		cout << "Score: " << score;
		Console::ResetColor();
	}

	int Game::GetScore()
	{
		return score;
	}

	void Game::SetLives(int inlives)
	{
		if (inlives >= 0)
		{
			lives = inlives;
		}
		else
		{
			lives = 0;
		}

		Console::SetCursorPosition(0, 1);
		Console::ForegroundColor(Cyan);
		cout << "Lives: " << lives;
		Console::ResetColor();
	}

	int Game::GetLives()
	{
		return lives;
	}

	void Game::EndOfGame()
	{
		Console::SetWindowSize(60, 30);
		Console::Clear();
		Console::SetCursorPosition(Console::WindowWidth() / 2 - 15, Console::WindowHeight() / 2);
		cout << "Your score was: " << score;
		Console::SetCursorPosition(Console::WindowWidth() / 2 - 15, Console::WindowHeight() / 2 + 1);
		cout << "Would you like to play again? \nPress 1 for yes,\nand 2 for no.";
		while (true)
		{
			if (GetAsyncKeyState(0x31))
			{
				objects.clear();
				start();
				break;
			}
			else if (GetAsyncKeyState(0x32))
			{
				break;
			}
		}


	}

	void Game::MainMenu()
	{
		Console::Clear();
		cout << "Welcome to Chroma. Enemies will come \nat you,\nand you must change the colors of your \nshield to match their color.\n";
		cout << "\nPress Up for green,\nLeft for red,\nand Right for blue.\n";
		cout << "\nFor your difficulty, press 1 for easy, \n2 for hard, 3 for hard, \nand 4 for insane";
		Console::WordWrap(Console::WindowWidth() / 2  - 30, Console::WindowHeight() / 2, 30, "");
		bool keepgoing = true;
		while (keepgoing) {
			if (GetAsyncKeyState(0x31))
			{
				difficulty = 1;
				keepgoing = false;
			}
			else if (GetAsyncKeyState(0x32))
			{
				difficulty = 2;
				keepgoing = false;
			}
			else if (GetAsyncKeyState(0x33))
			{
				difficulty = 3;
				keepgoing = false;
			}
			else if (GetAsyncKeyState(0x34))
			{
				difficulty = 4;
				keepgoing = false;
			}
			else
			{

			}
		}
	}


	Game::~Game()
	{

		
	}

