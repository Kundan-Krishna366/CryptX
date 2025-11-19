#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager {
public:
    // Read entire file into a string, throw runtime_error on failure
    static std::string readFile(const std::string &path);

    // Write entire string to file, throw runtime_error on failure
    static void writeFile(const std::string &path,
                          const std::string &data);
};

#endif
