#include"NightShade.h"
NightShade::~NightShade() {};
void NightShade::Add(int xx, int yy) {
	Organism* tmp = new NightShade(xx, yy, world);
	world->Add(tmp);
}
bool NightShade::Killed(int s) {
	return true;
}
NightShade::NightShade(int xx, int yy, World* w, int str, int spe, int a, char m, std::string n)
	:Plant(xx, yy, w, str, spe, a, m, n) {
}