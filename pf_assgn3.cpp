#include <iostream>
#include <cmath>
using namespace std;

void Menu();
void Input(int terms, int deg[], int coef[]);
int Solve(int terms, int deg[], int coef[], int variable);
void Add(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int rterms, int rdeg[], int rcoef[]);
void Multiply(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int rterms, int rdeg[], int rcoef[]);
void Subtract(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int rterms, int rdeg[], int rcoef[]);
void Print(int terms, int deg[], int coef[]);
bool Equal(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[]);


int main()
{
	Menu();
	return 0;
}


void Menu()
{
	int option, prevOption = 0;
	int term, var, bterm, rterm;
	int degree[15], coefficient[15], bD[15], bC[15], rD[225], rC[225];

	cout << "0. Exit\n1. Input\n2. Solve\n3. Add\n4. Multiply\n5. Subtract\n6. Print\n7. Equal\n\nEnter your option: ";
	cin >> option;

	while (option < 0 || option > 7)
	{
		cout << "Invalid option! Try again: ";
		cin >> option;
	}
	cout << endl;

	while (option != 0)
	{
		if (option == 1)
		{
			cout << "Enter number of terms of polynomial: ";
			cin >> term;

			while (term < 0 || term > 15)
			{
				cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
				cin >> term;
			}

			cout << endl;
			Input(term, degree, coefficient);
			prevOption = 1;

			/*If user option is 1 (where he inputs a polynomial) then rest of the processes will be done on that polynomial
			  Afterwards, if user option is to add multiply or subtract then one of the polynomials will be the one which was input when the chosen option was 1
			  Otherwise two different polynomials will be input when user option is not 1*/
		}

		else if (option == 2)
		{
			if (prevOption == 1)
			{
				//Processes the Solve function on the polynomial input by the user when the chosen option is 1 at first
				cout << "Enter the value of variable: ";
				cin >> var;
				cout << "Result of polynomial when x = " << var << ": " << Solve(term, degree, coefficient, var) << endl;
				prevOption = 0;
				//Sets to zero so that function begins through default manner in following iteration
			}

			else
			{
				//Process the Solve function when the chosen option is 2 at first
				cout << "Enter number of terms of polynomial: ";
				cin >> term;

				while (term < 0 || term > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> term;
				}

				cout << endl;
				Input(term, degree, coefficient);

				cout << "\nEnter the value of variable: ";
				cin >> var;
				cout << "Result of polynomial when x = " << var << ": " << Solve(term, degree, coefficient, var) << endl;
			}
		}

		else if (option == 3)
		{
			if (prevOption == 1)
			{
				/*Processes Add function on two polynomials; one which was input by user when chosen option was 1 at first
				and the second polynomial being the following*/
				cout << "Enter number of terms of second polynomial: ";
				cin >> bterm;

				while (bterm < 0 || bterm > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> bterm;
				}

				cout << endl;
				Input(bterm, bD, bC);

				rterm = 0;
				Add(term, degree, coefficient, bterm, bD, bC, rterm, rD, rC);
				prevOption = 0;
				//Sets to zero so that function begins through default manner in following iteration
			}

			else
			{
				//Processes Add function on two polynomials, both being input when chosen option is 3 at first
				cout << "Enter number of terms of first polynomial: ";
				cin >> term;

				while (term < 0 || term > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> term;
				}

				cout << endl;
				Input(term, degree, coefficient);

				cout << "\nEnter number of terms of second polynomial: ";
				cin >> bterm;

				while (bterm < 0 || bterm > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> bterm;
				}

				cout << endl;
				Input(bterm, bD, bC);

				rterm = 0;
				Add(term, degree, coefficient, bterm, bD, bC, rterm, rD, rC);
			}
		}

		else if (option == 4)
		{
			if (prevOption == 1)
			{
				/*Processes Multiply function on two polynomials; one which was input by user when chosen option was 1 at first
				and the second polynomial being the following*/
				cout << "Enter number of terms of second polynomial: ";
				cin >> bterm;

				while (bterm < 0 || bterm > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> bterm;
				}

				cout << endl;
				Input(bterm, bD, bC);

				rterm = 0;
				Multiply(term, degree, coefficient, bterm, bD, bC, rterm, rD, rC);
				prevOption = 0;
				//Sets to zero so that function begins through default manner in following iteration
			}

			else
			{
				//Processes Multiply function on two polynomials, both being input when chosen option is 4 at first
				cout << "Enter number of terms of first polynomial: ";
				cin >> term;

				while (term < 0 || term > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> term;
				}

				cout << endl;
				Input(term, degree, coefficient);

				cout << "\nEnter number of terms of second polynomial: ";
				cin >> bterm;

				while (bterm < 0 || bterm > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> bterm;
				}

				cout << endl;
				Input(bterm, bD, bC);

				rterm = 0;
				Multiply(term, degree, coefficient, bterm, bD, bC, rterm, rD, rC);
			}
		}

		else if (option == 5)
		{
			if (prevOption == 1)
			{
				/*Processes Subtract function on two polynomials; one which was input by user when chosen option was 1 at first
				and the second polynomial being the following*/
				cout << "Enter number of terms of second polynomial: ";
				cin >> bterm;

				while (bterm < 0 || bterm > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> bterm;
				}

				cout << endl;
				Input(bterm, bD, bC);

				rterm = 0;
				Subtract(term, degree, coefficient, bterm, bD, bC, rterm, rD, rC);
				prevOption = 0;
				//Sets to zero so that function begins through default manner in following iteration
			}

			else
			{
				//Processes Subtract function on two polynomials, both being input when chosen option is 5 at first
				cout << "Enter number of terms of first polynomial: ";
				cin >> term;

				while (term < 0 || term > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> term;
				}

				cout << endl;
				Input(term, degree, coefficient);

				cout << "\nEnter number of terms of second polynomial: ";
				cin >> bterm;

				while (bterm < 0 || bterm > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> bterm;
				}

				cout << endl;
				Input(bterm, bD, bC);

				rterm = 0;
				Subtract(term, degree, coefficient, bterm, bD, bC, rterm, rD, rC);
			}
		}

		else if (option == 6)
		{
			if (prevOption == 1)
			{
				//Prints the polynomial which was input by user when chosen option was 1 at first
				Print(term, degree, coefficient);
				prevOption = 0;
				//Sets to zero so that function begins through default manner in following iteration
			}
			
			else
			{
				//Executed when chosen option is 6 at first, asks for two polynomials and gives option for printing either of the two
				cout << "Enter number of terms of first polynomial: ";
				cin >> term;

				while (term < 0 || term > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> term;
				}

				cout << endl;
				Input(term, degree, coefficient);

				cout << "\nEnter number of terms of second polynomial: ";
				cin >> bterm;

				while (bterm < 0 || bterm > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> bterm;
				}

				cout << endl;
				Input(bterm, bD, bC);

				int choice;
				cout << "\n1. First polynomial\n2. Second polynomial\nWhich polynomial would you like to print? ";
				cin >> choice;

				while (choice < 0 || choice > 2)
				{
					cout << "Invalid choice! Try again: ";
					cin >> choice;
				}
				cout << endl;

				if (choice == 1)
					Print(term, degree, coefficient);

				else if (choice == 2)
					Print(bterm, bD, bC);
			}
		}

		else if (option == 7)
		{
			if (prevOption == 1)
			{
				/*Processes Equal function on two polynomials; one which was input by user when chosen option was 1 at first
				and the second polynomial being the following*/
				cout << "Enter number of terms of second polynomial: ";
				cin >> bterm;

				while (bterm < 0 || bterm > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> bterm;
				}

				cout << endl;
				Input(bterm, bD, bC);

				(Equal(term, degree, coefficient, bterm, bD, bC) == 1) ? cout << "\nBoth polynomials are same\n" : cout << "\nBoth polynomials are different\n";
				prevOption = 0;
				//Sets to zero so that function begins through default manner in following iteration
			}

			else
			{
				//Processes Equal function on two polynomials, both being input when chosen option is 7 at first
				cout << "Enter number of terms of first polynomial: ";
				cin >> term;

				while (term < 0 || term > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> term;
				}

				cout << endl;
				Input(term, degree, coefficient);

				cout << "\nEnter number of terms of second polynomial: ";
				cin >> bterm;

				while (bterm < 0 || bterm > 15)
				{
					cout << "Terms should be between 0 and 15 (inclusive)! Try again: ";
					cin >> bterm;
				}

				cout << endl;
				Input(bterm, bD, bC);

				(Equal(term, degree, coefficient, bterm, bD, bC) == 1) ? cout << "\nBoth polynomials are same\n" : cout << "\nBoth polynomials are different\n";
			}
		}

		cout << "\nEnter your option: ";
		cin >> option;

		while (option < 0 || option > 7)
		{
			cout << "Invalid option! Try again: ";
			cin >> option;
		}
		cout << endl;
	}

	cout << "Program exited!\n";
}


