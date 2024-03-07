#include <iostream>
using namespace std;

int main()
{
	long long int num, arrow;
	char character;

	cout << "Enter number: ";
	cin >> num;

	cout << "Enter character: ";
	cin >> character;

	cout << endl;

	for (arrow = 1; arrow <= num; arrow++)
	{
		for (int spaceCount = 1; spaceCount <= num - arrow; spaceCount++)
			cout << ' ';

		for (int symbolCount = 1; symbolCount <= arrow; symbolCount++)
		{
			if (symbolCount == 1 || symbolCount == arrow)
				cout << character;

			else
				cout << ' ';
		}

		for (int extraCount = arrow - 1; extraCount >= 1; extraCount--)
		{
			if (extraCount == 1)
				cout << character;

			else
				cout << ' ';
		}

		cout << endl;
	}


	for (int strCount = 1; strCount <= num; strCount++)
	{
		for (int spaceCount = 1; spaceCount <= num - 1; spaceCount++)
			cout << ' ';

		for (int arrowCount = 1; arrowCount <= 1; arrowCount++)
			cout << character;

		cout << endl;
	}

	return 0;
}
