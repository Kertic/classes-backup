#pragma once

#include "Base.h"


	class Game
	{
		int numObjects;
		bool play;
		int difficulty;
		int slowness;
		System::ConsoleColor shieldColor;
		int gameSpeedDelay;
		int score;
		int lives;
		string playerName;
		
		
		vector<Base*> objects;

	public:
		Game();
		void SpawnObs();
		void Update();
		void Render();
		void AddObject(Base* inBase);
		void start();
		void SetScore(int inScore);
		int GetScore();
		void SetLives(int inlives);
		int GetLives();
		void EndOfGame();
		void MainMenu();

		~Game();
	};


