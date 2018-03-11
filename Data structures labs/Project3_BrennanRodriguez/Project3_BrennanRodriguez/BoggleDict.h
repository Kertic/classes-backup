#pragma once
#include "HTable.h"
#include <iostream>
#include <fstream>
#include "Graph.h"
#include <time.h>
using namespace std;

template <typename Type>
class BoggleDict
{

	unsigned int(*_hashTemp)(const Type &v);//A blank function pointer for default constructors
	HTable<string> *_htable;
	Graph<char> characterGrid;

	unsigned int score;
public:
	BoggleDict() {
		_htable = new HTable<string>(100, _hashTemp);
		score = 0;
	}
	~BoggleDict() {
		delete _htable;
	}
	BoggleDict(int numBuckets, unsigned int(*inFunc) (const Type &_input)) {
		_htable = new HTable<string>(numBuckets, inFunc);
		score = 0;

		PopulateGrid(true);

		
	}

	void Populate() {
		ifstream inFile;
		inFile.open("engldict.txt");
		while (!inFile.eof()) {
			string input;
			getline(inFile, input);
			if (input.find('\'') == std::string::npos)//If we don't find an apostrophe
			{
				if (input.length() >= 4)//If the string is greater or equal to 4
				{
					_htable->insert(input);

				}
			}

		}

	}

	unsigned int GetScore() {

		return score;
	}

	void SetScore(unsigned int inScore) {

		if (inScore >= 0)
		{
			score = inScore;

		}
	}

