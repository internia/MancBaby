#include <iostream>
#include <string>
#include <vector>
#ifndef ASSEMBLER_H
#define ASSEMBLER_H

using namespace std;

class Assembler{
	private:
	string fileName;
	string outputName;
	int lineNum;
	int lineTotal;
	
	
	vector<vector<string>> symbolTable;
	vector<vector<string>> convertedCode;
	
	public:
	//constructor/destructor
	Assembler();
	~Assembler();
	
	//getters and setters
	string getFileName();
	string getOutputName();
	string getSymbolValue(string symbol); //search in table
	
	void setFileName(string fileName);
	void setOutputName(string outputName);
	void setSymbol(string label, string address); //add to the table
	void setOutputVSize(int tableSize);
	
	//main methods
	void loadFile();
	void decodeLine();
	string convertOpCode();
	void save();
	
	string decToBin(int decimal);
};

#endif
