// Adventure Story
// Written by: Luke Eure
// Date: 2/1/15

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	// initializing variables
	string mouseName, weapon;
	int dogNum, catNum, mouseNum, pause;

	// greeting
	cout << endl << "Welcome to the tale of all tales.\nPlease enter a name: ";

	// get name
	cin >> mouseName;

	//get numbers
	cout << endl << "Enter a whole number greater than 8:\n";
	cin >> mouseNum;
	cout << endl << "Enter a smaller whole number:\n";
	cin >> catNum;
	cout << endl << "What is your favorite weapon?\n";
	cin >> weapon;

	//tell the story
	cout << endl << "The intrepid adventurer " << mouseName << " scurried from his hole. The coast was clear." << endl;
	cout <<	"He gave a quick whistle, and his band of " << mouseNum << " heroes followed him accross the\nkitchen floor. They were on the hunt for cheese!\n\n";
	cout << "Suddenly " << mouseName << " heard a shriek from behind him. He wheeled around to see\nan attack on the right flank by " << catNum << " cats." << endl;
	cout << "The cats struck quickly and each cat managed to kill a mouse. The mice\nquickly regrouped, however, and being skilled in  the art of " << weapon;
	cout << "\nfighting, they managed to rout the rest of the cats. Their numbers were reduced to\n" << mouseNum - catNum << " but they regrouped and pressed on towards";
	cout << "their goal: the pantry.\nOnce there, they made a toast to their " << catNum << " fallen comrades, and\nthree cheers for their fearless leader " << mouseName << ".";
	cout << "They lived the rest of\ntheir days in idle gluttony, fearing neither cats nore humans.\n\n\n";
	cin >> pause;

	return 0;
}

	