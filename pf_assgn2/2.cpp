#include <iostream>
using namespace std;

void twothree();
int human_Turn();
int computer_Turn(int playerTurn);
int toothpicks = 23;

int main()
{
	cout << "You can only pick 1 to 3 toothpicks (inclusive)!\n\n";
	twothree();
	return 0;
}


void twothree()
{
	int playerInput, compInput;

	while (toothpicks < 0 || toothpicks != 0)
	{
		cout << "Toothpicks available: " << toothpicks << endl << endl;
		
		playerInput = human_Turn();
		toothpicks = toothpicks - playerInput;

		if (toothpicks == 0)
		{
			cout << "You lose!\n";
			break;
		}

		compInput = computer_Turn(playerInput);
		cout << "Toothpicks picked by computer: " << compInput << endl << endl;
		toothpicks = toothpicks - compInput;

		if (toothpicks == 0)
		{
			cout << "You win!\n";
			break;
		}
	}
}


int human_Turn()
{
	int pTurn;
	cout << "Toothpicks picked by you: ";
	cin >> pTurn;

	while (pTurn < 1 || pTurn > 3 || pTurn > toothpicks)
	{
		cout << "Try again!: ";
		cin >> pTurn;
	}

	return pTurn;
}


int computer_Turn(int playerTurn)
{
	int cTurn = 0;

	if (toothpicks > 4)
		cTurn = 4 - playerTurn;

	else if (toothpicks == 4)
		cTurn = 3;

	else if (toothpicks == 3)
		cTurn = 2;

	else if (toothpicks == 2)
		cTurn = 1;

	else if (toothpicks == 1)
		cTurn = 1;

	return cTurn;
}
