// mpags-cipher.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "TransformChar.hpp"

bool processCommandLine(
	const std::vector<std::string>& args,
	bool& helpRequested,
	bool& versionRequested,
	std::string& InputFileName,
	std::string& OutputFileName )
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
	
	processCommandLine(cmdLineArgs,helpRequested,versionRequested,InputFileName,OutputFileName);
	/* Take each letter from user input and in each case:
 * 	convert to Ucase
 * 	change numbers to words
 * 	ignore any other (non alphanumeric) characters
 * 	in each case, add result to string*/

	char in_char{'x'};
	std::string outstring{""};

	//Loop until user presses Enter then ctrl+D
	while(std::cin >> in_char)
	{
		transformChar(outstring,in_char);
	
	}
	std::cout << outstring << std::endl;
}


