#include"Guarana.h"
Guarana::~Guarana() {};
void Guarana::Add(int xx, int yy) {
	Organism* tmp = new Guarana(xx, yy, world);
	world->Add(tmp);
}
bool Guarana::Boosted() {
	return true;
}
Guarana::Guarana(int xx, int yy, World* w, int spe, int str, int a, char m, std::string n)
	:Plant(xx, yy, w, str, spe, a, m, n) {
}