#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "Cipher.h"
#include <string>

class CaesarCipher : public Cipher {
private:
    int shift;  // Shift value for Caesar Cipher

public:
    explicit CaesarCipher(int shiftValue = 3);

    void encrypt(const std::string &inputFile,
                 const std::string &outputFile) override;
    void decrypt(const std::string &inputFile,
                 const std::string &outputFile) override;

    char shiftChar(char c, int s);
};

#endif
