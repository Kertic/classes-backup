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
	//Score is now stored in the game object, because that makes more sense
	//if (inScore >= 0)
	//{
	//	score = inScore;
	//}
	//else
	//{
	//	score = 0;
	//}
	//
	//Console::SetCursorPosition(1, 1);
	//Console::ForegroundColor(Blue);
	//cout << "Score: " << score;
	//Console::ResetColor();
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
	
	
}

void Player::Update()
{
	//Console::WindowWidth()/2, Console::WindowHeight()/2,
	if (GetAsyncKeyState(VK_LEFT))
	{
		SetColor(Red);

	} else if (GetAsyncKeyState(VK_RIGHT))
	{
		SetColor(Blue);
	}else if (GetAsyncKeyState(VK_UP))
	{
		SetColor(Green);
	}
	else {

	}

	
}

void Player::Render()
{ 
	Base::Render();
	SetScore(score);
}

