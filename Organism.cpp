#include<iostream>
#include<string>
#include"Organism.h"
Organism::~Organism() {};
int Organism::GetSpeed()
{
	return speed;
}
int Organism::GetStrenght()
{
	return strenght;
}
std::string Organism::Comunicate(std::string com) {
	com +=name + " " + std::to_string(x) + " " + std::to_string(y);
	return com;
}
bool Organism::Eaten() {
	return false;
}
bool Organism::HogweedImmune() {
	return false;
}
bool Organism::Boosted() {
	return false;
}
xy Organism::GetFree() {
	int tmpx = x;
	int tmpy = y;
	int counter = 0;
	int places[9][2];
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			if (!(tmpx + i < 0) && !(tmpx + i >= world->GetWidth()) && !(tmpy + j < 0) && !(tmpy + j >= world->GetHeight()))
			{
				if (!world->GetOrg(tmpx + i, tmpy + j))
				{
					places[counter][0] = i;
					places[counter][1] = j;
					counter++;
				}
			}
		}
	}
	xy tmp_struct = { -1,-1 };
	if (counter > 0) {
		int tmp = rand() % counter;
		tmpx += places[tmp][0];
		tmpy += places[tmp][1];
		tmp_struct.xx = tmpx;
		tmp_struct.yy = tmpy;
	}
	return tmp_struct;
	
}
void Organism::CantMupliply() {
		can_multiply = false;
}
std::string Organism::Multiply(Organism* tmpo,std::string com) {
		xy tmp = GetFree();
		if (tmp.xx != -1) {
			Add(tmp.xx, tmp.yy);
			com=Comunicate(com);
			com+=" rozmnozyl sie z ";
			com=tmpo->Comunicate(com);
			com+="\n";
		}
		return com;
}
int Organism::GetSkillCounter() {
	return 0;
}
int Organism::GetSkillUsable() {
	return 0;
}
int Organism::GetX()
{
	return x;
}
int Organism::GetY()
{
	return y;
}
int Organism::GetAge() {
	return age;
}
char Organism::GetMark() {
	return mark;
}
bool Organism::Multiplied(char m) {
	if (mark == m) {
		can_multiply = false;
		return true;
	}
	else return false;
}
bool Organism::Killed(int s) {
	if (s < strenght)
		return true;
	else
		return false;
}
bool Organism::Ran() {
	return false;
}
bool Organism::Died(int s) {
	if (s >= strenght)
		return true;
	else return false;
}
bool Organism::Resisted(int s) {
	return false;
}

Organism::Organism(int xx = 0, int yy = 0, World* w = NULL, int str = 0, int spe = 0,int a=0,char m='X', std::string n) {
	x = xx;
	y = yy;
	speed = spe;
	strenght = str;
	age = a;
	world = w;
	mark = m;
	name = n;
}