#include "../include/ReverseCipher.h"
#include "../include/FileManager.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

// No special state needed
ReverseCipher::ReverseCipher() {}

// Encrypt: reverse content
void ReverseCipher::encrypt(const string &inputFile,
                            const string &outputFile) {
    string content = FileManager::readFile(inputFile);

    reverse(content.begin(), content.end());

    FileManager::writeFile(outputFile, content);
}

// Decrypt: reverse again to restore original
void ReverseCipher::decrypt(const string &inputFile,
                            const string &outputFile) {
    encrypt(inputFile, outputFile);
}
