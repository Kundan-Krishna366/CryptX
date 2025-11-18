#include "../include/ReverseCipher.h"
#include <iostream>
#include <fstream>   // Required for file I/O
#include <string>
#include <algorithm> // Required for std::reverse
#include <stdexcept> // Required for exceptions

using namespace std;

// Note: Constructor is defined inline in the header, so we don't need it here.

void ReverseCipher::encrypt(const string& inputFile, const string& outputFile) {
    // 1. Try to open the input file
    ifstream inFile(inputFile);
    
    // Exception: File not found or unreadable
    if (!inFile.is_open()) {
        throw runtime_error("Error: Could not open input file: " + inputFile);
    }

    // 2. Read the entire file into a string
    // This uses an iterator to read from start to finish efficiently
    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    // Exception: File is empty
    if (content.empty()) {
        throw runtime_error("Error: Input file is empty. Nothing to encrypt.");
    }

    // 3. The Logic: Reverse the string
    reverse(content.begin(), content.end());

    // 4. Write to the output file
    ofstream outFile(outputFile);
    
    // Exception: Output file cannot be created (permissions, disk space)
    if (!outFile.is_open()) {
        throw runtime_error("Error: Could not create output file: " + outputFile);
    }

    outFile << content;
    outFile.close();
}

void ReverseCipher::decrypt(const string& inputFile, const string& outputFile) {
    // For Reverse Cipher, decryption is identical to encryption.
    // Reversing a reversed string gives you the original.
    try {
        encrypt(inputFile, outputFile);
    } catch (...) {
        // If encrypt throws an error, we just pass it up
        throw;
    }
}
