// Lab9_BrennanRodriguez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Base.h"
#include <typeinfo>
Base* AddEntry();
Student* AddStudent();
Employee* AddEmployee();
void DisplayPeople(vector<Base*> inVec);
vector<Base*> ManageRecords(vector<Base*> inVec);


//TODO: ManageRecords()
using namespace std;
int main()
{
	vector<Base*> people;
	bool run = true;

	while (run)
	{
		Console::Lock(true);
		Console::Clear();
		cout << "Would you like to add a record, or view/modify existing records?";
		cout << "\n1. Add a record\n2. View/Modify\nEsc. Exit the program";
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			run = false;
		} else if (GetAsyncKeyState(0x31) & 0x8000)
		{

			people.push_back(AddEntry());


		}
		else if (GetAsyncKeyState(0x32) & 0x8000)
		{
			Console::Lock(false);
			Console::Clear();

			DisplayPeople(people);
			cout << "\n";
			system("pause");
			people = ManageRecords(people);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		}


		Console::Lock(false);
		Sleep(10);

	}
    return 0;
}

//While loop for input
	//while (true)
	//{
	//	Console::Lock(true);
	//	Console::Clear();
	//
	//
	//	Console::Lock(false);
	//	Sleep(10);
	//
	//}

Base* AddEntry()
{

	while (true)
	{
		
		Console::Lock(true);
		Console::Clear();
		cout << "Would you like to add an Employee or a Student?";
		cout << "\n3. Student\n4. Employee";
		if (GetAsyncKeyState(0x33) & 0x8000)
		{
			Console::Lock(false);

			Base* temp = AddStudent();
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			return temp;
			break;

		} else if (GetAsyncKeyState(0x34) & 0x8000)
		{
			Console::Lock(false);

			Base* temp = AddEmployee();
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			return temp;
			break;
		}

	
	
		Console::Lock(false);
		Sleep(10);
	
	}


	}

Student * AddStudent()
{
	Console::Clear();
	cout << "What is the student's name?: ";

	char* inName = new char[64];
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	cin.getline(inName, 32, '\n');


	cout << "\nWhat is their Degree?: ";
	char* inDeg = new char[64];
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	cin.getline(inDeg, 32, '\n');


	float inGpa;
	while (true)
	{
		cout << "\nWhat was their final GPA?: ";
		if (cin >> inGpa)
		{
			cout << "\n";
			break;
		}
		else
		{
			cout << "\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

	}

	int inRate;
	while (true)
	{
		cout << "\nHow likeable were they, on a scale of 1-10 (whole numbers only): ";
		if (cin >> inRate)
		{
			cout << "\n";
			break;
		}
		else
		{
			cout << "\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

	}

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	Student* temp = new Student(inName, inDeg, inGpa, inRate);
	return temp;
}

Employee * AddEmployee()
{
	Console::Clear();
	cout << "What is the employee's name?: ";

	char* inName = new char[64];
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	cin.getline(inName, 32, '\n');
	

	cout << "\nWhat is their Department?: ";
	char* inDeg = new char[64];
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	cin.getline(inDeg, 32, '\n');



	int inSal;
	while (true)
	{
		cout << "\nWhat is their Salary?: ";
		if (cin >> inSal)
		{
			cout << "\n";
			break;
		}
		else
		{
			cout << "\n";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	Employee* temp = new Employee(inName, inDeg, inSal);
	return temp;
}



void DisplayPeople(vector<Base*> inVec)
{
	cout << "Displaying People: ";
	for (int i = 0; i < inVec.size(); i++)
	{
		cout << "\nItem #" << i;
		inVec[i]->DisplayRecord();
	}
}

vector<Base*> ManageRecords(vector<Base*> inVec)
{
	
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	int index1;
	while (true)
	{
		Console::Lock(true);
		Console::Clear();
		cout << "Displaying People: ";
		DisplayPeople(inVec);
		cout << "\nWhich item would you like to copy from? (-1 to cancel)\n";
		Console::Lock(false);
		if (cin >> index1)
		{
			int upbound = (inVec.size() - 1);
			if (index1 == -1)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				return inVec;
			}
			if (index1 >= 0 && index1 <= upbound)
			{
				break;
			}
			else
			{
				cout << "\nPlease enter a valid index\n";
				system("pause");
			}
		}
	
		Console::Lock(false);
		Sleep(10);
	
	}


	int index2;
	while (true)
	{
		Console::Lock(true);
		Console::Clear();
		Console::Lock(false);
		cout << "Displaying People: ";
		DisplayPeople(inVec);
		cout << "\nWhich item would you like to copy onto? (-1 to cancel) \n";
		if (cin >> index2)
		{
			int upbound = (inVec.size() - 1);
			if (index2 == -1)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				return inVec;
			}
			if (index2 >= 0 && index2 <= upbound)
			{
				break;
			}
			else
			{
				cout << "\nPlease enter a valid index\n";
				system("pause");
			}
		}

		Console::Lock(false);
		Sleep(10);

	}
	Base* tempVar1 = inVec[index1];
	Base* tempVar2 = inVec[index2];

	if ((dynamic_cast<Employee*> (tempVar1) && dynamic_cast<Employee*> (tempVar2)) || (dynamic_cast<Student*> (tempVar1) && dynamic_cast<Student*> (tempVar2)))
	{
		inVec[index2] = static_cast<Base*> (inVec[index1]);
		
	}
	return inVec;
	//dynamic_cast<> 
}
