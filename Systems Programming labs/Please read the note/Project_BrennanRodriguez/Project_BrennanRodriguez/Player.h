#pragma once
#include "Base.h"
class Player :
	public Base
{
protected:
	string name;
	int score;
public:
	Player();
	Player(int inX, int inY, char* inChar, System::ConsoleColor inColor, int inScore, string inString);
	void SetScore(int inScore);
	int GetScore();
	void SetName(string inName);
	string GetName();
	~Player();
	void Update();
	void Render();
};

