/*
ezpssw aka easy password aka password generator and storage
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Generating part.h"
#include <string>

int MeniuPasirinkimas, lenght, menu2 = 0;
bool Dideles, mazos, skaiciai, simboliai;	

int meniu() {
	while (true) {
		std::cout << "---------------------------------\n";
		std::cout << "1. Generuoti nauja slaptazodi.\n";
		std::cout << "2. Uzsifruoti.\n";
		std::cout << "3. Atsifruoti.\n";
		std::cout << "9. Isjungti programa.\n";
		std::cout << "---------------------------------\n";
		std::cin >> MeniuPasirinkimas;
		switch (MeniuPasirinkimas) {
		case 1:
			std::cout << "Slaptazodyje naudoti dideles raides?\n";
			std::cout << "1.Taip\n";
			std::cout << "2.Ne\n";
			std::cin >> menu2;
			if (menu2 == 1) 
				Dideles = true;
			else 
				Dideles = false;
			menu2 = 0;
			std::cout << "Slaptazodyje naudoti mazas raides?\n";
			std::cout << "1.Taip\n";
			std::cout << "2.Ne\n";
			std::cin >> menu2;
			if (menu2 == 1) 
				mazos = true;
			else 
				mazos = false;
			menu2 = 0;
			std::cout << "Slaptazodyje naudoti skaicius?\n";
			std::cout << "1.Taip\n";
			std::cout << "2.Ne\n";
			std::cin >> menu2;
			if (menu2 == 1) 
				skaiciai = true;
			else
				skaiciai = false;
			menu2 = 0;
			std::cout << "Slaptazodyje naudoti kitus simbolius?\n";
			std::cout << "1.Taip\n";
			std::cout << "2.Ne\n";
			std::cin >> menu2;
			if (menu2 == 1) 
				simboliai = true;
			else 
				simboliai = false;
			menu2 = 0;
			MakePssw(lenght, Dideles, mazos, skaiciai, simboliai);
			break;
		case 2:
			encrytion();
			break;
		case 3:
			decrytion();
			break;
		case 9:
			return 0;
		}
	}
}



int main() {
	meniu();
	return 0;
}