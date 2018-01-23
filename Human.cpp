#include"Human.h"
#include<string>
#include<conio.h>
Human::~Human() {};
std::string Human::Action(std::string com) {
	int a;
	int tmpx = x;
	int tmpy = y;
	age++;
	system("cls");
	com += "Twoj ruch. Poruszaj sie strzalkami. Aktywuj umiejetnosc specjalna klawiszem T.\n";
	com = world->Print(com);
	a=_getch();
	a = toupper(a);
	if (a == int('T')) {
		if (SkillUsable) {
			SkillCounter = 5;
			SkillUsable = false;
			std::cout<<"Aktywowano umiejenosc specjalna\n";
		}
		else if (SkillCounter > 0)
		{
			std::cout << "Umiejetnosc specjalna jest juz aktywna\n";
		}
		else if (SkillCounter <= 0) {
			std::cout<<"Umiejetnosc specjalna nie moze zostac uruchomiona przez "<< std::to_string(-5 - SkillCounter)<< " tury\n";
		}
		a = _getch();
	}
	if (a==224) {
		if (SkillCounter > 2 || (SkillCounter > 0 && rand() % 2 == 0)) {
			switch (a=_getch()) {
			case 72: tmpy -= 2; break;
			case 80: tmpy += 2; break;
			case 75: tmpx -= 2; break;
			case 77: tmpx += 2; break;
			}
			a = 0;
		}
		else {
			switch (a=_getch()) {
			case 72: tmpy--; break;
			case 80: tmpy++; break;
			case 75: tmpx--; break;
			case 77: tmpx++; break;
			}
			a = 0;
		}
		if (!SkillUsable)
		{
			SkillCounter--;
			if (SkillCounter == -5) {
				SkillUsable = true;
			}
		}
	}
	if (tmpx >= 0 && tmpy >= 0 && tmpx < world->GetWidth() && tmpy < world->GetHeight()) {
		com = Collision(tmpx, tmpy, com);
	}
	return com;
}
void Human::Add(int xx,int yy)
{};
int Human::GetSkillUsable() {
	if (SkillUsable)
		return 1;
	return 0;
}
int Human::GetSkillCounter() {
	return SkillCounter;
}
Human::Human(int xx, int yy, World* w, int str, int spe, int a, char m, bool SU, int SC, std::string n)
	:Animal(xx, yy, w, str, spe, a, m) {
	name = n;
	SkillCounter = SC;
	SkillUsable = SU;
	}
