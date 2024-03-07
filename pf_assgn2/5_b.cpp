#include <iostream>
using namespace std;

int main()
{
	int num;
	char character;

	cout << "Enter number: ";
	cin >> num;

	cout << "Enter character: ";
	cin >> character;

	cout << endl;

	int addSpace = 0;
	int moreChar = num;

	for (int upperHalf = num; upperHalf >= 1; upperHalf--)
	{
		for (int space = 1; space <= ((num + num) - 1) - (num + addSpace); space++)
			cout << ' ';
		
		for (int numChar = 1; numChar <= num; numChar++)
			cout << character;

		for (int addChar = num - moreChar; addChar >= 1; addChar--)
			cout << character;

		addSpace++;
		moreChar -= 2;
		cout << endl;
	}


	addSpace = num + (num - 2);
	moreChar = num - 4;

	for (int lowerHalf = 1; lowerHalf <= num - 1; lowerHalf++)
	{
		for (int space = 1; space <= ((num + num) - 1) - addSpace; space++)
			cout << ' ';

		for (int numChar = 1; numChar <= num; numChar++)
			cout << character;

		for (int addChar = num + moreChar; addChar >= 1; addChar--)
			cout << character;

		addSpace--;
		moreChar -= 2;
		cout << endl;
	}

	cout << endl;
	return 0;
}
