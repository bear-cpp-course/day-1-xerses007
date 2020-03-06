#include "PlayfairCipher.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

PlayfairCipher::PlayfairCipher(const std::string& key)
{
	PlayfairCipher::setKey(key);
}

void PlayfairCipher::setKey(const std::string& key)
{
	//store the original key and append the alphabet
  	key_ = key + "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	
	// Make sure the key is upper case
	std::transform(key_.begin(),key_.end(),key_.begin(),::toupper);
	// Remove non-alpha characters
      	// Change J -> I
 
        // Remove duplicated letters
 
        // Store the coords of each letter
 
        // Store the playfair cihper key map
}
std::string PlayfairCipher::applyCipher(const std::string& instring, const CipherMode cipherMode) const
{
	// Change J → I
	
	// If repeated chars in a digraph add an X or Q if XX
	
	// if the size of input is odd, add a trailing Z

	// Loop over the input in Digraphs
	
	// - Find the coords in the grid for each digraph
	
	// - Apply the rules to these coords to get 'new' coords
	
	// - Find the letter associated with the new coords
	
	// return the text
	if(instring == "" && cipherMode == CipherMode::encrypt)
	{
		std::cout << "coolbeans"<<std::endl;
	}
	std::string outstring{"PlaceHolderString"};
	return outstring;
}
