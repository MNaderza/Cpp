#pragma once
#include"Animal.h"
class Human :public Animal {
private:
	int SkillCounter;
	bool SkillUsable;
public:
	std::string Action(std::string com);
	void Add(int xx, int yy);
	int GetSkillUsable();
	int GetSkillCounter();
	Human::Human(int xx = 0, int yy = 0, World* w = NULL, int str = 5, int spe = 4, int a = 0, char m = 'C', bool SU = true, int SC = 0, std::string n = "Czlowiek");
	~Human();
};
