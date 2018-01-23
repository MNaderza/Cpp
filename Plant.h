#pragma once
#include"Organism.h"
class Plant :public Organism {
protected:
	std::string Collision(int xx, int yy, std::string com);
public:
	std::string Action(std::string com);
	bool Eaten();
	bool HogweedImmune();
	Plant(int xx, int yy, World* w, int str, int spe, int a, char m, std::string name = "Nieznana roslina");
	~Plant();

};
