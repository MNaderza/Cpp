#pragma once
#include"Animal.h"
class Turtle :public Animal {
public:
	void Add(int xx, int yy);
	bool Resisted(int s);
	std::string Action(std::string com);
	Turtle(int xx = 0, int yy = 0, World* w = NULL, int str = 2, int spe = 1, int a = 0, char m = 'Z', std::string n = "Zolw");
	~Turtle();
};
