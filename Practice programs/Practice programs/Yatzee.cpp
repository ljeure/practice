// Yatzee game
// Programmer: Luke Eure
// 2/22/2015

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	// seeding the random number genorator
	srand(static_cast<unsigned int>(time(0)));

	// initializing variables
	int dice1, dice2, dice3, dice4, dice5;

	// first roll
	dice1 = rand();
	dice2 = rand();
	dice3 = rand();
	dice4 = rand();
	dice5 = rand();
	cout << endl << "Welcome tothe Yatzee game!\nHere is your first roll of the game: " << endl;
	cout << "Die 1: " << dice1 << endl;
	cout << "Die 2: " << dice2 << endl;
	cout << "Die 3: " << dice3 << endl;
	cout << "Die 4: " << dice4 << endl;
	cout << "Die 5: " << dice5 << endl;




	


	int pause;
	cin >> pause;
}