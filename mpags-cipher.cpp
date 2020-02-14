// mpags-cipher.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main()
{	
	//this is a comment
	/* Take each letter from user input and in each case:
 * 	convert to Ucase
 * 	change numbers to words
 * 	ignore any other (non alphanumeric) characters
 * 	in each case, add result to string*/

	char in_char{'x'};
	std::string outstring{""};
	while(std::cin >> in_char)
	{
		//Loop until user presses Enter then ctrl+D
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
	std::cout << outstring << std::endl;
}
