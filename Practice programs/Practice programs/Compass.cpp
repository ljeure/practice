// Compass
// Written by: Luke Eure
// Date: 2/15/15


#include <iostream>
#include <string>

using namespace std;



int asd()
{

	// Initializing variables
	int x = 0, y = 0;
	string uDirection, quadrant;

	do
	{
		// Setting the quadrant variable based on location
		if (x > 0)
		{
			if (y > 0)
				quadrant = "Northeast";
			if (y < 0)
				quadrant = "Southeast";
			if (y == 0)
				quadrant = "East";
		}
		
		if (x < 0)
		{
			if (y > 0)
			{
				quadrant = "Northwest";
			}
			if (y < 0)
			{
				quadrant = "Southwest";
			}
			if (y == 0)
			{
				quadrant = "West";
			}
		}

		if (x == 0)
		{
			if (y > 0)
				quadrant = "North";
			if (y < 0)
				quadrant = "South";
			if (y == 0)
				quadrant = "Origin";
		}

		// Output the location
		cout << endl << "(" << x << "," << y << ")" << endl;
		cout << "Quadrant: " << quadrant << endl;

		// Get direction
		cout << "Which direction would you like to go?" << endl;
		cin >> uDirection;

		// Calculate the new location
		if (uDirection == "n" || uDirection == "N")
			y += 1;
		if (uDirection == "s" || uDirection == "S")
			y -= 1;
		if (uDirection == "e" || uDirection == "E")
			x += 1;
		if (uDirection == "w" || uDirection == "W")
			x -= 1;


	} while (uDirection != "q" && uDirection != "Q"); // Break the loop if "q" is inputed
}