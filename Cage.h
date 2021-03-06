#pragma once
#include "Warehouse.h"
#include <memory>

class Cage
{
	vector<unique_ptr<Animal>> animals;
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
				animals.push_back(make_unique<Lion>(age));
			}
		} break;
		case 2: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 30;
				int age = 1 + rand() % 25;
				animals.push_back(make_unique<Tiger>(age));
			}
		} break;
		case 3: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 25;
				int age = 1 + rand() % 20;
				animals.push_back(make_unique<Cow>(age));
			}
		} break;
		case 4: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 15;
				int age = 1 + rand() % 10;
				animals.push_back(make_unique<Sheep>(age));
			}
		} break;
		case 5: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 70;
				int age = 1 + rand() % 65;
				animals.push_back(make_unique<Elefant>(age));
			}
		} break;
		case 6: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 50;
				int age = 1 + rand() % 45;
				animals.push_back(make_unique<Monkey>(age));
			}
		} break;
		case 7: {
			for (int i = 0; i < countAnimal; i++) {
				// maxAge = 5;
				int age = 1 + rand() % 2;
				animals.push_back(make_unique<Parrot>(age));
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
		int foodCount = animals[0]->getFoodCount();
		string name = animals[0]->getName();
		// Первая кормёжка
		feedAnimal(foodCount, typeFood, deathWithoutFood);
		if (deathWithoutFood != 0) {
			for (int i = 0; i < deathWithoutFood; i++) {
				animals.pop_back();
			}
		}

		// Рост и смерть
		for (int i = 0; i < animals.size(); i++) {
			animals[i]->grow();
			if (animals[i]->death()) {
				animals.erase(animals.begin() + i);
				deathFromOldAge++;
			}
		}

		// Кормёжка на размножение и размножение
		int countForNotSpawned = 0;
		while (isEnoughFood(typeFood, foodCount * 2)) {
			// На кормление для размножения необходима двойная проция еды поверх первого кормления
			feedAnimal(foodCount, typeFood, countForNotSpawned);
			feedAnimal(foodCount, typeFood, countForNotSpawned);
			for (int i = 0; i < animals.size(); i++) {
				if (animals[i]->spawned()) {
					spawned++;
				}
			}
			countForNotSpawned = 0;
		}

		// Размножение
		for (int i = 0; i < spawned; i++) {
			spawn(name);
		}

		// Переварить пищу
		for (int i = 0; i < animals.size(); i++) {
			animals[i]->digestFood();
		}
	}

	void feedAnimal(int foodCount, string typeFood, int &deathWithoutFood)
	{
		for (int i = 0; i < animals.size(); i++) {
			bool flag = true;
			for (int j = 0; j < foodInCage.size(); j++) {
				if (foodInCage[j].type == typeFood) {
					flag = false;
					if (takeFoodFromC(foodInCage[j].type, foodCount)) {
						if (!animals[i]->eatFood(foodInCage[j].type)) {
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
		}
	}

	void spawn(string name) 
	{
		if (name == "Lion") {
			animals.push_back(make_unique<Lion>(0));
		}
		if (name == "Tiger") {
			animals.push_back(make_unique<Tiger>(0));
		}
		if (name == "Cow") {
			animals.push_back(make_unique<Cow>(0));
		}
		if (name == "Sheep") {
			animals.push_back(make_unique<Sheep>(0));
		}
		if (name == "Elefant") {
			animals.push_back(make_unique<Elefant>(0));
		}
		if (name == "Monkey") {
			animals.push_back(make_unique<Monkey>(0));
		}
		if (name == "Parrot") {
			animals.push_back(make_unique<Parrot>(0));
		}
	}

	void clearCage()
	{
		foodInCage.clear();
	}

	string getNameAnimal()
	{
		if (animals.size() != 0) {
			return animals[0]->getName();
		}
		else {
			return "";
		}
	}

	int getCountAnimal()
	{
		return animals.size();
	}

	vector<Food> getFoodInCage()
	{
		return foodInCage;
	}

	int sellAnimal(int countAnimal, string typeAnimal)
	{
		int price = 0;
		string name = animals[0]->getName();

		if (name == typeAnimal) {
			// В клетке должно остаться хотя бы одно животное
			if (animals.size() >= countAnimal + 1) {
				if (name == "Lion") {
					price = 300;
				}
				if (name == "Tiger") {
					price = 300;
				}
				if (name == "Cow") {
					price = 400;
				}
				if (name == "Sheep") {
					price = 200;
				}
				if (name == "Elefant") {
					price = 500;
				}
				if (name == "Monkey") {
					price = 200;
				}
				if (name == "Parrot") {
					price = 100;
				}

				for (int i = 0; i < countAnimal; i++) {
					animals.erase(animals.begin());
				}
				return price * countAnimal;
			}
			else {
				return price;
			}
		}
		else {
			return price;
		}
	}
};
