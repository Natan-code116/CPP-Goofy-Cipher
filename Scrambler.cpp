#include <iostream>
#include <string>
// added a function for more variety of texts
std::string Cipher(std::string text, int startershift) {


    for (int i = 0; i < text.length(); i++) {
        text[i] = text[i] + startershift;
        startershift++;
    }
    return text;
}

int main() {

    std::string original = "Hello world";
}