#pragma once
#include<vector>
class Organism;
class World {
private:
	std::vector<Organism*> OrgList;
	Organism **map;
	std::string com = "";
	int width,height;
	void Save();
	int Find(Organism* tmp);
	void Sort();
	void ListToMap();
public:
	std::string Print(std::string com);
	void Add(Organism* tmp);
	void Kill(Organism* tmp);
	Organism* GetOrg(int x, int y);
	int GetHeight();
	int GetWidth();
	bool ExecuteTurn();
	World(int w,int h);
	World();
	~World();
};