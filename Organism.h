#pragma once
#include<iostream>
#include"World.h"
struct  xy
{
	int xx;
	int yy;
};
class Organism {
protected:
	int x, y, speed, strenght,age;
	std::string name;
	World* world;
	char mark;
	bool can_multiply = true;
	virtual std::string Collision(int xx, int yy, std::string com) = 0;
	virtual xy GetFree();
	virtual std::string Multiply(Organism* tmp, std::string com);
	virtual void Add(int xx, int yy) = 0;
public:
	virtual void CantMupliply();
	virtual int GetAge();
	virtual char GetMark();
	virtual int GetX();
	virtual int GetY();
	virtual int GetSpeed();
	virtual int GetStrenght();
	virtual std::string Action(std::string com)=0;
	virtual int GetSkillUsable();
	virtual int GetSkillCounter();
	virtual bool Ran();
	virtual bool Eaten();
	virtual bool HogweedImmune();
	virtual bool Boosted();
	virtual std::string Comunicate(std::string com);
	virtual bool Resisted(int s);
	virtual bool Multiplied(char m);
	virtual bool Killed(int s);
	virtual bool Died(int s);
	Organism(int xx, int yy, World* w, int str, int spe,int a,char m,std::string n= "Nieznany organizm");
	~Organism();
};