	bool searchForString(string inString) {//Find the string in the hash table
		int test = _htable->find(inString);
		if (test >= 0)//If we found it
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	void PopulateGrid(bool IsPreGen) {

		for (unsigned int i = 0; i < 16; i++)
		{
			characterGrid.addVertex('0');//Appened the character '0' 16 times, thus making characterGrid a 4x4 grid of 0's
		}




		if (IsPreGen == true)//If we want to use the pre-genned grid
		{
			characterGrid[0] = 'A';
			characterGrid[1] = 'I';
			characterGrid[2] = 'E';
			characterGrid[3] = 'W';
			characterGrid[4] = 'R';
			characterGrid[5] = 'T';
			characterGrid[6] = 'N';
			characterGrid[7] = 'P';
			characterGrid[8] = 'L';
			characterGrid[9] = 'O';
			characterGrid[10] = 'S';
			characterGrid[11] = 'K';
			characterGrid[12] = 'W';
			characterGrid[13] = 'S';
			characterGrid[14] = 'T';
			characterGrid[15] = 'J';
		}
		else
		{
			unsigned int totalVowels = 0;
			unsigned int passes = 0;
			while (totalVowels < 4)
			{
				totalVowels = 0;
				srand(time(NULL));
				system("cls");
				++passes;
				cout << "\nGenerating grid: pass # " << passes;
				for (unsigned int i = 0; i < characterGrid.size(); i++)
				{

					characterGrid[i] = (char)((rand() % 26) + 65);//Generate a random character
					if (characterGrid[i].element == 65 || characterGrid[i].element == 69 || characterGrid[i].element == 73 || characterGrid[i].element == 79 || characterGrid[i].element == 85)
					{
						++totalVowels;
					}//Check if we have enough vowels

				}


			}

		}

		//This if statement is just to be able to shrink down the verticies being added
		if (true)
		{
			characterGrid[0].addEdge(1);
			characterGrid[0].addEdge(4);
			characterGrid[0].addEdge(5);//A1 - (A2, B1, B2)
			characterGrid[1].addEdge(0);
			characterGrid[1].addEdge(4);
			characterGrid[1].addEdge(5);
			characterGrid[1].addEdge(6);
			characterGrid[1].addEdge(2);//A2 - (A1, B1, B2, B3, A3)
			characterGrid[2].addEdge(1);
			characterGrid[2].addEdge(5);
			characterGrid[2].addEdge(6);
			characterGrid[2].addEdge(7);
			characterGrid[2].addEdge(3);//A3 - (A2, B2, B3, B4, A4)
			characterGrid[3].addEdge(2);
			characterGrid[3].addEdge(6);
			characterGrid[3].addEdge(7);//A4 - (A3, B3, B4)
										//
			characterGrid[4].addEdge(0);
			characterGrid[4].addEdge(1);
			characterGrid[4].addEdge(5);
			characterGrid[4].addEdge(9);
			characterGrid[4].addEdge(8);//B1 - (A1, A2, B2, C2, C1)
			characterGrid[5].addEdge(0);
			characterGrid[5].addEdge(1);
			characterGrid[5].addEdge(2);
			characterGrid[5].addEdge(6);
			characterGrid[5].addEdge(10);
			characterGrid[5].addEdge(9);
			characterGrid[5].addEdge(8);
			characterGrid[5].addEdge(4);//B2 - (A1, A2, A3, B3, C3, C2, C1, B1)
			characterGrid[6].addEdge(1);
			characterGrid[6].addEdge(5);
			characterGrid[6].addEdge(9);
			characterGrid[6].addEdge(10);
			characterGrid[6].addEdge(11);
			characterGrid[6].addEdge(7);
			characterGrid[6].addEdge(3);
			characterGrid[6].addEdge(2);//B3 - (A2, B2, C2, C3, C4, B4, A4, A3)
			characterGrid[7].addEdge(3);
			characterGrid[7].addEdge(2);
			characterGrid[7].addEdge(6);
			characterGrid[7].addEdge(10);
			characterGrid[7].addEdge(11);//B4 - (A4, A3, B3, C3, C4)
										 //
			characterGrid[8].addEdge(4);
			characterGrid[8].addEdge(5);
			characterGrid[8].addEdge(9);
			characterGrid[8].addEdge(13);
			characterGrid[8].addEdge(12);//C1 - (B1, B2, C2, D2, D1)
			characterGrid[9].addEdge(4);
			characterGrid[9].addEdge(5);
			characterGrid[9].addEdge(6);
			characterGrid[9].addEdge(10);
			characterGrid[9].addEdge(14);
			characterGrid[9].addEdge(13);
			characterGrid[9].addEdge(12);
			characterGrid[9].addEdge(8);//C2 - (B1, B2, B3, C3, D3, D2, D1, C1)
			characterGrid[10].addEdge(5);
			characterGrid[10].addEdge(6);
			characterGrid[10].addEdge(7);
			characterGrid[10].addEdge(11);
			characterGrid[10].addEdge(15);
			characterGrid[10].addEdge(14);
			characterGrid[10].addEdge(13);
			characterGrid[10].addEdge(9);//C3 - (B2, B3, B4, C4, D4, D3, D2, C2)
			characterGrid[11].addEdge(7);
			characterGrid[11].addEdge(6);
			characterGrid[11].addEdge(10);
			characterGrid[11].addEdge(14);
			characterGrid[11].addEdge(15);//C4 - (B4, B3, C3, D3, D4)
										  //
			characterGrid[12].addEdge(8);
			characterGrid[12].addEdge(9);
			characterGrid[12].addEdge(13);//D1 - (C1, C2, D2)
			characterGrid[13].addEdge(12);
			characterGrid[13].addEdge(8);
			characterGrid[13].addEdge(9);
			characterGrid[13].addEdge(10);
			characterGrid[13].addEdge(14);//D2 - (D1, C1, C2, C3, D3)
			characterGrid[14].addEdge(13);
			characterGrid[14].addEdge(9);
			characterGrid[14].addEdge(10);
			characterGrid[14].addEdge(11);
			characterGrid[14].addEdge(15);//D3 - (D2, C2, C3, C4, D4)
			characterGrid[15].addEdge(14);
			characterGrid[15].addEdge(10);
			characterGrid[15].addEdge(11);//D4 - (D3, C3, C4)
										  //Grid spaces and their edges
		}


	}

	void PrintGrid() {
		for (unsigned int y = 0; y < 4; y++)
		{
			for (unsigned int x = 0; x < 16; x += 4)
			{
				cout << "[" << characterGrid[x + y].element << "]";
			}
			cout << "\n";
		}
	}

	unsigned int BucketCount(unsigned int(*funcToTest) (const Type &_input)) {
		SLList<unsigned int> temp;

		ifstream inFile;
		inFile.open("engldict.txt");
		ofstream outFile("report.txt");
		while (!inFile.eof())
		{

			SLLIter<unsigned int> iter(temp);
			bool found = false;
			string input;

			unsigned int hashID = 0;
			getline(inFile, input);//Get the line
			hashID = funcToTest(input);//Hash it out
			cout << "\nWord is: " << input << "  Hash ID is : " << hashID;
			outFile << "\nWord is: " << input << "  Hash ID is : " << hashID;
			while (!iter.end())//Loop through all the items in temp
			{

				if (iter.current() == hashID)//If we find an int with the same value as the hash returns, mark found as true and break out
				{
					found = true;
					break;
				}
				++iter;
			}

			if (found == false)
			{
				temp.addHead(hashID);//Add the unique ID to the head.
			}


		}
		outFile << "\nTotal buckets with at least one item: " << temp.size();
		return temp.size();

	}

	void InfoFile() {
		_htable->printSomeStuff();
	}

	bool checkIfStringCanBeMade(string input) {//Returns true if the string can be made, or false otherwise
		for (unsigned int i = 0; i < characterGrid.size(); i++)
		{
			if (tolower(characterGrid[i].element) == tolower(input[0]))
			{
				DynArray<unsigned int> path;
				if (recursiveEdgeWalk2(path, input, i))
				{
					return true;
				}
			}
		}


		
		return false;
	}

	//returns true if there is a valid path to make "input" from the starting index of the grid
	bool recursiveEdgeWalk(DynArray<unsigned int> path, string input, unsigned int startIndex) {
		bool temp = false;
		if (characterGrid[startIndex].edges.size() == 0)
		{
			return false;//There is no possible path out of here, so we dont make an iteratior and instead just break
		}

		DynArray<unsigned int> tempPath = path;
		for (unsigned int i = 0; i < tempPath.size(); i++)
		{
			char test1 = tolower(input[i]);
			char test2 = tolower(characterGrid[tempPath[i]].element);

			if (tolower(input[i]) != tolower(characterGrid[tempPath[i]].element))//If the current path doesnt match up to input
			{
				return false;//We know that there isnt a match already so just break
			}
		}

		tempPath.append(startIndex);
		SLLIter<Graph<char>::Edge> iter(characterGrid[startIndex].edges);//Make an iterator for the edge list at the index we last appended 
		if (tempPath.size() != input.size())
		{
			bool hasBeenThere = false;
			for (unsigned int i = 0; i < tempPath.size(); i++)
			{
				if (iter.iter->data.toVertex == tempPath[i])
				{
				++iter;
				}//if we're on a vertex we've visited before
				//and iter's next isnt a null ptr
				//++iter;
			}
			if (iter.iter->next != nullptr && iter.iter != nullptr)//The non-end case where you go back through
			{

				++iter;
				while (iter.iter->next != nullptr)
				{
					if (recursiveEdgeWalk(tempPath, input, iter.current().toVertex))
						return true;

					++iter;
				}

			}
			else//The end case where the path ends short
			{
				return false;
			}
		}
		else//They are the same size
		{
			bool areEqual = true;
				for (unsigned int i = 0; i < tempPath.size(); i++)
				{
					if (tolower(characterGrid[tempPath[i]].element) != tolower(input[i]))
						areEqual = false;
				}


			if (areEqual)//end case where they are the same
			{
				return true;
			}
			else//end case where they are the same size, but not the same string
			{
				return false;
			}
		}
		return false;
	}


	bool recursiveEdgeWalk2(DynArray<unsigned int> indexHistory, string input, unsigned int inIndex) {

		DynArray<unsigned int> tempHistory = indexHistory;
		tempHistory.append(inIndex);
		if (tempHistory.size() == input.size())//Checks if equal, coveres non same strings and identical strings
		{
			
			for (unsigned int i = 0; i < tempHistory.size(); i++)//If we have a character that doesn't match
			{
				if (tolower(characterGrid[tempHistory[i]].element) != tolower(input[i]))
					return false;
			}
			return true;
		}

		//At this point, we know its not equal. So we're going to call the recursive function for each path we may have.
		bool temp = false;
		SLLIter<Graph<char>::Edge> eIter(characterGrid[inIndex].edges);//Set the iterator to the edge of the current index
		for (unsigned int i = 0; i < characterGrid[inIndex].edges.size(); i++)//This will iterate through all the edges of the current index we're on
		{
			bool hasVertexBeenUsed = false;
			for (unsigned int j = 0; j < tempHistory.size(); j++)//This will do a check for each item in temp
			{
				if (tempHistory[i] == eIter.current().toVertex)//if tempHistory[i] == the current edge's toVertex
					hasVertexBeenUsed = true;
			}
			if (hasVertexBeenUsed)
			{
				//Do nothing
			}
			else
			{
				if (recursiveEdgeWalk2(tempHistory, input, eIter.current().toVertex))
				{
					temp = true;
				}
			}

		}


		return temp;
		

	}

};

/*

End conditions:
The string is the same length and is equal 

the string is the same length but does not equal

the string is a different length and has already used all the indicies that the current character has edges to





We add the current index to the history because we need to increase length and then check.


If we are at the same length and equal, return true

if we are at the same length and not equal, return false. No need to continue.


If we're at a lower length, 
	set a temporary variable to false;
	for each edge of the letter we're on
			if the history has this vertex inside of it, skip it;
			else
			if recursive function returns true, 
			set our temp variable to true



*/