#include "../include/CaesarCipher.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

// Constructor to initialize the shift value with maintinig it attainable
CaesarCipher::CaesarCipher(int shiftValue) : shift(shiftValue % 26) {}

// Shifts a single character by shift value
char CaesarCipher::shiftChar(char c, int s) {
    if (c >= 'A' && c <= 'Z') {
        return char('A' + (c - 'A' + s + 26) % 26);
    }
    if (c >= 'a' && c <= 'z') {
        return char('a' + (c - 'a' + s + 26) % 26);
    }
    return c; // Non-alphabetic characters remains unchanged
}

//  Caesar Cipher Method implemented
void CaesarCipher::encrypt(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        throw runtime_error("Error: Could not open input file: " + inputFile);
    }

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    if (content.empty()) {
        throw runtime_error("Error: Input file is empty.");
    }

    for (char& c : content) {
        c = shiftChar(c, shift);
    }

    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        throw runtime_error("Error: Could not create output file: " + outputFile);
    }

    outFile << content;
    outFile.close();
}

// Decrypts file by shifting the character in the opposite direction
void CaesarCipher::decrypt(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        throw runtime_error("Error: Could not open input file: " + inputFile);
    }

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    if (content.empty()) {
        throw runtime_error("Error: Input file is empty.");
    }

    for (char& c : content) {
        c = shiftChar(c, -shift);
    }

    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        throw runtime_error("Error: Could not create output file: " + outputFile);
    }

    outFile << content;
    outFile.close();
}
