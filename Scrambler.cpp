#include <iostream>
#include <string>

// Encryption logic with ASCII wrapping
std::string Cipher(std::string text, int startershift) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') continue;
        // Keep within printable ASCII (32-126)
        text[i] = (text[i] - 32 + startershift) % 95 + 32;
        startershift++;
    }
    return text;
}

// Decryption logic - MUST mirror the Cipher math to work
std::string Decipher(std::string text, int startershift) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') continue;

        // To reverse (x + shift) % 95, we use (x - shift) 
        // We add 95 before the modulo to handle negative results in C++
        int val = (text[i] - 32 - (startershift % 95) + 95) % 95;
        text[i] = val + 32;

        startershift++;
    }
    return text;
}

int main() {
    int mode;

    do {
        std::cout << "\n=== ENTROPY ENGINE STARTUP ===" << std::endl;
        std::cout << "1. Encrypt a message\n2. Decrypt a message\n3. Exit\nSelection: ";
        std::cin >> mode;
        std::cin.ignore(); // Crucial: clears the newline so getline works later

        if (mode == 1) {
            std::string input;
            int key;
            std::cout << "Enter text to scramble: ";
            std::getline(std::cin, input);
            std::cout << "Enter secret shift key (e.g., 2): ";
            std::cin >> key;
            std::cin.ignore();

            std::cout << "\nRESULT: " << Cipher(input, key) << std::endl;
        }
        else if (mode == 2) {
            std::string input;
            int key;
            std::cout << "Enter scrambled text: ";
            std::getline(std::cin, input);
            std::cout << "Enter the secret shift key: ";
            std::cin >> key;
            std::cin.ignore();

            std::cout << "\nRESTORED: " << Decipher(input, key) << std::endl;
        }

    } while (mode != 3);

    std::cout << "System offline. Goodbye." << std::endl;
    return 0;
}