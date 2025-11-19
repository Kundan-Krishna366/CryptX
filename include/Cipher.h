#ifndef CIPHER_H
#define CIPHER_H

#include <string>

class Cipher {
public:
    virtual ~Cipher() = default;

    // Pure virtual methods every cipher must implement
    virtual void encrypt(const std::string &inputFile,
                         const std::string &outputFile) = 0;
    virtual void decrypt(const std::string &inputFile,
                         const std::string &outputFile) = 0;
};

#endif
