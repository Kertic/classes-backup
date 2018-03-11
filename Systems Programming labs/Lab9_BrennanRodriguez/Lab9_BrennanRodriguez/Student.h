#pragma once
#include "Base.h"
class Student :
	public Base
{
	char* name = nullptr;
	char* degree = nullptr;
	float gpa;
	int rating;

public:
	Student() { name = nullptr; degree = nullptr; gpa = 0; rating = 0; }
	Student(char* inName, char* inDeg, float inGpa, int inRating);
	void DisplayRecord();

	Student(Student& input);  //Member 2
	Student& operator=(Student& input); //Member 3
	~Student() { delete[] name; delete[] degree; } //Member 1
};

