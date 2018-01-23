#pragma once
#include"Plant.h"
class Dandelion :public Plant {
public:
	void Add(int xx, int yy);
	std::string Action(std::string com);
	Dandelion(int xx = 0, int yy = 0, World* w = NULL, int str = 0, int spe = 0, int a = 0, char m = 'M', std::string n = "Mlecz");
	~Dandelion();
};
