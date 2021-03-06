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

	string getFoodInCage(int nCage)
	{
		string food = "";
		vector<Food> foodInCage = cages[nCage].getFoodInCage();
		if (foodInCage.size() == 1) {
			food += to_string(foodInCage[0].count) + " " + foodInCage[0].type;
		}
		else if (foodInCage.size() > 1) {
			for (int i = 0; i < foodInCage.size(); i++) {
				food += to_string(foodInCage[i].count) + " " + foodInCage[i].type + ", ";
			}
			food.erase(food.size() - 2); // delete 2 last symbols ("," and " ")
		}
		else {
			food = "no";
		}
		return food;
	}

	void infoAboutCage(int nCage, string &nameAnimal, int &countAnimal, string &foodInCage)
	{
		nameAnimal = cages[nCage].getNameAnimal();
		countAnimal = cages[nCage].getCountAnimal();
		foodInCage = getFoodInCage(nCage);
	}

	string getFoodType(string name) 
	{
		return info[name];
	}

	string getInfoWarehouse()
	{
		return "meat: " + to_string(warehouse.getCountSpecificFood("meat")) + ",\thay: " + to_string(warehouse.getCountSpecificFood("hay")) +
			",\tfruit: " + to_string(warehouse.getCountSpecificFood("fruit")) + ",\tgrain: " + to_string(warehouse.getCountSpecificFood("grain")) + ".";
	}

	string sellAnimal(string typeAnimal, int countAnimal, int nCage)
	{
		string result = "";
		int count = cages[nCage - 1].getCountAnimal();
		if (count != 0) {
			int price = cages[nCage - 1].sellAnimal(countAnimal, typeAnimal);
			if (price != 0) {
				money += price;
				result = "success";
			}
			else {
				result = "Not enough \"" + typeAnimal + "\" or don't exist this type of animal in " + to_string(nCage) + " cage.";
			}
		}
		else {
			result = "Not enough \"" + typeAnimal + "\" in " + to_string(nCage) + " cage.";
		}
		return result;
	}

	string buyFood(string typeFood, int countFood)
	{
		string result = "";
		int price = 0;
		if (typeFood == "meat") {
			price = 30 * countFood;
		}
		if (typeFood == "hay") {
			price = 20 * countFood;
		}
		if (typeFood == "fruit") {
			price = 15 * countFood;
		}
		if (typeFood == "grain") {
			price = 10 * countFood;
		}
		if (money >= price && price != 0) {
			money -= price;
			warehouse.addFoodToW(typeFood, countFood);
			result = "success";
		}
		else {
			result = "Not enough money for buying \"" + typeFood + "\" or don't exist this type of food.";
		}

		return result;
	}

	string feedingAndBreeding()
	{
		string result = "";
		for (int i = 0; i < cages.size(); i++) {
			int countAnimal = cages[i].getCountAnimal();
			if (countAnimal != 0) {
				int deathWithoutFood = 0, deathFromOldAge = 0, spawned = 0, nCage;
				string typeFood, name;
				name = cages[i].getNameAnimal();
				typeFood = info[name];
				cages[i].actionWithAnimal(deathWithoutFood, deathFromOldAge, spawned, typeFood);
				nCage = i + 1;
				if (deathWithoutFood != 0) {
					result += to_string(deathWithoutFood) + " " + name + " starved to death in Enclosure " + to_string(nCage) + ".\n";
				}
				if (deathFromOldAge != 0) {
					result += to_string(deathFromOldAge) + " " + name + " died of old age in Enclosure " + to_string(nCage) + ".\n";
				}
				if (spawned != 0) {
					result += to_string(spawned) + " " + name + " spawned in Enclosure " + to_string(nCage) + ".\n";
				}
				if (i == cages.size() - 1) {
					result += "\n";
				}
				cages[i].clearCage();
			}
		}
		return result;
	}

	string moveToWarehouse(string typeFood, int countFood, int nCage)
	{
		string result;

		if (cages[nCage - 1].takeFoodFromC(typeFood, countFood)) {
			warehouse.addFoodToW(typeFood, countFood);
			result = "success";
		}
		else {
			result = "Not enough \"" + typeFood + "\" or don't exist this type of food.";
		}
		return result;
	}

	string moveToCage(string typeFood, int countFood, int nCage)
	{
		string result;

		if (warehouse.takeFoodFromW(typeFood, countFood)) {
			cages[nCage - 1].addFoodtoC(typeFood, countFood);
			result = "success";
		}
		else {
			result = "Not enough \"" + typeFood + "\" or don't exist this type of food.";
		}
		return result;
	}

	string moveToCage(string typeFood, int countFood, int nCage, int nSecondCage)
	{
		string result;

		if (cages[nCage - 1].takeFoodFromC(typeFood, countFood)) {
			cages[nSecondCage - 1].addFoodtoC(typeFood, countFood);
			result = "success";
		}
		else {
			result = "Not enough \"" + typeFood + "\" or don't exist this type of food.";
		}
		return result;
	}
};
