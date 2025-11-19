#include "../include/CaesarCipher.h"
#include "../include/FileManager.h"
#include <stdexcept>

using namespace std;

// Constructor to initialize the shift value (normalized to 0–25)
CaesarCipher::CaesarCipher(int shiftValue)
    : shift(shiftValue % 26) {}

// Shift a single character
char CaesarCipher::shiftChar(char c, int s) {
    if (c >= 'A' && c <= 'Z') {
        return char('A' + (c - 'A' + s + 26) % 26);
    }
    if (c >= 'a' && c <= 'z') {
        return char('a' + (c - 'a' + s + 26) % 26);
    }
    return c; // Non-alphabetic characters remain unchanged
}

// Encrypt: shift forward
void CaesarCipher::encrypt(const string &inputFile,
                           const string &outputFile) {
    string content = FileManager::readFile(inputFile);

    for (char &c : content) {
        c = shiftChar(c, shift);
    }

    FileManager::writeFile(outputFile, content);
}

// Decrypt: shift backward
void CaesarCipher::decrypt(const string &inputFile,
                           const string &outputFile) {
    string content = FileManager::readFile(inputFile);

    for (char &c : content) {
        c = shiftChar(c, -shift);
    }

    FileManager::writeFile(outputFile, content);
}
