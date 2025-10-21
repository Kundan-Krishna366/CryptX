#include <iostream>
#include <limits> // Required for input cleanup
#include "../include/Cipher.h"          // Base class for polymorphism
#include "../include/CaesarCipher.h"    // Derived class implementation
#include "../include/XORCipher.h"       // Derived class implementation
#include "../include/ReverseCipher.h"   // Derived class implementation
#include "../include/FileManager.h"     // Utility for file I/O and logging

using namespace std;

// Function Prototypes
void displayMenu();
void handleCipherOperation(bool encryptMode);
bool authenticateUser(FileManager& fm);

int main() {
    cout << "--- CryptX File Encryption & Decryption System ---" << endl;

    // The FileManager handles logging and authentication
    // We instantiate it once to manage all file operations.
    FileManager fileManager;

    // Optional: Implement Step 3 - Authentication
    if (!authenticateUser(fileManager)) {
        cout << "Authentication failed. Exiting program." << endl;
        return 1;
    }

    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        cout << "Enter choice: ";

        // Handle potentially non-integer input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1: // Encrypt
                handleCipherOperation(true);
                break;
            case 2: // Decrypt
                handleCipherOperation(false);
                break;
            case 3: { // View Logs
                cout << "\n--- Viewing Logs ---\n";
                // Assuming FileManager has a function to display log.txt
                // Member 3 will implement FileManager::viewLog()
                fileManager.viewLog();
                break;
            }
            case 4: // Exit
                cout << "Exiting CryptX. Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice. Please select 1, 2, 3, or 4." << endl;
                break;
        }
        cout << "\n----------------------------------------------------\n";
    }

    return 0;
}


void displayMenu() {
    cout << "\nMain Menu:" << endl;
    cout << "1. Encrypt File" << endl;
    cout << "2. Decrypt File" << endl;
    cout << "3. View Logs" << endl;
    cout << "4. Exit" << endl;
}


void handleCipherOperation(bool encryptMode) {
    
    Cipher* cipherPtr = nullptr;
    

    FileManager fileManager; 

    // 1. Gather file and cipher type inputs
  string operation;
    if (encryptMode) {
        operation = "Encryption";
    } else {
        operation = "Decryption";
    }

    cout << "\n--- " << operation << " Mode ---\n";


    char inputFile[128], outputFile[128];
    int cipherChoice;

    cout << "Enter input file (e.g., input.txt): ";
    cin >> inputFile;
    cout << "Enter output file (e.g., encrypted.txt): ";
    cin >> outputFile;

    cout << "\nChoose method: 1. Caesar 2. XOR 3. Reverse" << endl;
    cout << "Choice: ";
    cin >> cipherChoice;

    // 2. Dynamic Object Creation (Polymorphism)
    switch (cipherChoice) {
        case 1: { // Caesar Cipher
            int shift;
            cout << "Enter shift amount (integer): ";
            if (!(cin >> shift)) {
                // Handle invalid shift input
                cerr << "Invalid shift amount." << endl;
                return;
            }
            // ASSUMING CaesarCipher constructor takes an int shift
            cipherPtr = new CaesarCipher(shift);
            break;
        }
        case 2: { // XOR Cipher
            char key;
            cout << "Enter key (single character): ";
            cin >> key;
            // ASSUMING XORCipher constructor takes a char key
            cipherPtr = new XORCipher(key);
            break;
        }
        case 3: // Reverse Cipher
            cipherPtr = new ReverseCipher();
            break;
        default:
            cout << "Invalid cipher choice." << endl;
            return;
    }

    // 3. Execution (Polymorphic Call)
    if (cipherPtr != nullptr) {
        try {
            if (encryptMode) {
                // Polymorphic call: The correct encrypt function is called based on the object type
                cipherPtr->encrypt(inputFile, outputFile);
            } else {
                // Polymorphic call: The correct decrypt function is called based on the object type
                cipherPtr->decrypt(inputFile, outputFile);
            }

            // 4. Logging the Operation
            // Member 4 will integrate the overloaded << operator here later.
            string logMsg = operation + " successful: " + inputFile + " -> " + outputFile;
            // Member 3 will implement FileManager::logOperation()
            fileManager.logOperation(logMsg.c_str());

            cout << operation << " complete!" << endl;

        } catch (const char* msg) {
            cerr << "Error during operation: " << msg << endl;
        }

        // 5. Cleanup (Crucial for dynamically allocated objects)
        delete cipherPtr;
        cipherPtr = nullptr;
    }
}


bool authenticateUser(FileManager& fm) {

    string password;
    cout << "Enter system password: ";
    cin >> password;

    //  Member 3 will update FileManager::checkPassword()
    if (password == "1234") {
        cout << "Password correct. Access granted." << endl;
        return true;
    } else {
        cout << "Incorrect password. " << endl;
        return false;
    }
}
