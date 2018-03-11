#pragma once
#include "HuffmanDef.h"
class HuffmanUtils
{
public:
	/////////////////////////////////////////////////////////////////////////////
	// Function : generateFrequencyTable
	// Parameters : filePath - the path to the file to open
	// Return : unsigned int* - a dynamically allocated frequency table 
	// Notes : [256] contains the total count of characters in the file
	/////////////////////////////////////////////////////////////////////////////
	unsigned int* generateFrequencyTable(const char* filePath) {

	}
		/////////////////////////////////////////////////////////////////////////////
		// Function : generateLeafList
		// Parameters : freqTable - the frequency table to be used to generate leaf 
		//			nodes
		// Return : vector<HuffNode*> - a vector containing the leaf nodes
		/////////////////////////////////////////////////////////////////////////////
	vector<HuffNode*> generateLeafList(unsigned int* freqTable) {

		}
		/////////////////////////////////////////////////////////////////////////////
		// Function : generateHuffmanTree
		// Parameters : leafList - the leaf nodes that will appear in our huffman 
		//			tree
		// Return : HuffNode* - the root of the generated tree
		/////////////////////////////////////////////////////////////////////////////
	HuffNode* generateHuffmanTree(vector<HuffNode*>& leafList) {

		}
		/////////////////////////////////////////////////////////////////////////////
		// Function : generateEncodingTable
		// Parameters : leafList - a vector containing all the leaves in the tree
		// Return : vector<int>* - a dynamically-allocated array of 256 vectors
		// Notes : each index in the encoding table corresponds to an index in the 
		//			frequency table
		/////////////////////////////////////////////////////////////////////////////
	vector<int>* generateEncodingTable(vector<HuffNode*>& leafList) {

		}
		/////////////////////////////////////////////////////////////////////////////
		// Function : writeHuffmanFile
		// Parameters : 	inputFilePath - the path of the file to open for input
		//			outputFilePath - the path of the file to open for output
		//			freqTable - the frequency table
		//			encodingTable - the encoding table
		// Notes : open the input file, read characters one at a time, while 
		//		streaming bitcodes to the output file
		/////////////////////////////////////////////////////////////////////////////
	void writeHuffmanFile(const char* inputFilePath, const char* outputFilePath,
		unsigned int* freqTable, vector<int>* encodingTable) {

		}
		/////////////////////////////////////////////////////////////////////////////
		// Function : cleanup
		// Notes : clean up any dynamic memory allocated by other functions
		/////////////////////////////////////////////////////////////////////////////
	void cleanup(unsigned int* freqTable, HuffNode* huffTree, vector<int>* encodingTable) {

		}

		/////////////////////////////////////////////////////////////////////////////
		// Function : decodeHuffmanFile
		// Parameters :	inputFilePath - the file to open and decode
		//			outputFilePath - the decoded mesasge, written to a file
		/////////////////////////////////////////////////////////////////////////////
	void decodeHuffmanFile(const char* inputFilePath, const char* outputFilePath) {

		}

};

