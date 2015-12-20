// Paragraph Program
// Luke Eure
// 3/4/2015

/*
psudocode:

paragraph = user entered paragraph
phrase = "";
while phrase != exit
	2. phrase = users term to search for
		if the term does exist, run a loop
			3. find the next instance of the term and output it
				if there are more, return to 3
		the user is told that there are no more instances of the term. return to 2 to search for another term
		if the term is exit, the program quits



*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// initialize variables
	string paragraph, phrase;
	int location = 0;

	// prompt user for paragraph
	cout << "\nThis program will search through a paragraph you enter for any phrase you want.\nPlease enter a paragraph:\n" << endl;
	getline (cin, paragraph);

	// display paragraph
	cout << "\nThe paragraph is:\n" << paragraph;

	phrase = " ";
	while (phrase != "exit")
	{

		//prompt user for phrase
		cout << "\nPlease enter a phrase to search for. Enter exit to exit the program:\n" << endl;
		getline (cin, phrase);


		//find instances of the phrase
		while (paragraph.find(phrase, location) != string::npos)
		{
			cout << phrase << " found at location " << paragraph.find(phrase, location) << endl;
			location = paragraph.find(phrase, location) + 1;
		}


		cout << endl << phrase << " not found anymore.\n";

	}







	return 0;
}

