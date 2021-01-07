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
	virtual bool eatFood(string food_type) = 0;

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

	virtual void grow() = 0;

	virtual bool death() = 0;

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
	
	virtual ~Animal() {}
};
