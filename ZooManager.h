#pragma once
#include "Cage.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <map>

using namespace std;

class ZooManager
{
	Warehouse warehouse;
	vector<Cage> cages;
	map<string, string> info;

public:
	int money;

	ZooManager()
	{
		money = 1000;

		info["Lion"] = "meat";
		info["Tiger"] = "meat";
		info["Cow"] = "hay";
		info["Sheep"] = "hay";
		info["Elefant"] = "hay";
		info["Monkey"] = "fruit";
		info["Parrot"] = "grain";
	}

	void populateAnimals(int N)
	{
		int typeAnimal, countOfAnimal;
		srand(time(0));

		for (int i = 0; i < N; i++) {
			typeAnimal = 1 + rand() % 7;
			countOfAnimal = 1 + rand() % 21;
			cages.push_back(Cage(typeAnimal, countOfAnimal));
		}
	}

	Cage infoAboutCage(int nCage)
	{
		return cages[nCage];
	}

	string getFoodType(string name) 
	{
		return info[name];
	}

	string getInfoWarehouse()
	{
		return "meat: " + warehouse.getCountSpecificFood("meat") + ",\thay: " + warehouse.getCountSpecificFood("hay") +
			",\tfruit: " + warehouse.getCountSpecificFood("fruit") + ",\tgrain: " + warehouse.getCountSpecificFood("grain") + ".";
	}

	void sellAnimal(string typeAnimal, int countAnimal, int nCage)
	{

	}

	void buyFood(string typeFood, int countFood)
	{

	}

	string feedingAndBreeding()
	{
		string result = "";
		for (int i = 0; i < cages.size(); i++) {
			Cage cage = cages[i];
			int deathWithoutFood = 0, deathFromOldAge = 0, spawned = 0, count;
			string typeFood, name;
			cage.getAnimalInfo(name, count);
			typeFood = info[name];
			cage.actionWithAnimal(deathWithoutFood, deathFromOldAge, spawned, typeFood);
			count = i++;
			if (deathWithoutFood != 0) {
				result += to_string(deathWithoutFood) + " " + name + "starved to death in Enclosure " + to_string(count) + ".\n";
			}
			if (deathFromOldAge != 0) {
				result += to_string(deathFromOldAge) + " " + name + "died of old age in Enclosure " + to_string(count) + ".\n";
			}
			if (spawned != 0) {
				result += to_string(spawned) + " " + name + "spawned in Enclosure " + to_string(count) + ".\n";
			}
			if (i < cages.size() - 1) {
				result += "\n";
			}
			cage.clearCage();
			cages[i] = cage;
		}
		return result;
	}

	string moveToWarehouse(string typeFood, int countFood, int nCage)
	{
		Cage cage = infoAboutCage(nCage - 1);
		string result;

		if (cage.takeFoodFromC(typeFood, countFood)) {
			warehouse.addFoodToW(typeFood, countFood);
			cages[nCage - 1] = cage;
			result = "success";
		}
		else {
			result = "Not enough \"" + typeFood + "\" or don't exist this type of food.";
		}
		return result;
	}

	string moveToCage(string typeFood, int countFood, int nCage)
	{
		Cage cage = infoAboutCage(nCage - 1);
		string result;

		if (warehouse.takeFoodFromW(typeFood, countFood)) {
			cage.addFoodtoC(typeFood, countFood);
			cages[nCage - 1] = cage;
			result = "success";
		}
		else {
			result = "Not enough \"" + typeFood + "\" or don't exist this type of food.";
		}
		return result;
	}

	string moveToCage(string typeFood, int countFood, int nCage, int nSecondCage)
	{
		Cage cage1 = infoAboutCage(nCage - 1);
		Cage cage2 = infoAboutCage(nSecondCage - 1);
		string result;

		if (cage1.takeFoodFromC(typeFood, countFood)) {
			cage2.addFoodtoC(typeFood, countFood);
			cages[nCage - 1] = cage1;
			cages[nSecondCage - 1] = cage2;
			result = "success";
		}
		else {
			result = "Not enough \"" + typeFood + "\" or don't exist this type of food.";
		}
		return result;
	}
};