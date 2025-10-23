#include "../include/XORCipher.h"
#include <fstream>
#include <iostream>
using namespace std;

XORCipher::XORCipher(char k) : key(k) {}

void XORCipher::encrypt(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);
    if (!in || !out) throw "File open error in XORCipher::encrypt";

    char ch;
    while (in.get(ch)) {
        ch = ch ^ key;
        out.put(ch);
    }

    in.close();
    out.close();
}

void XORCipher::decrypt(const string& inputFile, const string& outputFile) {
    // XOR encryption and decryption are identical
    encrypt(inputFile, outputFile);
}
