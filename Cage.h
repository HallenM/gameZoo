#pragma once
#include "Warehouse.h"

class Cage
{
	vector<Animal> animals;
	vector<Food> foodInCage;

public:
	Cage() {}

	Cage(int indexAnimal, int countAnimal)
	{
		switch (indexAnimal) {
		case 1: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 20;
				int age = 1 + rand() % 15;
				animals.push_back(Lion(age));
			}
		} break;
		case 2: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 30;
				int age = 1 + rand() % 25;
				animals.push_back(Tiger(age));
			}
		} break;
		case 3: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 25;
				int age = 1 + rand() % 20;
				animals.push_back(Cow(age));
			}
		} break;
		case 4: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 15;
				int age = 1 + rand() % 10;
				animals.push_back(Sheep(age));
			}
		} break;
		case 5: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 70;
				int age = 1 + rand() % 65;
				animals.push_back(Elefant(age));
			}
		} break;
		case 6: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 50;
				int age = 1 + rand() % 45;
				animals.push_back(Monkey(age));
			}
		} break;
		case 7: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 5;
				int age = 1 + rand() % 2;
				animals.push_back(Parrot(age));
			}
		} break;
		}
	}

	void addFoodtoC(string typeFood, int countFood)
	{
		if (foodInCage.size() == 0) {
			Food f = { typeFood, countFood };
			foodInCage.push_back(f);
		}
		else {
			bool flag = true;
			for (int i = 0; i < foodInCage.size(); i++) {
				if (foodInCage[i].type == typeFood) {
					foodInCage[i].count += countFood;
					flag = false;
				}
			}

			if (flag) {
				Food f = { typeFood, countFood };
				foodInCage.push_back(f);
			}
		}
	}

	bool takeFoodFromC(string typeFood, int countFood)
	{
		for (int i = 0; i < foodInCage.size(); i++) {
			if (foodInCage[i].type == typeFood) {
				// Невозможно отрицательное значение, поэтому >= countFood
				if (foodInCage[i].count >= countFood) {
					foodInCage[i].count -= countFood;
					return true;
				}
			}
		}
		return false;
	}

	bool isEnoughFood(string typeFood, int countFood) {
		for (int i = 0; i < foodInCage.size(); i++) {
			if (foodInCage[i].type == typeFood) {
				if (foodInCage[i].count >= countFood) {
					return true;
				}
			}
		}
		return false;
	}

	void actionWithAnimal(int &deathWithoutFood, int &deathFromOldAge, int &spawned, string typeFood)
	{
		int foodCount = animals[0].getFoodCount();
		// Первая кормёжка
		feedAnimal(foodCount, typeFood, deathWithoutFood);
		if (deathWithoutFood != 0) {
			for (int i = 0; i < deathWithoutFood; i++) {
				animals.pop_back();
			}
		}

		// Рост и смерть
		for (int i = 0; i < animals.size(); i++) {
			animals[i].grow();
			if (animals[i].death()) {
				animals.erase(animals.begin() + i);
				deathFromOldAge++;
			}
		}

		// Кормёжка на размножение и размножение
		int countForNotSpawned = 0;
		while (isEnoughFood(typeFood, foodCount * 2)) {
			feedAnimal(foodCount * 2, typeFood, countForNotSpawned);
			for (int i = 0; i < animals.size(); i++) {
				if (animals[i].spawned()) {
					spawned++;
					string name = animals[i].getName();
					spawn(name);
				}
			}
			countForNotSpawned = 0;
		}

		// Переварить пищу
		for (int i = 0; i < animals.size(); i++) {
			animals[i].digestFood();
		}
	}

	void feedAnimal(int foodCount, string typeFood, int &deathWithoutFood)
	{
		for (int i = 0; i < animals.size(); i++) {
			bool flag = true;
			for (int j = 0; j < foodInCage.size();) {
				if (foodInCage[j].type == typeFood) {
					flag = false;
					if (takeFoodFromC(foodInCage[j].type, foodCount)) {
						if (!animals[i].eatFood(foodInCage[j].type)) {
							deathWithoutFood++;
						}
					}
					else {
						deathWithoutFood++;
					}
				}
			}

			if (flag) {
				deathWithoutFood++;
			}
			/*if (foodInCage.size == 1) {
				if (foodInCage[0].type == typeFood) {
					if (takeFoodFromC(foodInCage[0].type, foodCount)) {
						if (!animals[i].eatFood(foodInCage[0].type)) {
							deathWithoutFood++;
						}
					}
					else {
						deathWithoutFood++;
					}
				}
				else {
					deathWithoutFood++;
				}
			}
			else {
				bool flag = true;
				for (int j = 0; j < foodInCage.size();) {
					if (foodInCage[j].type == typeFood) {
						flag = false;
						if (takeFoodFromC(foodInCage[j].type, foodCount)) {
							if (!animals[i].eatFood(foodInCage[j].type)) {
								deathWithoutFood++;
							}
						}
						else {
							deathWithoutFood++;
						}
					}
				}

				if (flag) {
					deathWithoutFood++;
				}
			}*/
		}
	}

	void spawn(string name) 
	{
		if (name == "Lion") {
			animals.push_back(Lion(0));
		}
		if (name == "Tiger") {
			animals.push_back(Tiger(0));
		}
		if (name == "Cow") {
			animals.push_back(Cow(0));
		}
		if (name == "Sheep") {
			animals.push_back(Sheep(0));
		}
		if (name == "Elefant") {
			animals.push_back(Elefant(0));
		}
		if (name == "Monkey") {
			animals.push_back(Monkey(0));
		}
		if (name == "Parrot") {
			animals.push_back(Parrot(0));
		}
	}

	void clearCage()
	{
		foodInCage.clear();
	}

	void getAnimalInfo(string &name, int &count)
	{
		name = animals[0].getName();
		count = animals.size();
	}

	string getFoodInCage()
	{
		string food = "";
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

};
