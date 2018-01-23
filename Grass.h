#pragma once
#include"Plant.h"
class Grass :public Plant {
public:
	void Add(int xx, int yy);
	Grass(int xx = 0, int yy = 0, World* w = NULL, int str = 0, int spe = 0, int a = 0, char m = 'T', std::string n = "Trawa");
	~Grass();

};
