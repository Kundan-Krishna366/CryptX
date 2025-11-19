#ifndef REVERSECIPHER_H
#define REVERSECIPHER_H

#include "Cipher.h"
#include <string>

using namespace std;

class ReverseCipher : public Cipher {
public:
    // Constructor
    ReverseCipher();

    // Methods override the Base Class to handle file I/O directly
    void encrypt(const string& inputFile, const string& outputFile) override;
    void decrypt(const string& inputFile, const string& outputFile) override;
};

#endif
