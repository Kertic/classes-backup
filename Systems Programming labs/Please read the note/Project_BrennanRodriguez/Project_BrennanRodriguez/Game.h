#pragma once

#include "Base.h"


	class Game
	{
		int numObjects;
		bool play;
		vector<Base*> objects;

	public:
		Game();
		void SpawnObs();
		void Update();
		void Render();
		void AddObject(Base* inBase);
		void start();
		~Game();
	};


