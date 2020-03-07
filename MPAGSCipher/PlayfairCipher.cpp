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
			if (foundLetters.find(c)!= std::string::npos){
				return true;
			}else{
				foundLetters.push_back(c);
				return false;
			}
		}
	);
	key_.erase(removeDup,key_.end());
	// clear the key maps ready to store into
	_cpmap.clear();
	_pcmap.clear();
	// Store the coords of each letter into the maps
	for (int i= 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			_cpmap.insert(std::make_pair(key_.at(i*5+j),std::make_pair(j,i)));
			_pcmap.insert(std::make_pair(std::make_pair(j,i),key_.at(i*5+j)));
		}
	}
}
std::string PlayfairCipher::applyCipher(const std::string& instring, const CipherMode cipherMode) const
{
	// Change J → I
	std::string tmpstring = instring;
	std::string outstring = "";	
	// If repeated chars in a digraph add an X or Q if XX
	for(std::string::size_type i = 0; i < tmpstring.size()-1;++i)
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
	std::pair<int,int> firstcoords;
	std::pair<int,int> secondcoords;
	int cmode = 1; //+1 encrypts, -1 decrypts
	switch(cipherMode){
		case CipherMode::encrypt:
			break;
		case CipherMode::decrypt:
			cmode = -1;
			break;
	}
	for(std::string::size_type i =0; i<tmpstring.size(); i+=2)
	{
		// - Find the coords in the grid for each digraph
		firstcoords = _cpmap.at(tmpstring.at(i));
		secondcoords  = _cpmap.at(tmpstring.at(i+1));
		// - Apply the rules to these coords to get 'new' coords
		if (firstcoords.first == secondcoords.first)
		{
			firstcoords.second += cmode; // cmode = +1 if encrypt or -1 if decrypt
			secondcoords.second += cmode;
		}else if (firstcoords.second == secondcoords.second)
		{
			firstcoords.first += cmode;
			secondcoords.first += cmode;	
		}else
		{
			std::swap(firstcoords.first,secondcoords.first);
		}
		//wrap coords if necessary
		for(auto &coord : {&firstcoords.first,&firstcoords.second,&secondcoords.first,&secondcoords.second})
		{
			if(*coord>4){*coord=0;}else if(*coord<0){*coord=4;}
		}
		
		// - Append the two letters associated with the new coords to the output string
		outstring.push_back(_pcmap.at(firstcoords));
		outstring.push_back(_pcmap.at(secondcoords));
	}
	
	// return the text
	return outstring;
}
