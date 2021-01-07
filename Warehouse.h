#pragma once
#include <vector>
#include "Lion.h"
#include "Tiger.h"
#include "Cow.h"
#include "Sheep.h"
#include "Elefant.h"
#include "Monkey.h"
#include "Parrot.h"

using namespace std;

struct Food
{
	string type;
	int count;
};

class Warehouse
{
	vector<Food> foodOnW;
public:
	Warehouse()
	{
		Food f = { "meat", 600 };
		foodOnW.push_back(f);

		f = { "hay", 600 };
		foodOnW.push_back(f);

		f = { "fruit", 600 };
		foodOnW.push_back(f);

		f = { "grain", 600 };
		foodOnW.push_back(f);
	}
	
	void addFoodToW(string typeFood, int countFood)
	{
		for (int i = 0; i < foodOnW.size(); i++) {
			if (foodOnW[i].type == typeFood) {
				foodOnW[i].count += countFood;
			}
		}
	}

	bool takeFoodFromW(string typeFood, int countFood)
	{
		for (int i = 0; i < foodOnW.size(); i++) {
			if (foodOnW[i].type == typeFood) {
				// Невозможно отрицательное значение, поэтому >= countFood
				if (foodOnW[i].count >= countFood) {
					foodOnW[i].count -= countFood;
					return true;
				}
			}
		}
		return false;
	}

	string getCountSpecificFood(string typeFood)
	{
		for (int i = 0; i < foodOnW.size(); i++) {
			if (foodOnW[i].type == typeFood) {
				return to_string(foodOnW[i].count);
			}
		}
	}
};
