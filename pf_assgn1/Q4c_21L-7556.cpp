#include <iostream>
using namespace std;

int main()
{
	int rows;

	cout << "Enter number of rows for each triangle: ";
	cin >> rows;
	
	for (int a = 1; a <= rows; a++)
	{
		for (int b = 1; b <= a; b++)
			cout << a;
		cout << endl;
	}

	for (int c = rows; c >= 1; c--)
	{
		for (int d = c; d >= 1; d--)
			cout << c;
		cout << endl;
	}

	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= rows - i; j++)
			cout << ' ';

		for (int k = 1; k <= i; k++)
			cout << i;

		cout << endl;
	}

	for (int l = rows; l >= 1; l--)
	{
		for (int m = 1; m <= rows - l; m++)
			cout << ' ';

		for (int n = l; n >= 1; n--)
			cout << l;

		cout << endl;
	}

	for (int e = 1; e <= rows; e++)
	{
		for (int f = 1; f <= rows - e; f++)
			cout << ' ';
		
		for (int g = 1; g <= e; g++)
			cout << e;
		
		for (int h = e - 1; h >= 1; h--)
			cout << e;

		cout << endl;
	}

	return 0;
}