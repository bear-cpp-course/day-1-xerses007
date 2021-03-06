// declare PlayfairCipher class
#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include <string>
#include "CipherMode.hpp"
#include <map>

/** \brief PlayfairCipher class that stores the key and has the applyCipher method which evaluates that key on a given string to either encrypt or decrypt
 *
 * Use it by creating a new cipher and then using .applyCipher on it with the input string and boolean to encrypt 
 */
class PlayfairCipher {
	public:
		explicit PlayfairCipher(const std::string& key); /// accepts input as string
		void setKey(const std::string& key);/// sets the cipher key
		std::string applyCipher(const std::string& instring, const CipherMode cipherMode) const;///uses the cipher's key to encrypt/decrypt the given string
	private:
		std::string key_;
		
		using Char2PairMap = std::map<char,std::pair<int,int>>;
		using Pair2CharMap = std::map<std::pair<int,int>,char>;

		Char2PairMap _cpmap;
		Pair2CharMap _pcmap; 
};
#endif //MPAGSCIPHER_CAESARCIPHER_HPP
