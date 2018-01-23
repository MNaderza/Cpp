#include"Foxx.h"
Foxx::~Foxx() {};
Foxx::Foxx(int xx, int yy, World* w, int str, int spe, int a, char m, std::string n)
	:Animal(xx, yy, w, str, spe, a, m, n) {
};
void Foxx::Add(int xx, int yy) {
	Organism* tmp = new Foxx(xx, yy, world);
	world->Add(tmp);
}
std::string Foxx::Action(std::string com) {
	int tmpx = x;
	int tmpy = y;
	int tab[9][2];
	int counter = 0;
	age++;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (i == 0 && j == 0)
				continue;
			else if (x + i < world->GetWidth() && x + i > 0 && y + j < world->GetHeight() && y + j > 0) {
				Organism* tmp = world->GetOrg(x + i, y + j);
				if(tmp){
					if (tmp->GetStrenght() <= strenght) {
						tab[counter][0] = i;
						tab[counter][1] = j;
						counter++;
					}
				}
				else {
					tab[counter][0] = i;
					tab[counter][1] = j;
					counter++;
				}
			}
		}
	}
	if (counter > 0) {
		int n = rand() % counter;
		tmpx += tab[n][0];
		tmpy += tab[n][1];
	}
	com = Collision(tmpx, tmpy, com);
	return com;
}