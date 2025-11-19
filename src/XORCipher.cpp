#include "../include/XORCipher.h"
#include "../include/FileManager.h"
#include <stdexcept>

using namespace std;

XORCipher::XORCipher(const string &key) : key(key) {
    if (this->key.empty()) {
        throw invalid_argument("XOR key cannot be empty.");
    }
}

void XORCipher::xorBuffer(string &buffer) const {
    const size_t keyLen = key.size();
    for (size_t i = 0; i < buffer.size(); ++i) {
        buffer[i] = static_cast<char>(buffer[i] ^ key[i % keyLen]);
    }
}

void XORCipher::encrypt(const string &inputFile,
                        const string &outputFile) {
    string buffer = FileManager::readFile(inputFile);

    xorBuffer(buffer);

    FileManager::writeFile(outputFile, buffer);
}

void XORCipher::decrypt(const string &inputFile,
                        const string &outputFile) {
    // XORing with the same key again decrypts
    encrypt(inputFile, outputFile);
}
