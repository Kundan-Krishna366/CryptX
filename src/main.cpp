#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

// Include all blueprints
#include "../include/Cipher.h"
#include "../include/ReverseCipher.h"
#include "../include/CaesarCipher.h" 
#include "../include/XORCipher.h"    

using namespace std;

int main() {
    unique_ptr<Cipher> cipherApp; 
    int choice;
    int mode;

    cout << "======================================\n";
    cout << "      CryptX Secure System v1.0       \n";
    cout << "======================================\n";

    do {
        cout << "\n[MAIN MENU]\n";
        cout << "1. Caesar Cipher\n";
        cout << "2. XOR Cipher\n";
        cout << "3. Reverse Cipher\n";
        cout << "4. Exit\n";
        cout << "Select Option: ";
        
        // Input validation to prevent infinite loops on bad input
        if (!(cin >> choice)) {
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 4) {
            cout << "Exiting CryptX. Goodbye!\n";
            break;
        }

        try {
            // 1. Setup the Strategy based on user choice
            switch(choice) {
                case 1: {
                    int shift;
                    cout << ">> Enter Caesar Shift (integer): ";
                    cin >> shift;
                    // Assumes CaesarCipher takes an int in constructor
                    cipherApp = make_unique<CaesarCipher>(shift);
                    break;
                }
                case 2: {
                    string key;
                    cout << ">> Enter XOR Key (string): ";
                    cin >> key;
                    // Assumes XORCipher takes a string in constructor
                    cipherApp = make_unique<XORCipher>(key);
                    break;
                }
                case 3: {
                    // Reverse Cipher needs no key
                    cipherApp = make_unique<ReverseCipher>();
                    break;
                }
                default:
                    cout << "Invalid selection. Try again.\n";
                    continue; // Skip the rest of the loop
            }

            // 2. Select Mode (Encrypt/Decrypt)
            cout << "   [1] Encrypt\n   [2] Decrypt\n   Choose Mode: ";
            cin >> mode;

            if (mode != 1 && mode != 2) {
                throw runtime_error("Invalid mode selected. Please choose 1 or 2.");
            }

            // 3. Execute Logic
            // Note: We assume input/output files are fixed for simplicity, 
            // but you could also ask the user for filenames here.
            if (mode == 1) {
                cout << "   ...Processing 'data/input.txt' -> 'data/encrypted.txt'...\n";
                cipherApp->encrypt("data/input.txt", "data/encrypted.txt");
                cout << "   ✅ SUCCESS: Check 'data/encrypted.txt'\n";
            } 
            else {
                cout << "   ...Processing 'data/encrypted.txt' -> 'data/decrypted.txt'...\n";
                cipherApp->decrypt("data/encrypted.txt", "data/decrypted.txt");
                cout << "   ✅ SUCCESS: Check 'data/decrypted.txt'\n";
            }

        } catch (const exception& e) {
            // This catches errors (like missing files) and prints them without crashing
            cerr << "\n   ❌ ERROR: " << e.what() << "\n";
            cout << "   Returning to menu...\n";
        }

    } while (choice != 4);

    return 0;
}
