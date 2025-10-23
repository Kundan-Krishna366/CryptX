#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "Cipher.h"

class CaesarCipher : public Cipher {
private:
    int shift;

public:
    CaesarCipher(int s);
    void encrypt(const string& inputFile, const string& outputFile) override;
    void decrypt(const string& inputFile, const string& outputFile) override;
};

#endif
