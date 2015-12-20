//Critter Caretaker
//Simulates caring for a virtual pet

#include <iostream>

using namespace std;

class Critter
{
public:          
    Critter(int hunger = 0, int boredom = 0); 
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
	void Display();

private:
    int m_Hunger;
    int m_Boredom;

    int GetMood() const;
    void PassTime(int time = 1);

};

Critter::Critter(int hunger, int boredom):
    m_Hunger(hunger),
    m_Boredom(boredom)
{}

inline int Critter::GetMood() const 
{
    return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}

void Critter::Display()
{
	cout << "\nYour critter's hunger level is " << m_Hunger;
	cout << "\nYour critter's boredom level is " << m_Boredom;
	PassTime();
}

void Critter::Talk()
{
    cout << "\nI'm a critter and I feel ";

    int mood = GetMood();
    if (mood > 15)
	{
        cout << "mad.\n";
	}
    else if (mood > 10)
	{
        cout << "frustrated.\n";
	}
    else if (mood > 5)
	{
        cout << "okay.\n";
	}
    else
	{
        cout << "happy.\n";
	}

	//give hints as to whether the critter is hungry or bored by saying what it's been thinking about
	cout << "Lately I've been thinking about ";

	if (m_Hunger > 9)
	{
		cout << "turkey dinner.\n";
	}

	else if (m_Boredom > 9)
	{
		cout << "amusement parks.\n";
	}

	else if (m_Hunger > 6)
	{
		cout << "sandwhiches.\n";
	}

	else if (m_Boredom > 6)
	{
		cout << "going swimming.\n";
	}

	else if (m_Hunger > 3)
	{
		cout << "cheese.\n";
	}

	else if (m_Boredom > 3)
	{
		cout << "watching a movie.\n";
	}
	
	else
	{
		cout << "how wonderful you are.\n";
	}



    PassTime();
}

void Critter::Eat(int food) 
{
    cout << "Brruppp.\n";

    m_Hunger -= food;
    if (m_Hunger < 0)
	{
        m_Hunger = 0;
	}

    PassTime();
}

void Critter::Play(int fun)
{
    cout << "Wheee!\n";

    m_Boredom -= fun;
    if (m_Boredom < 0)
	{
        m_Boredom = 0;
	}

    PassTime();
}

int main()
{
    Critter crit;

    int choice = 1;  //start the critter off talking
    while (choice != 0)
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:	
            cout << "Good-bye.\n";
			break;
        case 1:	
            crit.Talk();
			break;
        case 2:	
            crit.Eat();
			break;
        case 3:	
            crit.Play();
			break;
		case 4:
			crit.Display();
			break;
        default:
            cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
    }

    return 0;
}

