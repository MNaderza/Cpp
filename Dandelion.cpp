#include"Dandelion.h"
#include<string>
Dandelion::~Dandelion() {};
void Dandelion::Add(int xx, int yy) {
	Organism* tmp = new Dandelion(xx, yy,world);
	world->Add(tmp);
}
std::string Dandelion::Action(std::string com) {
	for (int i = 0; i < 3; i++) {
		com = Plant::Action(com);
		}
	return com;
}
Dandelion::Dandelion(int xx, int yy, World* w, int spe, int str, int a, char m, std::string n)
	:Plant(xx, yy, w, str, spe, a, m, n) {
}