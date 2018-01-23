#pragma once
#include<iostream>
#include"Plant.h"
class Hogweed :public Plant {
public:
	void Add(int xx, int yy);
	bool Killed(int s);
	std::string Action(std::string com);
	Hogweed(int xx = 0, int yy = 0, World* w = NULL, int str = 10, int spe = 0, int a = 0, char m = 'B', std::string n = "Barszcz sosnowskiego");
	~Hogweed();
};