#include"Hogweed.h"
#include<string>
Hogweed::~Hogweed() {};
void Hogweed::Add(int xx, int yy) {
	Organism* tmp = new Hogweed(xx, yy, world);
	world->Add(tmp);
}
bool Hogweed::Killed(int s) {
	return true;
}
std::string Hogweed::Action(std::string com) {
	int n = rand() % 8;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (i == 0 && j == 0)
				continue;
			else if (x + i < world->GetWidth() && x + i > 0 && y + j < world->GetHeight() && y + j > 0) {
				Organism* tmp = world->GetOrg(x + i, y + j);
				if (tmp) {
					if (!(tmp->HogweedImmune())) {
						com = Comunicate(com);
						com += " zabil ";
						com = tmp->Comunicate(com);
						com += "\n";
						world->Kill(tmp);
					}
				}
			}
		}
	}
	if (n == 0) {
		xy tmp = GetFree();
		if (tmp.xx != -1) {
			Add(tmp.xx, tmp.yy);
			com = Comunicate(com);
			com += " rozprzestrzenil(a) sie na " + std::to_string(tmp.xx) + " " + std::to_string(tmp.yy) + "\n";
		}
	}
	return com;
}
Hogweed::Hogweed(int xx, int yy, World* w, int str, int spe, int a, char m, std::string n)
	:Plant(xx, yy, w, str, spe, a, m, n) {
}