void Input(int terms, int deg[], int coef[])
{
	//Inputs degree array
	for (int count = 0; count < terms; count++)
	{
		cout << "Enter degree for term " << count + 1 << ": ";
		cin >> deg[count];

		while (deg[count] < 0 || deg[count] > 15)
		{
			cout << "Degree is out of range! Try again: ";
			cin >> deg[count];
		}
	}

	//Checks to ensure different degrees are input
	for (int count = 0; count < terms; count++)
		for (int diff = count + 1; diff < terms; diff++)
			while (deg[count] == deg[diff])
			{
				cout << "Enter a different degree for term " << diff + 1 << ": ";
				cin >> deg[diff];
			}

	cout << endl;

	//Inputs coefficient array
	for (int count = 0; count < terms; count++)
	{
		cout << "Enter coefficient for term " << count + 1 << ": ";
		cin >> coef[count];
	}

	int dTemp, cTemp;
	for (int count = 0; count < terms; count++)
		for (int index = 0; index < terms - count; index++)
			if (deg[index] < deg[index + 1])
			{
				//Sorts degree array in descending order
				dTemp = deg[index];
				deg[index] = deg[index + 1];
				deg[index + 1] = dTemp;

				//Sorts the coefficients according to the respective degrees
				cTemp = coef[index];
				coef[index] = coef[index + 1];
				coef[index + 1] = cTemp;
			}
}


