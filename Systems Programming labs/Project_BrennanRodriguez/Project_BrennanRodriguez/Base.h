#pragma once



	class Base
	{
	protected:
		int x;
		int y;
		bool toDie = false;
		char* symbol = nullptr;
		System::ConsoleColor color;

	public:
		Base();
		Base(int inX, int inY, char* inChar, System::ConsoleColor inColor);
		virtual ~Base();
		int GetX();
		void SetX(int inputX);
		int GetY();
		void SetY(int inputY);
		char GetSymbol();
		void SetSymbol(char* inputChar);
		System::ConsoleColor GetColor();
		void SetColor(System::ConsoleColor inColor);
		bool GetToDie();
		void SetToDie(bool istoDie);

		virtual void Update();
		virtual void Render();

	};



