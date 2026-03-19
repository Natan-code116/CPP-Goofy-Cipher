#include <iostream>
#include <string>

int main() {
	std::string text = "Hello world!";
	int shift = 2;

	std::cout << "Original text: " << text << std::endl;

	for (int i = 0; i < text.length(); i++) {
		text[i] = text[i] + shift;
		shift++;
	}

	std::cout << "Cipher/Scrambled text: " << text << std::endl;
}
