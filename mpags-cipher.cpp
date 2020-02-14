// mpags-cipher.cpp

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "TransformChar.hpp"
#include "RunCeasarCipher.hpp"

bool processCommandLine(
	const std::vector<std::string>& args,
	bool& helpRequested,
	bool& versionRequested,
	std::string& InputFileName,
	std::string& OutputFileName,
	std::string& Cipher,
	bool& encrypt,
	int& key)
{
	for (size_t i{0}; i < args.size() ; i++)
	{
		if ((args.at(i) == "-h")||(args.at(i) == "--help"))
		{
			std::cout << "Help Entry to come, please wait!" << std::endl;
			helpRequested = true;
			return false;	
		}
		if (args.at(i) == "--version")
		{
			std::cout << "Version 0.0.1"<< std::endl;
			versionRequested = true;
			return false;	
		}
		if ((args.at(i) == "-i")||(args.at(i) == "--input"))
		{
			if(i+1 >= args.size())
			{
				std::cout << "error: input file not supplied" << std::endl;
				return false;
			}
			InputFileName = args.at(i+1);
		}
		if ((args.at(i) == "-o")||(args.at(i) == "--output"))
		{
			if(i+1 >= args.size())
			{
				std::cout << "error: output file not supplied" << std::endl;
				return false;
			}
			OutputFileName = args.at(i+1);
		}
		if ((args.at(i) == "-c")||(args.at(i) == "--ceasar"))
		{
			if(i+1 >= args.size())
			{
				std::cout << "error: cipher not given" << std::endl;
				return false;
			}
			Cipher = args.at(i+1);
		}
		if ((args.at(i) == "-k")||(args.at(i) == "--key"))
		{
			if(i+1 >= args.size())
			{
				std::cout << "error: key not given" << std::endl;
				return false;
			}
			key = std::stoi(args.at(i+1));
		}
		if ((args.at(i) == "-d")||(args.at(i) == "decrypt"))
		{
			encrypt = false;
		}
		//std::cout << args.at(i) << std::endl;
	}
	return true;
}


int main(int argc, char* argv[])
{	
	// convert input to vector of strings
	const std::vector<std::string> cmdLineArgs{argv,argv+argc};

	bool helpRequested{false};
	bool versionRequested{false};
	std::string InputFileName{""};
	std::string OutputFileName{""};
	std::string Cipher{"Ceasar"};
	bool encrypt{true};//encrypt defaults to true, decrypt if false
	int key{0};

	processCommandLine(cmdLineArgs,helpRequested,versionRequested,InputFileName,OutputFileName,Cipher,encrypt,key);
	/* Take each letter from user input and in each case:
 * 	convert to Ucase
 * 	change numbers to words
 * 	ignore any other (non alphanumeric) characters
 * 	in each case, add result to string*/

	char in_char{'x'};
	std::string outstring{""};

	if( InputFileName == "")
	{
	//Loop until user presses Enter then ctrl+D
		while(std::cin >> in_char)
		{
			transformChar(outstring,in_char);
		}
	}
	else
	{
		std::ifstream in_file{InputFileName};
		if (in_file.good() == false)
		{
			std::cout << "Error: Input file not found." <<std::endl;
			return 0;
		}
		while(in_file >> in_char)
		{
			transformChar(outstring,in_char);
		
		}
	}
	
	if(OutputFileName == "")
	{
		std::cout << runCeasarCipher(outstring,key) << std::endl;
	}
	else
	{
		std::ofstream out_file{OutputFileName};
		if (out_file.good()==false)
		{
			std::cout << "Error: could not open output file." << std::endl;
			return 0;
		}
		out_file << runCeasarCipher(outstring,key)  << "\n";
	}
}


