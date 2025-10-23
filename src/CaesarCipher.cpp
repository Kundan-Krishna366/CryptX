#include "../include/CaesarCipher.h"
#include <fstream>
#include <iostream>
using namespace std;

CaesarCipher::CaesarCipher(int s) : shift(s % 26) {}

void CaesarCipher::encrypt(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    if (!in || !out) throw "File open error in CaesarCipher::encrypt";

    char ch;
    while (in.get(ch)) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + shift + 26) % 26 + base;
        }
        out.put(ch);
    }

    in.close();
    out.close();
}

void CaesarCipher::decrypt(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    if (!in || !out) throw "File open error in CaesarCipher::decrypt";

    char ch;
    while (in.get(ch)) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base - shift + 26) % 26 + base;
        }
        out.put(ch);
    }

    in.close();
    out.close();
}
