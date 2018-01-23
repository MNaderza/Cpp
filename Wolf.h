#pragma once
#include"Animal.h"
class Wolf :public Animal {;
public:
	void Add(int xx,int yy);
	Wolf(int xx=0, int yy=0, World* w=NULL, int str=9, int spe=5, int a=0,char m='W',std::string n="Wilk");
	~Wolf();
};
