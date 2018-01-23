#include"Animal.h"
#include<iostream>
#include<ctime>
#include<string>
Animal::~Animal() {};
bool Eaten() {
	return true;
}
std::string Animal::Action(std::string com) {
	int tmpx = x;
	int tmpy = y;
	age++;
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
	com=Collision(tmpx, tmpy, com);
	return com;
}
std::string Animal::Collision(int tmpx, int tmpy, std::string com){
	Organism* enemy = world->GetOrg(tmpx, tmpy);
	if (enemy && enemy!=this)
	{
		if (enemy->Eaten()) {
			if (enemy->Killed(strenght)) {
				com = Comunicate(com);
				com += " zjadl ";
				com = enemy->Comunicate(com);
				com += " i umarl \n";
				world->Kill(enemy);
				world->Kill(this);
			}
			else if (enemy->Boosted()) {
				com = Comunicate(com);
				com += " zjadl ";
				com = enemy->Comunicate(com);
				com += " i otrzymal +3 do sily \n";
				x = tmpx;
				y = tmpy;
				strenght += 3;
				world->Kill(enemy);
			}
			else {
				com = Comunicate(com);
				com += " zjadl ";
				com = enemy->Comunicate(com);
				com += "\n";
				x = tmpx;
				y = tmpy;
				world->Kill(enemy);
			}
		}
		else if (enemy->Resisted(strenght) ) {
			com=enemy->Comunicate(com);
			com+=" odparl atak ";
			com=Comunicate(com);
			com+="\n";
		}
		else if (enemy->Ran()) {
				com=enemy->Comunicate(com);
				com+=" uciekl przed ";
				com=Comunicate(com);
				com+="\n";
			}
		else if (enemy->Multiplied(mark))
		{
			if (can_multiply)
			{
				com = this->Multiply(enemy, com);
				enemy->CantMupliply();
			}
			else can_multiply = true;
		}
		else if (enemy->Died(strenght))
		{
			com=Comunicate(com);
			com+=" zaatakowal i zabil ";
			com= enemy->Comunicate(com);
			com+="\n";
			x = tmpx;
			y = tmpy;
			world->Kill(enemy);
		}
		else if (enemy->Killed(strenght)) {
			{
				com=Comunicate(com);
				com+=" zaatakowal ";
				com=enemy->Comunicate(com);
				com+= " i polegl \n";
				world->Kill(this);
			}
		}
	}
	else {
		x=tmpx;
		y=tmpy;
	}
	return com;
}
Animal::Animal(int xx=0, int yy=0, World* w = NULL, int str=0, int spe=0, int a=0, char m='X', std::string n)
:Organism(xx, yy , w, str, spe, a, m, n){};
