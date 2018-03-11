#include "stdafx.h"
#include "Player.h"


Player::Player() : Base()
{
	name = "Default";
	SetScore(0);
}

Player::Player(int inX, int inY, char * inChar, System::ConsoleColor inColor, int inScore, string inString) : Base(inX, inY, inChar, inColor)
{
	SetScore(inScore);
	SetName(inString);
}

void Player::SetScore(int inScore)
{
	if (inScore >= 0)
	{
		score = inScore;
	}
	else
	{
		score = 0;
	}

	Console::SetCursorPosition(1, 1);
	Console::ForegroundColor(Blue);
	cout << "Score: " << score;
	Console::ResetColor();
}

int Player::GetScore()
{
	return score;
}

void Player::SetName(string inName)
{

	
		name = inName;
	

}

string Player::GetName()
{
	return name;
}


Player::~Player() 
{
	delete[] symbol;
	
}

void Player::Update()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		SetX(x - 1);

	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		SetX(x + 1);
	}
	if (GetAsyncKeyState(VK_UP))
	{
		SetY(y - 1);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		SetY(y + 1);
	}

	
}

void Player::Render()
{ 
	Base::Render();
	SetScore(score);
}

