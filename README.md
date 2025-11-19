# CryptX Secure System

A simple C++ console app that encrypts and decrypts text files using three ciphers: Caesar, XOR, and Reverse.

## Build

cd src
g++ *.cpp -o cryptx
./cryptx


## Usage

1. Put your plaintext in `data/input.txt`.
2. Run `./cryptx`.
3. Choose:
   - Cipher: `1` Caesar, `2` XOR, `3` Reverse
   - Mode: `1` Encrypt, `2` Decrypt
4. Check:
   - Encrypted: `data/encrypted.txt`
   - Decrypted: `data/decrypted.txt`

For XOR, use the **same key** for both encrypt and decrypt.
