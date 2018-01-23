#include"Sheep.h"
Sheep::~Sheep() {};
Sheep::Sheep(int xx, int yy, World* w, int str, int spe, int a,char m, std::string n)
	:Animal(xx, yy, w,str, spe, a, m, n) {
};
void Sheep::Add(int xx, int yy) {
	Organism* tmp = new Sheep(xx, yy, world);
	world->Add(tmp);
}