#ifndef CIPHER_H
#define CIPHER_H

#include <string>
using namespace std;

class Cipher {
public:
    virtual ~Cipher() = default;

    // Every cipher class MUST implement these:
    virtual void encrypt(const string& inputFile, const string& outputFile) = 0;
    virtual void decrypt(const string& inputFile, const string& outputFile) = 0;
};

#endif
