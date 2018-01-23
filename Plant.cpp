#include"Plant.h"
#include<string>
Plant::~Plant() {};
Plant::Plant(int xx = 0, int yy = 0, World* w = NULL, int str = 0, int spe = 0, int a = 0, char m = 'X', std::string n)
	:Organism(xx, yy, w, str, spe, a, m, n) {};
std::string Plant::Action(std::string com) {
	int n = rand() % 8;
	if (n == 0) {
		xy tmp = GetFree();
		if (tmp.xx != -1) {
			Add(tmp.xx, tmp.yy);
			com=Comunicate(com);
			com += " rozprzestrzenil(a) sie na " + std::to_string(tmp.xx) + " " + std::to_string(tmp.yy) + "\n";
		}
	}
	return com;
}
bool Plant::Eaten() {
	return true;
}
bool Plant::HogweedImmune() {
	return true;
}
std::string Plant::Collision(int xx, int yy, std::string com) { return com; }