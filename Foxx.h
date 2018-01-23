#pragma once
#include"Animal.h"
#include<iostream>
class Foxx :public Animal {
public:
	void Add(int xx, int yy);
	std::string Action(std::string com);
	Foxx(int xx = 0, int yy = 0, World* w = NULL, int str = 3, int spe = 7, int a = 0, char m = 'L', std::string n = "Lis");
	~Foxx();

};
