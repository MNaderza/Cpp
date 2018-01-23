#pragma once
#include"Animal.h"
#include<iostream>
class Antilope :public Animal {
public:
	void Add(int xx, int yy);
	bool Ran();
	std::string Action(std::string com);
	Antilope(int xx = 0, int yy = 0, World* w = NULL, int str = 4, int spe = 4, int a = 0, char m = 'A', std::string n = "Antylopa");
	~Antilope();

};
