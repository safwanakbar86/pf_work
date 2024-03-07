#include <iostream>
using namespace std;

int main()
{
	int num;
	cout << "Enter number: ";
	cin >> num;
	cout << endl;


	int upReverse = num;
	for (int upperRow = 1; upperRow <= (num + num) - 1; upperRow++)
	{
		if (upperRow > num)
		{
			cout << upReverse - 1;
			upReverse--;
		}

		else
			cout << upperRow;
	}
	cout << endl;


	for (int upperHalf = 1; upperHalf <= num - 1; upperHalf++)
	{
		for (int upNum = 1; upNum <= num - upperHalf; upNum++)
			cout << upNum;

		for (int upSpace = 1; upSpace <= upperHalf; upSpace++)
			cout << ' ';

		for (int addUpSpace = upperHalf - 1; addUpSpace >= 1; addUpSpace--)
			cout << ' ';

		for (int revUpNum = num - upperHalf; revUpNum >= 1; revUpNum--)
			cout << revUpNum;
		
		cout << endl;
	}


	for (int lowerHalf = num - 2; lowerHalf >= 1; lowerHalf--)
	{
		for (int lowNum = 1; lowNum <= num - lowerHalf; lowNum++)
			cout << lowNum;
		
		for (int lowSpace = 1; lowSpace <= lowerHalf; lowSpace++)
			cout << ' ';

		for (int addLowSpace = lowerHalf - 1; addLowSpace >= 1; addLowSpace--)
			cout << ' ';

		for (int revLowNum = num - lowerHalf; revLowNum >= 1; revLowNum--)
			cout << revLowNum;

		cout << endl;
	}


	int lowReverse = num;
	for (int lowerRow = 1; lowerRow <= (num + num) - 1; lowerRow++)
	{
		if (lowerRow > num)
		{
			cout << lowReverse - 1;
			lowReverse--;
		}

		else
			cout << lowerRow;
	}
	cout << endl;

	return 0;
}
