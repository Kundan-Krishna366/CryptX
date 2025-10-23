#ifndef XORCIPHER_H
#define XORCIPHER_H

#include "Cipher.h"

class XORCipher : public Cipher {
private:
    char key;

public:
    XORCipher(char k);
    void encrypt(const string& inputFile, const string& outputFile) override;
    void decrypt(const string& inputFile, const string& outputFile) override;
};

#endif
