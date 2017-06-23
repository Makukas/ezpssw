#pragma once
#include <random>
#include <string>
#include <iostream>
#include <fstream>

void encrytion() {
	char raide;
	std::ifstream fd("Pssw.txt");
	std::ofstream fr("temp.txt");
	while (!fd.eof()) {
		fd.get(raide);
		raide++;
		fr << raide;
	}
	fd.close();
	fr.close();
	std::ifstream fd1("temp.txt");
	std::ofstream fr1("Pssw.txt");
	while (!fd1.eof()) {
		fd1.get(raide);
		fr1 << raide;
	}
	fd1.close();
	fr1.close();
	std::ofstream fr2("temp.txt");
	fr2 << " ";
	fr2.close();
	remove("temp.txt");
}

void decrytion() {
	char raide;
	std::ifstream fd("Pssw.txt");
	std::ofstream fr("temp.txt");
	while (!fd.eof()) {
		fd.get(raide);
		raide--;
		fr << raide;
	}
	fd.close();
	fr.close();
	std::ifstream fd1("temp.txt");
	std::ofstream fr1("Pssw.txt");
	while (!fd1.eof()) {
		fd1.get(raide);
		fr1 << raide;
	}
	fd1.close();
	fr1.close();
	std::ofstream fr2("temp.txt");
	fr2 << " ";
	fr2.close();
	remove("temp.txt");
}






/*void uzkoduoti()
{
	std::ifstream fd("Pssw.txt");
	std::ofstream fr("Pssw1.txt");
	std::string tekstas;
	std::string sifruota;
	char r = 'm';
	while (!fd.eof())
	{
		std::getline(fd, tekstas);
	}
	for (int i = 0; i < tekstas.size(); ++i)
	{
		sifruota += tekstas[i] ^ (int(r) + i) % 20;
	}
	fr << sifruota << std::endl;
	fr.close();
	fd.close();
}

void atkoduoti()
{
	std::ifstream fd("Pssw.txt");
	std::ofstream fr("Pssw.txt");
	std::string tekstas;
	std::string desifruota;
	char r = 'm';
	while (!fd.eof())
	{
		std::getline(fd, tekstas);
	}
	for (int i = 0; i < tekstas.size(); ++i)
	{
		desifruota += tekstas[i] ^ (int(r) + i) % 20;
	}
	fr << desifruota << std::endl;
	fd.close();
	fr.close();
}*/
