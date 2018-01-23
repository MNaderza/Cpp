#include"Antilope.h"
Antilope::~Antilope() {};
Antilope::Antilope(int xx, int yy, World* w, int str, int spe, int a, char m, std::string n)
	:Animal(xx, yy, w, str, spe, a, m,n) {
};
void Antilope::Add(int xx, int yy) {
	Organism* tmp = new Antilope(xx, yy, world);
	world->Add(tmp);
}
bool Antilope::Ran() {
	int n = rand() % 2;
	if (n == 0) {
		xy tmp=GetFree();
		if (tmp.xx != -1) {
			x = tmp.xx;
			y = tmp.yy;
			return true;
		}
	}
	return false;
}
std::string Antilope::Action(std::string com) {
	int tmpx = x;
	int tmpy = y;
	age++;
	for (int i = 0; i < 2; i++) {
		int tmp = rand() % 3;
		switch (tmp) {
		case 0: break;
		case 1:
			if (x < world->GetWidth() - 1)
				tmpx++;
			break;
		case 2:
			if (x > 0)
				tmpx--;
			break;
		}
		tmp = rand() % 3;
		switch (tmp) {
		case 0: break;
		case 1:
			if (y < world->GetHeight() - 1)
				tmpy++;
			break;
		case 2:
			if (y > 0)
				tmpy--;
			break;
		}
	}
	com=Collision(tmpx, tmpy,com);
	return com;
}