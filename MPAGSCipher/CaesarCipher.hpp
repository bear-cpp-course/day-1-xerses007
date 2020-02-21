// declare CaesarCipher class
#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include "CipherMode.hpp"

/** CaesarCipher class that stores the key and has the applyCipher method that evaluates that key on a given string to either encrypt or decrypt
 * Use it by creating a new cipher and then using .applyCipher on it with the input string and boolean to encrypt **/
class CaesarCipher {
	public:
		explicit CaesarCipher(const int key); /// accepts input as int
		explicit CaesarCipher(const std::string& key);///input as string will be converted to int via std::stoi
		std::string applyCipher(const std::string& instring, const CipherMode cMode) const;///uses the cipher's key to encrypt/decrypt the given string
	private:
		const int key_ = 0;
};
#endif //MPAGSCIPHER_CAESARCIPHER_HPP
