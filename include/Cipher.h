#ifndef CIPHER_H
#define CIPHER_H

#include <string>
using namespace std;

class Cipher {
public:
    virtual void encrypt(const string& inputFile, const string& outputFile) = 0;
    virtual void decrypt(const string& inputFile, const string& outputFile) = 0;
    virtual ~Cipher() {} // Virtual destructor for polymorphism
};

#endif
