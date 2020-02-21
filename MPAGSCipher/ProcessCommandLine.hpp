#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include "CipherMode.hpp"

struct cmdLine{
bool helpRequested;
bool versionRequested;
std::string inputFile;
std::string outputFile;
std::string cipher;
std::string key;
CipherMode cMode;
};

bool processCommandLine(const std::vector<std::string>& args, cmdLine& cmdArgs);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP 
