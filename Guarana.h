#pragma once
#include"Plant.h"
class Guarana :public Plant {
public:
	void Add(int xx, int yy);
	bool Boosted();
	Guarana(int xx = 0, int yy = 0, World* w = NULL, int str = 0, int spe = 0, int a = 0, char m = 'G', std::string n = "Guarana");
	~Guarana();
};

