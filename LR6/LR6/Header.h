#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include<numeric>
#include<functional>
#include <list>
#include <map>

using namespace std;

float random() { return (-5.0 + rand() % 15) / 100; }
void show(float x) { cout << x << " "; }

class CCity
{
private:
	int population;
	float square;
	string name;
	bool airport;
public:
	CCity() { population = 800; square = 500.25; name = "Тюмень"; airport = true; }
	CCity(int VPopulation, float VSquare, string VName, bool VAirport)
	{
		population = VPopulation;
		square = VSquare;
		name = VName;
		airport = VAirport;
	}

	float getPopDen() { return (float)(population) / square; }
	int getPopulation() { return population; }
	float getSquare() { return square; }
	string getName() { return name; }
	bool getAirport() { return airport; }

	string info()
	{
		return "Город " + name + ", площадь " + to_string(square) + ", население "
			+ to_string(population) + ", аэропорт " + to_string(airport);
	}

	void SetCCity(int pop) { population = pop; }
	void SetCCity(int pop, float sqr) { population = pop; square = sqr; }
	void SetCCity(int pop, float sqr, bool airp) { population = pop; square = sqr; airport = airp; }
	void SetCCity(int pop, float sqr, bool airp, string nm) { population = pop; square = sqr; name = nm; airport = airp; }

	bool operator == (string nm) { return name == nm ? 1 : 0; }

	~CCity() {};
};

int prompt_menu_item()
{
	int variant;
	cout << "Меню\n" << endl;
	cout << "1. Добавить город\n "
		<< "2. Посмотреть список городов\n"
		<< "3. Посмотреть плотность населения\n"
		<< "4. Изменить население города\n"
		<< "5. Изменить население и площадь города\n"
		<< "6. Изменить население, площадь и статус города\n"
		<< "7. Посмотреть количество городов\n"
		<< "0. Выйти\n"
		<< endl << endl;
	cout << ">>> ";
	cin >> variant;
	return variant;
}

void showCity(CCity c) { cout << c.info() << endl; }



class BusStation
{
public:
	int route;
	string city;
	float time;
public:
	BusStation() { route = 1; city = "Moscow"; time = 9.05; };
	BusStation(string ct, int rt, float t) { route = rt; city = ct; time = t; };
	~BusStation() {};

	void setRoute(int r) { route = r; };
	void setCity(string c) { city = c; };
	void setTime(float t) { time = t; };

	int getRoute() { return route; };
	string getCity() { return city; };
	float getTime() { return time; };

	bool operator == (int rt) { return route == rt ? 1 : 0; }

	BusStation& operator = (BusStation obj)
	{
		route = obj.route;
		city = obj.city;
		time = obj.time;
		return *this;
	};

	void Info(BusStation obj)
	{
		cout << " Маршрут " << obj.route << endl <<
			" Город назначения: " << obj.city << endl <<
			" Время отправления " << obj.time << endl << endl;
	}
};

void getInfo(float key, BusStation obj)
{
	cout << " Маршрут " << key << endl <<
		" Город назначения: " << obj.city << endl <<
		" Время отправления " << obj.time << endl << endl;
};

BusStation createBusStation(int r)
{
	string city;
	float time;

	cout << "Введите название города: ";
	cin >> city;
	cout << "Введите время отправления: ";
	cin >> time;
	cout << endl;

	BusStation BS(city, r, time);
	return BS;
}
