#pragma once

#include <iostream>
#include <string>
#include <random>
#include <string>
#include "encryption.h"

char BigLetters[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','X','Y','Z' };
char SmallLetters[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','p','q','r','s','t','u','v','w','x','y','z' };
int Numbers[] = { 0,1,2,3,4,5,6,7,8,9 };
char SpecialSymbols[] = { '!','@','#','$','%','^','&','*','(',')','_','-','=','+','/','?','>','<',',','.','+','-' };
int sk;
std::string Password[32];
int i;
int lenght1;
int MeniuPasirinkimas2;
std::string puslapis;
int CTR = 0;

//Random number generator

void randomnumber(int nuo, int iki) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(nuo, iki); // define the range
	sk = distr(eng); // generate numbers
}

void MakePssw(int lenght, bool bigLetters, bool smallLetters, bool number, bool specSymbols) {
	i = 0;
	lenght1 = 1;
	std::cout << "Irasykite puslapio pavadinima, kuriam skirtas slaptazodis.\n";
	std::cin >> puslapis;
	std::cout << "Irasykite slaptazodzio ilgi.\n";
	while (CTR != 1) {
		std::cin >> lenght;
		if (lenght > 32) {
			std::cout << "Slaptazodis per ilgas\n";

		}
		else CTR = 1;
	}
	CTR = 0;
	std::cout << "Slaptazodis:\n" << std::endl;
	while (lenght1 != (lenght + 1)) {
		randomnumber(1, 4);
		/////////////////////////////////
		if (sk == 1) {
			if (bigLetters == true) {
				randomnumber(0, 24);
				Password[i] = BigLetters[sk];
				std::cout << BigLetters[sk];
				i++;
				lenght1++;
			}
		}
		/////////////////////////////////
		if (sk == 2) {
			if (smallLetters == true) {
				randomnumber(0, 24);
				Password[i] = SmallLetters[sk];
				std::cout << SmallLetters[sk];
				i++;
				lenght1++;
			}
		}
		/////////////////////////////////
		if (sk == 3) {
			if (number == true) {
				randomnumber(0, 9);
				Password[i] = std::to_string(Numbers[sk]);
				std::cout << Numbers[sk];
				i++;
				lenght1++;
			}
		}
		/////////////////////////////////
		if (sk == 4) {
			if (specSymbols == true) {
				randomnumber(0, 21);
				Password[i] = SpecialSymbols[sk];
				std::cout << SpecialSymbols[sk];
				i++;
				lenght1++;
			}
		}
		/////////////////////////////////
	}
	std::cout << "\n";
	std::cout << "Irasyti slaptazodi i faila?\n";
	std::cout << "1.Taip\n";
	std::cout << "2.Ne\n";
	std::cin >> MeniuPasirinkimas2;
	switch (MeniuPasirinkimas2) {
	case 1:
		std::ofstream fd;
		std::string df = "Pssw.txt";
		fd.open(df, std::ios_base::app | std::ios_base::out);

		fd << "----------------------------------------\n";
		fd << puslapis << "\n";
		lenght1 = 0;
		while (lenght1 != (lenght + 1)) {
			fd << Password[lenght1];
			lenght1++;
		}
		fd << "\n";
		std::cout << "Slaptazodis irasytas\n";
		fd.close();
	}
}