int Solve(int terms, int deg[], int coef[], int variable)
{
	int result = 0;

	for (int index = 0; index < terms; index++)
		result = result + (coef[index] * pow(variable, deg[index]));

	return result;
}


void Add(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int rterms, int rdeg[], int rcoef[])
{
	int dTemp, cTemp;

	for (int firstPol = 0; firstPol < aterms; firstPol++)
		for (int secondPol = 0; secondPol < bterms; secondPol++)
			if (adeg[firstPol] == bdeg[secondPol])
			{
				//Adds the terms with same degrees and stores them in result arrays
				rdeg[rterms] = adeg[firstPol];
				rcoef[rterms] = acoef[firstPol] + bcoef[secondPol];
				rterms++;

				//Sets the equal degrees and their respective coefficients in the original arrays to zero
				adeg[firstPol] = 0;
				acoef[firstPol] = 0;
				bdeg[secondPol] = 0;
				bcoef[secondPol] = 0;

				break;
			}

	int aPol, aCount = -1;
	for (aPol = 0; aPol < aterms; aPol++)
	{
		if (adeg[aPol] != 0 && acoef[aPol] != 0)
		{
			//Includes the terms from first polynomial which had different degrees from the other polynomial to the result arrays
			aCount++;
			rdeg[rterms + aCount] = adeg[aPol];
			rcoef[rterms + aCount] = acoef[aPol];
		}
	}

	int bPol, bCount = -1;
	for (bPol = 0; bPol < bterms; bPol++)
	{
		if (bdeg[bPol] != 0 && bcoef[bPol] != 0)
		{
			//Includes the terms from second polynomial which had different degrees from the other polynomial to the result arrays
			bCount++;
			rdeg[rterms + (aCount + 1) + bCount] = bdeg[bPol];
			rcoef[rterms + (aCount + 1) + bCount] = bcoef[bPol];
		}
	}

	rterms = rterms + (aCount + 1) + (bCount + 1);
	for (int count = 0; count < rterms; count++)
		for (int index = 0; index < rterms - count; index++)
			if (rdeg[index] < rdeg[index + 1])
			{
				//Sorts degree array in descending order
				dTemp = rdeg[index];
				rdeg[index] = rdeg[index + 1];
				rdeg[index + 1] = dTemp;

				//Sorts the coefficients according to the respective degrees
				cTemp = rcoef[index];
				rcoef[index] = rcoef[index + 1];
				rcoef[index + 1] = cTemp;
			}

	cout << endl;
	Print(rterms, rdeg, rcoef);
}


