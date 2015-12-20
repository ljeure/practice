// Yahtzee Dice Simulator
// Programmer: Luke Eure
// 2/22/2015

/* Description:
Yahtzee is a fun game that everyone loves, but how can you play if you don't have dice? You couldn't... until now!
The C++ Yahtzee Dice Simulator allows you to roll dice as you would in the game Yahtzee. You have three rolls, and you can strategicly hold
on to dice between rolls. 
The random element of the game allows the dice to roll... randomly! I used the method shown in the book to seed the rand() and to get a number between 1 and 6.

Then I knew that the user would be prompted somehow to pick which dice to keep, but I wasn't sure how to work in allowing the user to indicate when they were ready to move to the next roll
I didn't want to have too many layers of questions for the user to wade through, so I settled on just having the user input 0 instead of a die number to indicate that they wanted to move on.
The program loops to continue asking the user which dice to save until 0 is entered.

I set boolean values for each of the dice (the keep variables) to avoid re-assigning the kept dice a random number.

I was going to re-write the rolling segment for each of the three rolls, but then I realized that it would be more elegant to just have a loop run 3 times for each of the three rolls.

After playing through the game a couple times, I realized that the "keepeing dice" stage was confusing to use, so I added the section that displays the dice currently saved.

Currently all the program does is act as dice, but it could potentially be expanded to play anentire game of Yahtzee against the user, or allow multiple users to play
in multiplayer mode.


*/
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
	int dice1, dice2, dice3, dice4, dice5, uKeep;
	bool keep1, keep2, keep3, keep4, keep5;

	//declaring the keep variables false by default
	keep1 = false;
	keep2 = false;
	keep3 = false;
	keep4 = false;
	keep5 = false;

	int x = 1;

	// header
	cout << endl << "Welcome to the Yahtzee dice simulator!\n";


// run the loop which allows you to roll three times
while (true)
{
	// only roll the die if it hasn't been kept
	if (keep1 == false)
		dice1 = (rand() % 6) +1;
	if (keep2 == false)
		dice2 = (rand() % 6) +1;
	if (keep3 == false)
		dice3 = (rand() % 6) +1;
	if (keep4 == false)
		dice4 = (rand() % 6) +1;
	if (keep5 == false)
		dice5 = (rand() % 6) +1;

	// reset all the keep values to false so the user can change his/her mind and roll dice that s/he kept last time
	keep1 = false;
	keep2 = false;
	keep3 = false;
	keep4 = false;
	keep5 = false;
	
	// display the second roll
	cout << endl << "Roll number " << x <<": "<< endl << endl;
	cout << "Die 1: " << dice1 << endl;
	cout << "Die 2: " << dice2 << endl;
	cout << "Die 3: " << dice3 << endl;
	cout << "Die 4: " << dice4 << endl;
	cout << "Die 5: " << dice5 << endl;

	if (x == 3)
		break;


	// keep, finish, roll
	do
	{


		//display the dice currently saved
		cout << "\nDice currently saved:\n";
		if (keep1 == true)
			cout << "Die 1\n";
		else if (keep2 == true)
			cout << "Die 2\n";
		else if (keep3 == true)
			cout << "Die 3\n";
		else if (keep4 == true)
			cout << "Die 4\n";
		else if (keep5 == true)
			cout << "Die 5\n";
		else
			cout << "No dice currently saved\n";

		cout << endl << "If you would like to keep a die, type the number of the die.\nType \"0\" to move to the next roll" << endl;
		
		//get user input
		cin >> uKeep;

		// declare the keeping boolean
		if (uKeep == 1)
			keep1 = true;
		if (uKeep == 2)
			keep2 = true;
		if (uKeep == 3)
			keep3 = true;
		if (uKeep == 4)
			keep4 = true;
		if (uKeep == 5)
			keep5 = true;
	}
	while (uKeep != 0);

x += 1;
}

cout << "\nThank you for playing Yahtzee" << endl;
	


	int pause;
	cin >> pause;
}