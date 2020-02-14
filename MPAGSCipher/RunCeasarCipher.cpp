
#include<string>

#include"RunCeasarCipher.hpp"


std::string runCeasarCipher(const std::string& instring,const int key)
{
	std::string outstring{""};
	for(const char& c : instring)
	{
		if(c + key > 90)
		{
			outstring += static_cast<char>(c+key-26);
		}
		else if(c+key<65)
		{
			outstring += static_cast<char>(c+key+26);
		}
		else
		{
			outstring += static_cast<char>(c+key);
		}
	}
	return outstring;
}
