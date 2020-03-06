#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include "CipherMode.hpp"
#include "CipherType.hpp"

struct cmdLine{
bool helpRequested;
bool versionRequested;
std::string inputFile;
std::string outputFile;
std::string key;
CipherMode cMode;
CipherType cipherType;
};

bool processCommandLine(const std::vector<std::string>& args, cmdLine& cmdArgs);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP 
