#pragma once
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
class BitOStream
{
	//string _path;
	//string _header;
	int _numB;
	ofstream outFile;
	char toWrite;

public:
	/////////////////////////////////////////////////////////////////////////////// Function : constructor
	// Parameters : 	filePath - the path of the file to open for output
	//			headerChunk - a chunk of data to be written at the 
	//					beginning of the file
	//			numberOfBytes - the number of bytes of header information 
	//					to write out
	/////////////////////////////////////////////////////////////////////////////
	BitOStream(const char* filePath, const char* headerChunk = NULL, int numberOfBytes = 0) {

		outFile.open(filePath, ios::binary);
		// = filePath;
		//_numB = numberOfBytes;
		if (headerChunk != NULL)
		{
			//_header = headerChunk;
			outFile.write((char *)headerChunk, numberOfBytes);
		}






		//for (unsigned int i = 0; i < 8; i++)//Sets toWrite to 0
		{
			//toWrite[i] = 0;
		}
		toWrite = 0;
		_numB = 128;

	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : destructor
	/////////////////////////////////////////////////////////////////////////////
	~BitOStream() {
		close();
		//aint nothin but a thang
	}






	/////////////////////////////////////////////////////////////////////////////
	// Function : insertion operator
	// Parameters : bits - a vector containing some number of 1's and 0's to 
	//						stream out to the file
	// Return : BitOStream& - the stream (allows for daisy-chaining insertions)
	////////////////////////////////////////////////////////////////////////////
	BitOStream& operator<<(vector<int> &bits) {
		for (size_t i = 0; i < bits.size(); i++)
		{
			
			//Or the toWrite bit wtih vector[i]
			if (bits[i] == 1)
			{
				toWrite |= _numB;
			}
		






			_numB /= 2;



			if (_numB == 0)//we have gotten to all the bits
			{
				outFile.write((char*)&toWrite, 1);
				toWrite = 0;
				_numB = 128;
			}
	
		}


		return *this;
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : close
	// Notes : closes the file stream - if remaining bits exist, they are written
	//			to the file with trailing 0's. if no remaining bits exist, 
	//			simply close the file
	/////////////////////////////////////////////////////////////////////////////
	void close() {
		/*bool found = false;

		for (unsigned int i = 0; i < 8; i++)//This checks if we have any variables that arent written yet
		{
			if (toWrite[i] != 0)
			{
				found = true;
			}
		}*/


		if ( _numB != 128) // if remaining bits exist
		{
			outFile.write((char*)&toWrite, 1);
		}

		outFile.close();
	}

};



class BitIStream {
	int _numB;
	ifstream inFile;
	char toRead;

public:

	/////////////////////////////////////////////////////////////////////////////
	// Function : constructor
	// Parameters : 	filePath - the path of the file to open for input
	//			headerChunk - a chunk of data to be read from the 
	//					beginning of the file
	//			numberOfBytes - the number of bytes of header information 
	//					to read in
	/////////////////////////////////////////////////////////////////////////////
	BitIStream(const char* filePath, char* headerChunk = NULL, int numberOfBytes = 0) {
		inFile.open(filePath, ios::binary);


		if (headerChunk != NULL)
		{
			inFile.read(headerChunk, numberOfBytes);
		}


		
		_numB = 128;
		inFile.read(&toRead, 1);

	
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : destructor
	/////////////////////////////////////////////////////////////////////////////
	~BitIStream() {
		close();
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : extraction operator
	// Parameters : bit - store the next bit here
	// Return : BitIStream& - the stream (allows for daisy-chaining extractions)
	/////////////////////////////////////////////////////////////////////////////
	BitIStream& operator >> (int &bit) {
		
		
		
		//if the piece we input's bit of the index of _numB is true
		if (toRead & _numB)
		{
			bit = 1;//set bit = 1
		}
		else//else
		{
			bit = 0;//bit = 0
		}
		
		
		

		_numB /= 2;
		if (_numB == 0)//we have gotten to all the bits
		{
			inFile.read(&toRead, 1);
			
			_numB = 128;
		}
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : eof
	// Return : true if we are at the end of the file, false otherwise
	// Notes : should only return true when we have given the user every byte
	//		from the file and every bit from the buffer
	/////////////////////////////////////////////////////////////////////////////
	bool eof() {

		if (inFile.eof())
		{
			if (_numB != 128)
			{
				return true;
			}
			
		}

		return false;
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : close
	// Notes : close the file
	/////////////////////////////////////////////////////////////////////////////
	void close() {
		inFile.close();

	}


};

