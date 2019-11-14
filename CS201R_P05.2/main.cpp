/*
	Alex, Emily, Justin, McKenzie
	Program 5
	14 November 2019
*/

#include "player.h"

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

	srand(time(0));

	int r = 0, c = 0;
	string strVariable;
	string arrayVariable[28][11];
	ifstream fileIn("board.txt");
	while (fileIn.good()) {

		for (c = 0; c < 7; c++) {

			fileIn >> strVariable;
			arrayVariable[r][c] = strVariable;

		}

		for (c = 7; c < 11; c++) {

			arrayVariable[r][c] = "0";

		}

		getline(fileIn, strVariable);
		arrayVariable[r][7] = strVariable;
		r += 1;

	}

	vector<vector<string> > vectorVariable1;
	for (int r = 0; r < 28; r++) {

		vector<string> vectorTemp;
		for (int c = 0; c < 11; c++) {

			vectorTemp.push_back(arrayVariable[r][c]);
			cout << arrayVariable[r][c] << endl; //

		}

		vectorVariable1.push_back(vectorTemp);

	}

	cout << "Welcome to Monopoly.\nNumber of players : ";

	int intVariable;
	cin >> intVariable;
	cout << endl;

	vector<Player*> vectorVariable2;
	for (int i = 1; i <= intVariable; i++) {

		cout << "Player " << i << " : ";

		string strVariable;
		cin >> strVariable;

		vectorVariable2.push_back(new Player(strVariable));

	}

	cout << endl;

	while (true) {

		for (int i = 0; i < vectorVariable1.size(); i++) {

			vectorVariable2.at(i)->setBoard(vectorVariable1);
			vectorVariable2.at(i)->playerDice();
			vectorVariable1 = vectorVariable2.at(i)->getBoard(vectorVariable1);

			bool boolVariable = vectorVariable2.at(i)->getBankrupt();
			if (boolVariable == true) { break; }

		}

	}

	for (int i = 0; i < vectorVariable1.size(); i++) {

		cout << vectorVariable2.at(i)->getName() << "\t$" << vectorVariable2.at(i)->getMoney() << endl;

	}

	return 0;

}