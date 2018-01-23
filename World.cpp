#include<list>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<conio.h>
#include"World.h"
#include"Animal.h"
#include"Plant.h"
#include"Wolf.h"
#include"Sheep.h"
#include"Human.h"
#include"Antilope.h"
#include"Turtle.h"
#include"Grass.h"
#include"Dandelion.h"
#include"NightShade.h"
#include"Guarana.h"
#include"Hogweed.h"
#include"Foxx.h"
#define WHITE 219

World::World(int w=20,int h=20) {
	map = new Organism*[w*h];
	for (int i = 0; i < w*h; i++)
		map[i] = NULL;
	width = w;
	height = h;
	Organism* tmp=new Human(rand()% width, rand()% height, this);
	Add(tmp);
	srand(time(NULL));
	for (int i = 0; i < w*h/15; i++)
	{
		int x = rand() % width;
		int y = rand() % height;
		while (GetOrg(x, y)) {
			x = rand() % width;
			y = rand() % height;
		}
		int s = rand() % 10;
		switch (s) {
		case 3: tmp = new Sheep(x, y, this); break;
		case 0: tmp = new Wolf(x, y, this); break;
		case 2: tmp = new Turtle(x, y, this); break;
		case 1: tmp = new Antilope(x, y, this); break;
		case 5: tmp = new Grass(x, y, this); break;
		case 4: tmp = new Dandelion(x, y, this); break;
		case 6: tmp = new Guarana(x, y, this); break;
		case 7: tmp = new NightShade(x, y, this); break;
		case 8: tmp = new Hogweed(x, y, this); break;
		case 9: tmp = new Foxx(x, y, this); break;
		}
		Add(tmp);
	}
	Sort();
	ListToMap();
}
World::~World() {
	delete[] map;
};
void World::Kill(Organism* tmp) {
	int i = Find(tmp);
	if (i != -1)
		OrgList.erase(OrgList.begin() + i);
}
void World::Save() {
	FILE* file;
	fopen_s(&file,"save.txt", "w+");
	fprintf(file,"%d %d\n", width, height);
	fprintf(file,"%d", OrgList.size());
	for (std::size_t i = 0; i < OrgList.size(); i++) {
		fprintf(file,"\n%d %d %d %d %d %c", OrgList[i]->GetX(), OrgList[i]->GetY(), OrgList[i]->GetStrenght(), OrgList[i]->GetSpeed(), OrgList[i]->GetAge(), OrgList[i]->GetMark());
		if (OrgList[i]->GetMark() == 'C') {
			fprintf(file, "%d %d", OrgList[i]->GetSkillUsable(), OrgList[i]->GetSkillCounter());
		}
	}
	fclose(file);
}
World::World() {
	FILE *file;
	if (file = fopen("save.txt", "r")) {
		int w, h, n;
		fscanf_s(file,"%d %d\n", &w, &h);
		fscanf_s(file,"%d", &n);
		map = new Organism*[w*h];
		width = w;
		height = h;
		for (int i = 0; i < w*h; i++) {
			map[i] = NULL;
		}
		for (int i = 0; i < n; i++) {
			int xx, yy, spe, str, a,bol,count;
			char m;
			bool usable;
			Organism* tmp;
			fscanf_s(file,"\n%d %d %d %d %d %c", &xx, &yy, &str, &spe, &a, &m);
			if (m == 'C') {
				fscanf_s(file, " %d %d", &bol, &count);
				usable = bol;
			}
			switch (m) {
			case 'O':tmp = new Sheep(xx, yy, this, str, spe, a); break;
			case 'A':tmp = new Antilope(xx, yy, this, str, spe, a); break;
			case 'W':tmp = new Wolf(xx, yy, this, str, spe, a); break;
			case 'Z':tmp = new Turtle(xx, yy, this, str, spe, a); break;
			case 'L':tmp = new Foxx(xx, yy, this, str, spe, a); break;
			case 'T':tmp = new Grass(xx, yy, this, str, spe, a); break;
			case 'M':tmp = new Dandelion(xx, yy, this, str, spe, a); break;
			case 'G':tmp = new Guarana(xx, yy, this, str, spe, a); break;
			case 'B':tmp = new Hogweed(xx, yy, this, str, spe, a); break;
			case 'J':tmp = new NightShade(xx, yy, this, str, spe, a); break;
			case 'C':tmp = new Human(xx, yy, this, str, spe, a, m, usable, count); break;
			}
			OrgList.push_back(tmp);
		}
		fclose(file);
	}
}
int World::Find(Organism* tmp) {
	for (std::size_t i = 0; i < OrgList.size(); i++) {
		if (tmp == OrgList[i]) {
			return i;
		}
	}
	return -1;
}
Organism* World::GetOrg(int xx,int yy) {
	for (std::size_t i = 0; i < OrgList.size(); i++) {
		if (OrgList[i]->GetX() == xx && OrgList[i]->GetY() == yy) {
			return OrgList[i];
		}
	}
	return NULL;

}
int World::GetWidth() {
	return width;
}
int World::GetHeight() {
	return height;
}
bool HelpSort(Organism* a, Organism* b){
	if ( (a->GetSpeed() > b->GetSpeed()) || ( a->GetSpeed() == b->GetSpeed() && a->GetAge() > b->GetAge() ) )
		return true;
	else return false;
}
void World::Sort() {
	for (std::size_t i = 0; i < OrgList.size(); i++) {
		int min = i;
		for (std::size_t j = i+1; j < OrgList.size(); j++) {
			if ((OrgList[j]->GetSpeed() > OrgList[min]->GetSpeed()) || (OrgList[j]->GetSpeed() == OrgList[min]->GetSpeed() && OrgList[j]->GetAge() > OrgList[min]->GetAge())) {
				min = j;
				Organism* tmp = OrgList[i];
				OrgList[i] = OrgList[min];
				OrgList[min] = tmp;
			}
		
		}
	}
}
void World::Add(Organism* tmp) {
	OrgList.push_back(tmp);
}
std::string World::Print(std::string com) {
	for (int i = -1; i <height; i++)
	{
		if (i == -1) {
			for (int j = 0; j < width + 2; j++) {
				std::cout << char(WHITE);
			}
			std::cout << "\n";
			continue;
		}
		std::cout << char(WHITE);
		for (int j = 0; j < width; j++) {
			if (!map[i*width+j])
				std::cout << " ";
			else std::cout << map[i*width+j]->GetMark();
		}
		std::cout << char(WHITE);
		std::cout << "\n";
		if (i == height-1) {
			for (int j = 0; j < width + 2; j++) {
				std::cout << char(WHITE);
			}
		}

	}
	std::cout<<"\n"<<com;
	com = "";
	return com;
}
bool World::ExecuteTurn() {
	int end = OrgList.size();
		for (std::size_t i=0; i<OrgList.size(); i++)
		{
			com=OrgList[i]->Action(com);
			ListToMap();
		}
		system("cls");
		com += "Koniec tury, wprowadz dowolny przycisk (S-Zapisanie stanu swiata, Q-opusczenie symulacji)\n";
		com=Print(com);
		int a;
		a = _getch();
		a = toupper(a);
		if (a == int('S')) {
			this->Save();
			std::cout << "Zapisano stan swiata\n";
			a = _getch();
			a = toupper(a);
		}
		if (a == int('Q')) {
			return false;
		}
		if (a == 224) {
			a=_getch();
		}
		Sort();
		return true;
}

void World::ListToMap() {
	for (int i = 0; i < height*width; i++) {
		map[i] = NULL;
	}
	for (std::size_t i = 0; i<OrgList.size();i++) {
		int tmp = OrgList[i]->GetX() + OrgList[i]->GetY()*width;
		map[tmp] = OrgList[i];
		}
}

