#include "../include/FileManager.h"
#include <fstream>
#include <stdexcept>

using namespace std;

string FileManager::readFile(const string &path) {
    ifstream in(path, ios::binary);
    if (!in.is_open()) {
        throw runtime_error("Error: Could not open input file: " + path);
    }

    string buffer((istreambuf_iterator<char>(in)),
                  istreambuf_iterator<char>());

    if (in.bad()) {
        throw runtime_error("Error: Failed while reading file: " + path);
    }

    if (buffer.empty()) {
        throw runtime_error("Error: Input file is empty.");
    }

    return buffer;
}

void FileManager::writeFile(const string &path,
                            const string &data) {
    ofstream out(path, ios::binary);
    if (!out.is_open()) {
        throw runtime_error("Error: Could not create output file: " + path);
    }

    out.write(data.data(), static_cast<streamsize>(data.size()));
    if (!out) {
        throw runtime_error("Error: Failed while writing file: " + path);
    }
}
