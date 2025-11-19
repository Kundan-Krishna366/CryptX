#ifndef XORCIPHER_H
#define XORCIPHER_H

#include <string>
#include "Cipher.h"

class XORCipher : public Cipher {
private:
    std::string key;

    void xorBuffer(std::string &buffer) const;

public:
    explicit XORCipher(const std::string &key);

    void encrypt(const std::string &inputFile,
                 const std::string &outputFile) override;

    void decrypt(const std::string &inputFile,
                 const std::string &outputFile) override;
};

#endif // XORCIPHER_H