void Multiply(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int rterms, int rdeg[], int rcoef[])
{
	int dTemp, cTemp;
	
	//Performs multiplication on both polynomials (without addition of terms of same degree)
	for (int firstPol = 0; firstPol < aterms; firstPol++)
		for (int secondPol = 0; secondPol < bterms; secondPol++)
		{
			rdeg[rterms] = adeg[firstPol] + bdeg[secondPol];
			rcoef[rterms] = acoef[firstPol] * bcoef[secondPol];
			rterms++;
			//Counts the terms of result polynomial
		}

	for (int count = 0; count < rterms; count++)
		for (int index = 0; index < rterms - count; index++)
			if (rdeg[index] < rdeg[index + 1])
			{
				//Sorts degree array in descending order
				dTemp = rdeg[index];
				rdeg[index] = rdeg[index + 1];
				rdeg[index + 1] = dTemp;

				//Sorts the coefficients according to the respective degrees
				cTemp = rcoef[index];
				rcoef[index] = rcoef[index + 1];
				rcoef[index + 1] = cTemp;
			}

	//Adds terms with same degrees and puts the following equal degrees (with their coefficients) to zero
	for (int index = 0; index < rterms; index++)
		if (rdeg[index] == rdeg[index + 1])
		{
			rcoef[index] = rcoef[index] + rcoef[index + 1];
			rdeg[index + 1] = -1;
			rcoef[index + 1] = -1;
		}

	//Stores the terms in result arrays without the repeated degrees
	int temp = rterms, count = -1;
	for (int index = 0; index < rterms; index++)
	{
		if (rdeg[index] != -1 && rcoef[index] != -1)
		{
			count++;
			rdeg[count] = rdeg[index];
			rcoef[count] = rcoef[index];
		}

		else
			temp--;
	}

	rterms = temp;
	cout << endl;
	Print(rterms, rdeg, rcoef);
}


void Subtract(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int rterms, int rdeg[], int rcoef[])
{
	int dTemp, cTemp;

	for (int firstPol = 0; firstPol < aterms; firstPol++)
		for (int secondPol = 0; secondPol < bterms; secondPol++)
			if (adeg[firstPol] == bdeg[secondPol])
			{
				//Subtracts the terms with same degrees and stores them in result arrays
				rdeg[rterms] = adeg[firstPol];
				rcoef[rterms] = acoef[firstPol] - bcoef[secondPol];
				rterms++;

				//Sets the equal degrees and their respective coefficients in the original arrays to zero
				adeg[firstPol] = 0;
				acoef[firstPol] = 0;
				bdeg[secondPol] = 0;
				bcoef[secondPol] = 0;

				break;
			}

	int aPol, aCount = -1;
	for (aPol = 0; aPol < aterms; aPol++)
	{
		if (adeg[aPol] != 0 && acoef[aPol] != 0)
		{
			//Includes the terms from first polynomial which had different degrees from the other polynomial to the result arrays
			aCount++;
			rdeg[rterms + aCount] = adeg[aPol];
			rcoef[rterms + aCount] = acoef[aPol];
		}
	}

	int bPol, bCount = -1;
	for (bPol = 0; bPol < bterms; bPol++)
	{
		if (bdeg[bPol] != 0 && bcoef[bPol] != 0)
		{
			//Includes the terms from second polynomial which had different degrees from the other polynomial to the result arrays
			bCount++;
			rdeg[rterms + (aCount + 1) + bCount] = bdeg[bPol];
			rcoef[rterms + (aCount + 1) + bCount] = -bcoef[bPol];
		}
	}

	rterms = rterms + (aCount + 1) + (bCount + 1);
	for (int count = 0; count < rterms; count++)
		for (int index = 0; index < rterms - count; index++)
			if (rdeg[index] < rdeg[index + 1])
			{
				//Sorts degree array in descending order
				dTemp = rdeg[index];
				rdeg[index] = rdeg[index + 1];
				rdeg[index + 1] = dTemp;

				//Sorts the coefficients according to the respective degrees
				cTemp = rcoef[index];
				rcoef[index] = rcoef[index + 1];
				rcoef[index + 1] = cTemp;
			}

	cout << endl;
	Print(rterms, rdeg, rcoef);
}


void Print(int terms, int deg[], int coef[])
{
	for (int index = 0; index < terms; index++)
	{
		if (deg[index] == 0)
			cout << coef[index] << ' ';

		else
			cout << coef[index] << "x^" << deg[index] << ' ';

		//Ensures + sign before every positive coefficient
		if (coef[index + 1] > 0 && index < terms - 1)
			cout << '+';
	}
	cout << endl;
}


bool Equal(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[])
{
	bool same = false;

	if (aterms == bterms)
	{
		for (int index = 0; index < aterms; index++)
		{
			if (adeg[index] == bdeg[index])
				if (acoef[index] == bcoef[index])
					same = true;

				else
					same = false;

			else
				same = false;
		}
	}

	else
		same = false;

	return same;
}
