#include<iostream>
#include<conio.h>
#include<fstream>
#include<Windows.h>
#include"World.h"
int main()
{
	SetConsoleTitleA("Mikolaj Naderza 165337");
	char a;
	std::cout << "Witaj w symulatorze swiata.\nN-nowy swiat\nW-wczytaj zapisany swiat\n";
	a = _getch();
	a=toupper(a);
	while (a != 'W' && a != 'N') {
		system("cls");
		std::cout << "Nacisnij N aby utworzyc nowy swiat, lub W aby wczytac zapisany swiat.\n";
		a = _getch();
		a = toupper(a);
	}
	if(a=='W') {
		FILE* file;
		if (file = fopen("save.txt", "r")) {
			fclose(file);
			World world;
			while (true) {
				if (!world.ExecuteTurn())
					break;
			}
		}
		else a = 'N';
		std::cout << "Brak istniejacego zapisu gry/n";
	}
	if(a=='N'){
		std::cout << "Podaj rozmiary swojego swiata\nWysokosc:";
		int h, w;
		std::cin >> h;
		while (std::cin.fail() || h<=0) {
			std::cout << "Podaj poprawna wartosc liczbowa\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> h;
		}
		std::cout << "Szerokosc:";
		std::cin >> w;
		while (std::cin.fail() || w<=0) {
			std::cout << "Podaj poprawna wartosc liczbowa\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> w;
		}
		if (h > 40) h = 40;
		if (w > 200) w = 200;
		World world(w, h);
		system("cls");
		std::cout << "\nUtworzono swiat. Sterowanie- WASD. Aby wykonac ruch nacisnij klawisz i potwierdz enterem.\nWprowadz dowolny znak aby zaczac gre.\n";
		_getch();
		while (1 == 1) {
			if(!world.ExecuteTurn())
				break;
		}
	}
    return 0;
}

