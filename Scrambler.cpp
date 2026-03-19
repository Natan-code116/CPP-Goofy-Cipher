#include <iostream>
#include <string>
// added a function for more variety of texts
std::string Cipher(std::string text, int startershift) {


	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') continue;
		// added a failsafe
		text[i] = (text[i] - 32 + startershift) % 95 + 32;
		startershift++;
	}
	return text;
}

std::string Decipher(std::string text, int startershift) {
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') continue;
		// Subtract the shift to go backwards
		text[i] = text[i] - startershift;
		startershift++;
	}
	return text;
}

void showCipher(std::string text) {
	std::cout << "Your ciphered text: " << text << std::endl;
}

int main() {
	char choice;

	do {
		std::string original, currentResult;

		std::cout << "Enter any text: ";
		std::getline(std::cin, original);

		std::string newstring = Cipher(original, 2);
		showCipher(newstring);

		std::cout << "Choose the next option [DECRYPT] / [EXIT]: ";
		std::cin >> choice;
		std::cin.ignore();
		//decryption
		if (choice == 'd') {
			int shifts;
			std::string encword;

			std::cout << "Enter the encrypted message: ";
			std::getline(std::cin, encword);

			std::cout << "Enter the number of shifts desired: ";
			std::cin >> shifts;

			std::string fix = Decipher(encword, shifts);
			std::cout << "Your Deciphered text is: " << fix << std::endl;
			break;
		}
		//manual exit
	} while (choice != 'd');
		std::cout << "Exiting..." << std::endl;
		return 0;
	
}