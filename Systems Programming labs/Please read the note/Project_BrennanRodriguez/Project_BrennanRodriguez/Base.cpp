#include "stdafx.h"
#include "Base.h"



	Base::Base()
	{
		SetX(10);
		SetY(10);
		SetSymbol("X");
		SetColor(ConsoleColor::Red);

	}

	Base::Base(int inX, int inY, char * inChar, System::ConsoleColor inColor)
	{
		SetX(inX);
		SetY(inY);
		SetSymbol(inChar);
		SetColor(inColor);
	}


	Base::~Base()
	{
		delete[] symbol;
	}

	int Base::GetX()
	{
		return x;
	}

	void Base::SetX(int inputX)
	{
		if (inputX >= 0 && inputX <= Console::WindowWidth())
			x = inputX;

	}

	int Base::GetY()
	{
		return y;
	}

	void Base::SetY(int inputY)
	{
		
		if (inputY >= 0 && inputY <= Console::WindowHeight())
			y = inputY;
	}

	char  Base::GetSymbol()
	{
		return *symbol;
	}

	void Base::SetSymbol(char* inputChar)
	{
		delete[] symbol;
		
		symbol = _strdup(inputChar);
	}

	ConsoleColor Base::GetColor()
	{
		return color;

	}

	void Base::SetColor(ConsoleColor inColor)
	{
		color = inColor;
	}

    void Base::Update()
	{



	}

	 void  Base::Render()
	{
		Console::SetCursorPosition(x, y);
		Console::ForegroundColor(color);
		cout << *symbol;
		Console::ResetColor();
	}

