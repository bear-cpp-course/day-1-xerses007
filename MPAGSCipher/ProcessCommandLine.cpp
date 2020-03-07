// process command line

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "ProcessCommandLine.hpp"

bool processCommandLine(const std::vector<std::string>& args, cmdLine& cmdArgs)
{
	for (size_t i{0}; i < args.size() ; i++)
	{
		if ((args.at(i) == "-h")||(args.at(i) == "--help"))
		{
			std::cout << "Help Entry to come, please wait!" << std::endl;
			cmdArgs.helpRequested = true;
			return false;	
		}
		if (args.at(i) == "--version")
		{
			std::cout << "Version 0.0.1"<< std::endl;
			cmdArgs.versionRequested = true;
			return false;	
		}
		if ((args.at(i) == "-i")||(args.at(i) == "--input"))
		{
			if(i+1 >= args.size())
			{
				std::cout << "error: input file not supplied" << std::endl;
				return false;
			}
			cmdArgs.inputFile = args.at(i+1);
			i++;
		}
		if ((args.at(i) == "-o")||(args.at(i) == "--output"))
		{
			if(i+1 >= args.size())
			{
				std::cout << "error: output file not supplied" << std::endl;
				return false;
			}
			cmdArgs.outputFile = args.at(i+1);
			i++;
		}
		if ((args.at(i) == "-c")||(args.at(i) == "--cipher"))
		{
			if(i+1 >= args.size())
			{
				std::cout << "error: cipher not given" << std::endl;
				return false;
			}
			if(args.at(i+1) == "caesar" || (args.at(i+1) == "c"))
			{
				cmdArgs.cipherType = CipherType::Caesar;
			}else if( args.at(i+1) == "playfair" || (args.at(i+1) == "p"))
			{
				cmdArgs.cipherType = CipherType::Playfair;
			}else
			{
				std::cerr << "[error] unknown cipher '" << args[i+1] << "'" <<std::endl;
				return false;
			}  
			i++;
		}
		if ((args.at(i) == "-k")||(args.at(i) == "--key"))
		{
			if(i+1 >= args.size())
			{
				std::cout << "error: key not given" << std::endl;
				return false;
			}
			cmdArgs.key = args.at(i+1);
			i++; // skip next arg as it is the value of k
		}
		if ((args.at(i) == "-d")||(args.at(i) == "--decrypt"))
		{
			cmdArgs.cMode = CipherMode::decrypt;
		}
		//std::cout << args.at(i) << std::endl;
	}
	return true;
}
