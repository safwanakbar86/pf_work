#include <iostream>
using namespace std;

int main()
{
	int length, width, lengthCount, widthCount;

	cout << "Enter width of the hollow rectangle: ";
	cin >> width;

	cout << "Enter length of the hollow rectangle: ";
	cin >> length;

	cout << endl;

	for (lengthCount = 1; lengthCount <= length; lengthCount++)
	{
		for (widthCount = 1; widthCount <= width; widthCount++)
		{
			if (lengthCount != 1 && lengthCount != length)
			{
				if (widthCount == 1 || widthCount == width)
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
