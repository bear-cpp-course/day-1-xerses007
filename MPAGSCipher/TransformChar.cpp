// transform_char.cpp

#include <string>
#include <vector>
#include <cctype>

#include "TransformChar.hpp"

void transformChar(std::string& outstring,const char in_char)	
{
	// takes a string and appends (inplace) the character given
	// numbers are converted to words
	// output in all caps
	
	const std::vector<std::string> toword {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
	if(isdigit(in_char))
	{
		outstring.append( toword[in_char-'0']);		
	}
	else if (isalpha(in_char))
	{
		outstring +=  toupper(in_char);
	}
}


