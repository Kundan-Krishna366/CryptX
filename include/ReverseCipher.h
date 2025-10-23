#ifndef REVERSECIPHER_H
#define REVERSECIPHER_H

#include "Cipher.h"

class ReverseCipher : public Cipher {
public:
    ReverseCipher() {}
    void encrypt(const string& inputFile, const string& outputFile) override;
    void decrypt(const string& inputFile, const string& outputFile) override;
};

#endif
