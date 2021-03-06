// mpags-cipher.cpp

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"
#include "PlayfairCipher.hpp"

int main(int argc, char* argv[])
{	
	// convert input to vector of strings
	const std::vector<std::string> cmdLineArgs{argv,argv+argc};
	
	// create arguments object with default args, will be populated by passing to processCommandLine
	cmdLine Args {false,false,"","","",CipherMode::encrypt,CipherType::Caesar};

	if (processCommandLine(cmdLineArgs,Args)==false)
	{
		//error caught by processcommand line function
		return 0;
	}
	
	/* Take each letter from user input and in each case:
 * 	convert to Ucase
 * 	change numbers to words
 * 	ignore any other (non alphanumeric) characters
 * 	in each case, add result to string*/

	char in_char{'x'};
	std::string instring{""};
	
	if( Args.inputFile == "")
	{
	//Loop until user presses Enter then ctrl+D
		std::cout << "Ready, enter input text and press Enter then ctrl+d" << std::endl;
		while(std::cin >> in_char)
		{
			transformChar(instring,in_char);
		}
	}
	else
	{
		std::ifstream in_file{Args.inputFile};
		if (in_file.good() == false)
		{
			std::cout << "Error: Input file not found." <<std::endl;
			return 0;
		}
		while(in_file >> in_char)
		{
			transformChar(instring,in_char);
		
		}
	}
	std::string outstring = "";	
	switch(Args.cipherType)
	{
		case CipherType::Caesar:
		{
			try{std::stoi(Args.key);}catch(...){std::cerr<<"[error] Caesar cipher key must be an integer"<<std::endl; return 0;}
			CaesarCipher cipher{Args.key};
			outstring = cipher.applyCipher(instring,Args.cMode);
			break;
		}
		case CipherType::Playfair:
		{
			PlayfairCipher cipher{Args.key};
			outstring = cipher.applyCipher(instring,Args.cMode);
			break;
		}
	}
	
	
	if(Args.outputFile == "")
	{
		std::cout << outstring <<std::endl;
	}
	else
	{
		std::ofstream out_file{Args.outputFile};
		if (out_file.good()==false)
		{
			std::cout << "Error: could not open output file." << std::endl;
			return 0;
		}
		out_file << outstring << "\n";
	}
}


