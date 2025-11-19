#include "../include/XORCipher.h"
#include <fstream>
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
    ifstream in(inputFile, ios::binary);
    if (!in.is_open()) {
        throw runtime_error("Failed to open input file: " + inputFile);
    }

    ofstream out(outputFile, ios::binary);
    if (!out.is_open()) {
        throw runtime_error("Failed to open output file: " + outputFile);
    }

    // Read entire file into memory (OK for small project files)
    string buffer((istreambuf_iterator<char>(in)),
                  istreambuf_iterator<char>());

    if (in.bad()) {
        throw runtime_error("Error while reading from file: " + inputFile);
    }

    // Core XOR logic
    xorBuffer(buffer);

    out.write(buffer.data(),
              static_cast<streamsize>(buffer.size()));

    if (!out) {
        throw runtime_error("Error while writing to file: " + outputFile);
    }
}

void XORCipher::decrypt(const string &inputFile,
                        const string &outputFile) {
    // XOR with the same key again reverses the operation
    encrypt(inputFile, outputFile);
}
