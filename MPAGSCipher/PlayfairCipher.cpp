#include "PlayfairCipher.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

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
      	auto bitsToRemove = std::remove_if(key_.begin(),key_.end(),[](char c) {if (isalpha(c)){return false;}else{return true;}});	
	key_.erase(bitsToRemove,key_.end());
	// Change J -> I
 	std::replace_if(key_.begin(),key_.end(),[](char c){return c=='j';},'i');
        // Remove duplicated letters
        std::string foundLetters = "";
	// iterator that checks if a letter is in foundletters, adds it to foundletters if not, and removes it from key if it is
	auto removeDup = std::remove_if(key_.begin(),key_.end(),
		[&foundLetters](char c) {
			if (foundLetters.find(c)){
				return true;
			}else{
				foundLetters.push_back(c);
				return false;
			}
		}
	);
	key_.erase(removeDup,key_.end());
	// Store the coords of each letter
	using Char2PairMap = std::map<char,std::pair<int,int>>;
	Char2PairMap cpmap; 
	for (int i= 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cpmap.insert(std::make_pair(key_.at(i*5+j),std::make_pair(i,j)));
		}
	}
        // Store the playfair cipher key map
 	std::cout <<key_ <<std::endl;
}
std::string PlayfairCipher::applyCipher(const std::string& instring, const CipherMode cipherMode) const
{
	// Change J → I
	std::string tmpstring = instring;	
	// If repeated chars in a digraph add an X or Q if XX
	for(std::string::size_type i = 0; i < tmpstring.size();++i)
	{
		if (tmpstring.at(i)== tmpstring.at(i+1))
		{	
			if (tmpstring.at(i)=='X'){tmpstring.insert(i+1,1,'Q');}
			else{tmpstring.insert(i+1,1,'X');}
		}
	}
	// if the size of input is odd, add a trailing Z
	if(tmpstring.size() % 2 != 0){tmpstring.push_back('Z');}
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
