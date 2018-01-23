#include"Turtle.h"
Turtle::Turtle(int xx, int yy, World* w, int str, int spe, int a, char m, std::string n)
	:Animal(xx, yy, w, str, spe, a, m, n) {
};
Turtle::~Turtle() {};
void Turtle::Add(int xx, int yy) {
	Organism* tmp = new Turtle(xx, yy, world);
	world->Add(tmp);
}
bool Turtle::Resisted(int s) {
	if (s < 5)
		return true;
	else return false;
}
std::string Turtle::Action(std::string com) {
	int move = rand() % 4;
	if (move == 0) {
		com=Animal::Action(com);
	}
	return com;
}