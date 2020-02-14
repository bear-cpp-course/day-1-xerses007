// mpags-cipher.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main(int argc, char* argv[])
{	
	// convert input to vector of strings
	const std::vector<std::string> cmdLineArgs{argv,argv+argc};

	for (size_t i{0}; i < cmdLineArgs.size() ; i++)
	{
		std::cout << cmdLineArgs.at(i) << std::endl;
	}
	//this is a comment
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
