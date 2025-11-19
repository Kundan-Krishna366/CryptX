#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "Cipher.h"
#include <string>

class CaesarCipher : public Cipher {
private:
    int shift;  // Shift value for Caesar Cipher

public:
    // Constructor
    CaesarCipher(int shiftValue = 3);

    // File-based encryption/decryption
    void encrypt(const std::string& inputFile, const std::string& outputFile) override;
    void decrypt(const std::string& inputFile, const std::string& outputFile) override;

    // Helper to shift text
    char shiftChar(char c, int s);
};

#endif
