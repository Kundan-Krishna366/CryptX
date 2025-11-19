#ifndef CIPHER_H
#define CIPHER_H

#include <string>
using namespace std;

class Cipher {
public:
    virtual ~Cipher() = default;

    // virtual methods to encrypt and decrpyt methods that should be defined in each type of methods according to thier algo .
    virtual void encrypt(const string& inputFile, const string& outputFile) = 0;
    virtual void decrypt(const string& inputFile, const string& outputFile) = 0;
};

#endif
