#include <iostream>
#include <fstream>
#include <string>
#include <csting>
#include <vector>
#include <stdio.h>
#include <fstream>	
#include <stdlib.h>
#include "Assembler.h"

using namespace std;

int main() {
	
	cout << "Manchester Baby Assembler" << endl;
	
	//create new assembler
	Assembler* ass = new Assembler();
	
	string rFileName; //read file name (assembler code file name)
	
	cout << "Please input the name of the file you want to convert from " << endl;
	cout << "assembily code to machine code: ";
	cout << "" << endl;
	
	getline(cin, rFileName);
		
	string sFileName; //save file name (machine code output file name)
	
	cout << "Enter the name you want to give to the output machine code file :";
	cout << "" << endl;
	
	getline(cin, sFileName);
	
	ass->loadFile();
	
	delete ass;
	
}

Assembler::Assembler(string fileName, string outputName){
	
	this->fileName = fileName;
	this->outputName = outputName;
}

//Deconstructor
Assembler::~Assembler(){
	
	fileName.clear();
	lineNum = 0;
	lineTotal = 0;
	
	
}

void Assembler::setOutputVSize(int size){
	
	this->convertedCode.resize(size, vector<string>(32, 0));
	
}

void Assembler::loadFile(){
	
	//input stream class to operate on files	
	ifstream file;
	string line;
	
	//read in file
	file.open("MachineCode.txt");
	
	//while not at end of file, continue reading
	while(!file.eof()){
		
		//extracts characters from stream and stores in c string, 'line' defines the maximum num of characters to write to 'input'
		getline(input, line);
		
		//store countLine as line
		store.at(countLine) = line;
		
		//postfix increment
		countLine++;
		
	}
	
	//store the first line of the file to be decoded here
	
	writeToOutput(decodeLine(line))
}

string Assembler::decodeLine(int lineNum, string line){
	
	char line1 = 0;
	
	//remove all white space
	
	for(string::iterator it = str.begin(); it != str.end(); ++it) {
		if(*it != ';'){ //if not a comment
			
			//remove all white space
			line.erase(remove(line.begin(),line.end(),' '),line.end());

			for(int i; i < line.length(); i++){
				char curr = line[i];
				if(curr == ':'){
					string temp;
			
		}else{ //if you have reached a comment, ignore the rest on that line
			break;
		}
	}
	

}
	
string Assembler::convertOpCode(string opCode){
	
	//instruction set
	if (opCode == "JMP"){
		return "000";
	}
	if (opCode == "JRP"){
		return "100";
	}
	if (opCode == "LDN"){
		return "010";
	}
	if (opCode == "STO"){
		return "110";
	}
	if (opCode == "SUB"){
		return "001";
	}
	if (opCode == "CMP"){
		return "011";
	}
	if (opCode == "STP"){
		return "111";
	}else{
	
	return "label"; //returns label if not in instruction set
		
	}
}



int Assembler::decToBin(int n){
for(i=0; n>0; i++){    
	a[i]=n%2;    
	n= n/2;  
}  
return n;
}

//hex to binary method from https://stackoverflow.com/questions/18310952/convert-strings-between-hex-format-and-binary-format
String Assembler::hexToBin(const string& hex){

    string bin;
    for(unsigned i = 0; i != hex.length(); ++i)
       bin += hex_char_to_bin(hex[i]);
    return bin;

}
const char* Assembler::hex_char_to_bin(char c){
 
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

