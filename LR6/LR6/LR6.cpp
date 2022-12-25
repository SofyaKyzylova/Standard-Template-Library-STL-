// LR6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include<numeric>
#include<functional>
#include <list>
#include <map>
#include "Header.h"

using namespace std;

list<CCity> CityList;

typedef map <float, BusStation, less <float>> map1;


int main()
{
	setlocale(LC_ALL, "Russian");

	//ЗАДАНИЕ 1
	int n;
	cout << "Введите количество элементов: "; 
	cin >> n;
	vector<float> a(n);
	
	srand(time(0));
	generate(a.begin(), a.end(), random);
	cout.precision(3);
	for_each(a.begin(), a.end(), show); 
	cout << endl;

	//a. используя сортировку набора, определить значение второго максимума
	sort(a.begin(), a.end());
	for_each(a.begin(), a.end(), show);
	cout << endl;
	cout << "Максимальный элемент = " << * max_element(a.begin(), a.end() - 1) << endl;

	//b. сумму модулей элементов, расположенных после первого нулевого элемента
	float sum = 0;
	vector<float>::iterator it = find(a.begin(), a.end(), 0);
	if (it == a.end())
		cout << "Нулевых элементов нет. Невозможно посчитать сумму" << endl;
	else
		cout << "Сумма элементов после первого 0 = " << accumulate(it + 1, a.end(), sum) << endl;

	//c. сжать массив, удалив из него все одинаковые элементы, оставив их первые вхождения. 
	//   Освободившиеся в конце элементы заполнить нулями.
	cout << "Удаление одинаковых вхождений: " << endl;
	auto last = unique(a.begin(), a.end());
	a.erase(last, a.end());
	a.resize(n, 0);
	for_each(a.begin(), a.end(), show);
	cout << endl << endl << endl;

	

	//ЗАДАНИЕ 2
	int variant = -1;
	while (variant != 0) 
	{
		variant = prompt_menu_item();
		switch (variant) 
		{
		case 0:
			cout << "Выход..." << endl;
			break;
		case 1:
		{
			string name;
			int pop;
			float square;
			bool airp;
			cout << "Введите название города: ";
			cin >> name;
			cout << "Введите население города: ";
			cin >> pop;
			cout << "Введите площадь города: ";
			cin >> square;
			cout << "Наличие аэропорта (0/1): ";
			cin >> airp;
			CityList.push_back(CCity(pop,square, name, airp));
			break;
		}
		case 2: 
		{
			for_each(CityList.begin(), CityList.end(), showCity);
			cout << endl;
			break;
		}
		case 3: 
		{
			string name;
			cout << "Введите название города: ";
			cin >> name;
			list<CCity>::iterator it = find(CityList.begin(), CityList.end(), name);
			cout << "Плотность населения:  " << it->getPopDen() << endl << endl;
			break;
		}
		case 4:
		{
			int pop;
			string name;
			cout << "Введите название города для изменения населения: ";
			cin >> name;
			list<CCity>::iterator it = find(CityList.begin(), CityList.end(), name);
			cout << "Введите население: ";
			cin >> pop;
			it->SetCCity(pop);
			cout << "Измененный город: " << it->info() << endl << endl;
			break;
		}
		case 5:
		{
			int pop;
			float sqr;
			string name;
			cout << "Введите название города для изменения населения и площади: ";
			cin >> name;
			list<CCity>::iterator it = find(CityList.begin(), CityList.end(), name);
			cout << "Введите население: ";
			cin >> pop;
			cout << "Введите площадь: ";
			cin >> sqr;
			it->SetCCity(pop, sqr);
			cout << "Измененный город: " << it->info() << endl << endl;
			break;
		}
		case 6:
		{
			int pop;
			float sqr;
			string name;
			bool airp;
			cout << "Введите название города для изменения населения, площади и статуса: ";
			cin >> name;
			list<CCity>::iterator it = find(CityList.begin(), CityList.end(), name);
			cout << "Введите население: ";
			cin >> pop;
			cout << "Введите площадь: ";
			cin >> sqr;
			cout << "Наличие аэропорта (0/1): ";
			cin >> airp;
			it->SetCCity(pop, sqr, airp);
			cout << "Измененный город: " << it->info() << endl << endl;
			break;
		}
		case 7:
		{
			cout << "Количество городов в списке: " << CityList.size() << endl << endl;
			break;
		}
		default:
			cerr << "Вы выбрали неверный номер" << endl;
		}
	}
	cout << endl << endl;


	//ЗАДАНИЕ 3
	BusStation bus1("Samara", 101, 8.05);
	BusStation bus2("Rostov", 352, 8.50);
	BusStation bus3("Omsk", 136, 9.45);
	BusStation bus4("Perm", 441, 11.15);
	BusStation bus5("Omsk", 575, 13.25);

	map1 bus;
	bus[101] = bus1;
	bus[352] = bus2;
	bus[136] = bus3;
	bus[441] = bus4;
	bus[575] = bus5;

	map1::iterator i;

	cout << "Список автобусов:" << endl;
	for (i = bus.begin(); i != bus.end(); i++)
		getInfo((*i).first, (*i).second);

	int r;
	cout << "Введите номер маршрута: ";
	cin >> r;
	bus[r] = createBusStation(r);
	
	cout << "Список автобусов:" << endl;
	for (i = bus.begin(); i != bus.end(); i++)
		getInfo((*i).first, (*i).second);

	int id;
	cout << "Какой атобус вы хотите удалить? Введите номер маршрута: ";
	cin >> id;
	bus.erase(id);

	cout << "Список автобусов:" << endl;
	for (i = bus.begin(); i != bus.end(); i++)
		getInfo((*i).first, (*i).second);
	
	int rt;
	cout << "Какой атобус вы хотите найти? Введите номер маршрута: ";
	cin >> rt;
	bus[rt].Info(bus[rt]);
	
	string c;
	cout << "Какие маршруты вы хотите найти? Введите название города: ";
	cin >> c;
	map1::iterator e = find_if(bus.begin(), bus.end(), [bus, &c](pair<const float, BusStation> q) {return q.second.city == c; });
	getInfo((*e).first, (*e).second);
}
