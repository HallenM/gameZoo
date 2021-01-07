#pragma once
#include <string>

using namespace std;

class Animal
{
protected:
	string name;
	//string foodType;
	int foodCount;
	int age;
	//int maxAge; // максимальный у менеджера как и тип еды (не сделано)
	int satiety;

public:
	bool eatFood(string food_type) { return false; }

	bool spawned()
	{
		if (satiety >= foodCount * 3) {
			satiety -= foodCount * 2;
			int randValue = 1 + rand() % 10;
			if (randValue <= 3) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}

	void grow()	{ }

	bool death() {	return false; }

	void digestFood()
	{
		satiety = 0;
	}

	string getName()
	{
		return name;
	}

	int getFoodCount()
	{
		return foodCount;
	}
};