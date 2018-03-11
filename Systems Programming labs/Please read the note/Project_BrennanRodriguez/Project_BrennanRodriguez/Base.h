#pragma once



	class Base
	{
	protected:
		int x;
		int y;
		char* symbol = nullptr;
		System::ConsoleColor color;

	public:
		Base();
		Base(int inX, int inY, char* inChar, System::ConsoleColor inColor);
		~Base();
		int GetX();
		void SetX(int inputX);
		int GetY();
		void SetY(int inputY);
		char GetSymbol();
		void SetSymbol(char* inputChar);
		System::ConsoleColor GetColor();
		void SetColor(System::ConsoleColor inColor);

		virtual void Update();
		virtual void Render();

	};



