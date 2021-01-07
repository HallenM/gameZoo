#pragma once
#include "ZooManager.h"

class ZooViewContoller
{
	bool finishGame = false;
	int N;
	ZooManager manager;
public:
	ZooViewContoller() { }

	void start() {
		cout << "Hello! Welcome to Your Zoo!" << endl;
		cout << "To start, please, enter the number of cages in your Zoo:" << endl;
		cin >> N;
		manager.populateAnimals(N);
		stateZoo();
		stateMoney();
		stateWarehous();
		help();
		while (!finishGame) {
			userCommand();
		}
	}

	void stateZoo() {
		Cage cage;
		int count = 0;
		string name = "";
		cout << "--------------------------------------------------------------------------" << endl;
		for (int i = 0; i < N; i++) {
			cage = manager.infoAboutCage(i);
			cage.getAnimalInfo(name, count);
			cout << "Enclosure " << i + 1 << ": " << name << ".\tQuantity: " << count << ".\tEat: "
				<< manager.getFoodType(name) << ".\tFood: " << cage.getFoodInCage() << ". " << endl;
		}
		cout << "--------------------------------------------------------------------------" << endl;
	}

	void stateWarehous()
	{
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "Food on the warehouse:" << endl;
		cout << manager.getInfoWarehouse() << endl;
		cout << "--------------------------------------------------------------------------" << endl;
	}

	void stateMoney()
	{
		cout << "\nAvailable money:\t" << manager.money << endl << endl;
	}

	void help()
	{
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "Available commands: " << endl;
		cout << "move A B to C  -  move A units of type B foods from warehouse to cage C." << endl;
		cout << "move A B from C to warehouse  -  move A units of type B foods from cage C to warehouse." << endl;
		cout << "move A B from C to cage D  -  move A units of type B foods from cage C to cage D." << endl;
		cout << "sell A B from C  -  sell A units of type B animals from cage C." << endl;
		cout << "buy A B  -  buy A units of type B foods." << endl;
		cout << "next  -  end of turn and start of a new day." << endl;
		cout << "finish  -  end of game." << endl;
		cout << "help  -  info about commands." << endl;
		cout << "--------------------------------------------------------------------------" << endl;
	}

	void userCommand() {
		string command;
		cin >> command;
		if (command == "move") {
			int countFood;
			string typeFood;
			int nCage;
			cin >> countFood >> typeFood >> command;
			if (command == "to") {
				cin >> nCage;
				// move to cage
				string resp = manager.moveToCage(typeFood, countFood, nCage);
				if (resp == "success") {
					cout << "\nSuccessfull, the \"" << typeFood << "\" was moved from warehouse to " << nCage << " cage." << endl;
					stateZoo();
					stateWarehous();
				}
				else {
					cout << endl << resp << endl;
				}
			}
			else if (command == "from") {
				cin >> nCage >> command >> command;
				if (command == "warehouse") {
					// move to warehouse
					string resp = manager.moveToWarehouse(typeFood, countFood, nCage);
					if (resp == "success") {
						cout << "\nSuccessfull, the \"" << typeFood << "\" was moved from " << nCage << " cage to warehouse." << endl;
						stateZoo();
						stateWarehous();
					}
					else {
						cout << endl << resp << endl;
					}
				}
				else if (command == "cage") {
					int nSecondCage;
					cin >> nSecondCage;
					// move btw cages
					string resp = manager.moveToCage(typeFood, countFood, nCage, nSecondCage);
					if (resp == "success") {
						cout << "\nSuccessfull, the \"" << typeFood << "\" was moved from "<< nCage << " to " << nSecondCage << " cage." << endl;
						stateZoo();
					}
					else {
						cout << endl << resp << endl;
					}
				}
				else {
					cout << "\nWrong command, please, try again." << endl;
				}
			}
			else {
				cout << "\nWrong command, please, try again." << endl;
			}
		}
		else if (command == "sell") {
			int countAnimal, nCage;
			string typeAnimal;
			cin >> countAnimal >> typeAnimal >> command >> nCage;
			// sell animal
			manager.sellAnimal(typeAnimal, countAnimal, nCage);
			stateMoney();
			stateZoo();
		}
		else if (command == "buy") {
			int countFood;
			string typeFood;
			cin >> countFood >> typeFood;
			// buy food
			manager.buyFood(typeFood, countFood);
			stateWarehous();
		}
		else if (command == "next") {
			//func end turn
			string resp = manager.feedingAndBreeding();
			cout << endl << resp << endl;
		}
		else if (command == "finish") {
			finishGame = true;
		}
		else if (command == "help") {
			help();
		}
		else {
			cout << "\nWrong command, please, try again." << endl;
		}
	}
};
