#include "../include/ReverseCipher.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void ReverseCipher::encrypt(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    if (!in || !out) throw "File open error in ReverseCipher::encrypt";

    vector<char> content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    for (auto it = content.rbegin(); it != content.rend(); ++it)
        out.put(*it);

    in.close();
    out.close();
}

void ReverseCipher::decrypt(const string& inputFile, const string& outputFile) {
    // Reverse cipher works the same both ways
    encrypt(inputFile, outputFile);
}
