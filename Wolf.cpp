#include"Wolf.h"
Wolf::Wolf(int xx, int yy, World* w, int str, int spe, int a,char m, std::string n)
	:Animal(xx, yy, w, str, spe, a, m, n) {
};
Wolf::~Wolf() {};
void Wolf::Add(int xx,int yy) {
	Organism* tmp = new Wolf(xx, yy, world);
	world->Add(tmp);
}