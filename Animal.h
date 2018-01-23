#pragma once
#include"Organism.h"
class Animal:public Organism {
protected:
	std::string Collision(int xx, int yy, std::string com);
public:
	std::string Action(std::string com);
	Animal(int xx, int yy, World* w, int str, int spe, int a, char m, std::string n = "Nieznane zwierze");
	~Animal();
};
