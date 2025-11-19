#include "../include/ReverseCipher.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Constructor
ReverseCipher::ReverseCipher() {
    // No initialization required for Reverse Cipher
}

void ReverseCipher::encrypt(const string& inputFile, const string& outputFile) {
    // 1. Open input file
    ifstream inFile(inputFile);

    // Check if file opened successfully
    if (!inFile.is_open()) {
        throw runtime_error("Error: Could not open input file: " + inputFile);
    }

    // 2. Read entire file content into a string using iterators
    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    // Check for empty input
    if (content.empty()) {
        throw runtime_error("Error: Input file is empty.");
    }

    // 3. Reverse the string content
    reverse(content.begin(), content.end());

    // 4. Open output file
    ofstream outFile(outputFile);

    // Check if output file opened successfully
    if (!outFile.is_open()) {
        throw runtime_error("Error: Could not create output file: " + outputFile);
    }

    // Write processed content to file
    outFile << content;
    outFile.close();
}

void ReverseCipher::decrypt(const string& inputFile, const string& outputFile) {
    // Decryption is identical to encryption for Reverse Cipher
    try {
        encrypt(inputFile, outputFile);
    } catch (...) {
        throw; // Rethrow any exceptions caught from encrypt
    }
}
