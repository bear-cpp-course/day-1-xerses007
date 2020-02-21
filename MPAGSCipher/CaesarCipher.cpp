#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(const int key) : key_{key}
{
}
CaesarCipher::CaesarCipher(const std::string& key) : key_{std::stoi(key)}
{
}
std::string CaesarCipher::applyCipher(const std::string& instring, const CipherMode cMode) const
{
	std::string outstring{""};
	int ekey{key_};
	switch(cMode){
		case CipherMode::encrypt:
			break;
		case CipherMode::decrypt:
			ekey = -key_;
			break;
	}

	for(const char& c : instring)
	{
		if(c + ekey > 90)
		{
			outstring += static_cast<char>(c + ekey-26);
		}
		else if(c+ekey<65)
		{
			outstring += static_cast<char>(c + ekey+26);
		}
		else
		{
			outstring += static_cast<char>(c + ekey);
		}
	}
	return outstring;
}
