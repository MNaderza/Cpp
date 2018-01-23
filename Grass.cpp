#include"Grass.h"
Grass::~Grass() {};
void Grass::Add(int xx, int yy){
	Organism* tmp = new Grass(xx, yy,world);
	world->Add(tmp);
}
Grass::Grass(int xx, int yy, World* w, int spe, int str, int a, char m, std::string n)
	:Plant(xx, yy, w, str, spe, a, m, n) {
}