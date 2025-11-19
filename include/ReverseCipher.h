#ifndef REVERSECIPHER_H
#define REVERSECIPHER_H

#include "Cipher.h"
#include <string>

class ReverseCipher : public Cipher {
public:
    ReverseCipher();

    void encrypt(const std::string &inputFile,
                 const std::string &outputFile) override;
    void decrypt(const std::string &inputFile,
                 const std::string &outputFile) override;
};

#endif
