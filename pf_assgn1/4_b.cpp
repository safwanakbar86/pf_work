#include <iostream>
using namespace std;

int main()
{
	int rows, column, rowCount;

	cout << "Enter number of rows of the hollow triangle: ";
	cin >> rows;

	cout << endl;

	for (rowCount = rows; rowCount >= 1; rowCount--)
	{
		for (column = rowCount; column >= 1; column--)
		{
			if (rowCount != rows && rowCount != 1)
			{
				if (column == 1 || column == rowCount)
					cout << "*";

				else
					cout << " ";
			}

			else
				cout << "*";
		}

		cout << endl;
	}

	return 0;
}
