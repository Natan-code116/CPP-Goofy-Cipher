#include <iostream>
#include <string>
// added a function for more variety of texts
std::string Cipher(std::string text, int startershift) {


    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') continue;
        text[i] = text[i] + startershift;
        startershift++;
    }
    return text;
}
void showCipher(std::string text) {
    std::cout << "Your ciphered text: " << text << std::endl;
}

int main() {

    std::string original;

    std::cout << "Enter any text: ";
    std::getline(std::cin, original);

    std::string newstring = Cipher(original, 2);
    showCipher(newstring);
    return 0;
}