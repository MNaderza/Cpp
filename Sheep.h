#pragma once
#include"Animal.h"
class Sheep :public Animal {
public:
	void Add(int xx, int yy);
	Sheep(int xx=0, int yy=0, World* w=NULL, int str=4, int spe=4, int a=0,char m='O', std::string n = "Owca");
	~Sheep();
};
