#pragma once
#include"Plant.h"
class NightShade :public Plant {
public:
	void Add(int xx, int yy);
	bool Killed(int s);
	NightShade(int xx = 0, int yy = 0, World* w = NULL, int str = 99, int spe = 0, int a = 0, char m = 'J', std::string n = "Wilcza jagoda");
	~NightShade();

};

