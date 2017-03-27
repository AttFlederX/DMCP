#include "Func.h"
#include "Set.h"
#include "Lexicographic permutations.h"

void Menu()
{
	int choice = 0;

	while (choice < 1 || choice > 6)
	{
		system("cls");

		cout << "\nDMCP library\n\n";
		cout << "\t >>> (1) Sets & logical expressions\n";
		cout << "\t >>> (2) Combinatorics\n";
		cout << "\t >>> (3) Graphs\n";
		cout << "\t >>> (4) Trees\n";
		cout << "\t >>> (5) Binary relations\n";
		cout << "\t >>> (6) Encoding\n";

		cout << "\nEnter the number of one of the options above: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			SetsMenu();
			break;
		case 2:
			CombinatoricsMenu();
			break;
		default:
			cout << "\n\nInvaild command or an unimplemented option\n\n";
			system("pause");
			break;
		}


	}
}

void SetsMenu()
{
	int choice = 0;

	while (choice < 1 || choice > 6)
	{
		system("cls");

		cout << "\nDMCP library/Sets\n\n";
		cout << "\t >>> (1) Expression operations\n";
		cout << "\t >>> (2) Bitwise operations\n";
		cout << "\t >>> (3) Set operations\n";
		cout << "\t >>> (4) Cartesian product\n";
		cout << "\t >>> (5) Subset operations\n";
		cout << "\t >>> (6) Back\n";

		cout << "\nEnter the number of one of the options above: ";
		cin >> choice;

		Set A;
		Set B;

		switch (choice)
		{
		case 1:
			bool p, q;
			cout << "\nEnter the value for p: ";
			cin >> p;
			cout << "\nEnter the value for q: ";
			cin >> q;

			cout << "\np = " << p;
			cout << "\nq = " << q;

			cout << "\n\np && q = " << (p && q);
			cout << "\np || q = " << (p || q);
			cout << "\np XOR q = " << (p != q);
			cout << "\np => q = " << (!p || q);
			cout << "\np == q = " << (p == q) << endl;
			system("pause");

			choice = 0;
			break;
		case 3:
			cout << "\nSet A: \n";
			A.Input();
			cout << "\nSet B: \n";
			B.Input();

			cout << "\nA = ";
			A.Print();
			cout << "\nB = ";
			B.Print();

			cout << "\nA && B = ";
			A.Intersection(B).Print();
			cout << "\nA || B = ";
			A.Union(B).Print();
			cout << "\nA / B = ";
			A.Difference(B).Print();
			cout << "\nB / A = ";
			B.Difference(A).Print();
			system("pause");

			choice = 0;
			break;
		case 4:
			int n;
			Set* S;
			int len;

			cout << "Enter the number of sets: ";
			cin >> n;

			S = new Set[n];

			len = 1;
			for (int i = 0; i < n; i++)
			{
				cout << "\nSet #" << i + 1 << ": \n";
				S[i].Input();
				len *= S[i].Length();
			}	

			cout << "\nCartesian product: ";
			PrintMatrixInRow(CartesianProduct(S, n), len, n);
			cout << endl;
			system("pause");

			choice = 0;
			break;
		case 5:
			cout << "\nSet A: \n";
			A.Input();
			cout << "\nSet B: \n";
			B.Input();

			(A.IsSubset(B)) ? (cout << "\nB is a subset of A\n") : (cout << "\nB is not a subset of A\n");
			(B.IsSubset(A)) ? (cout << "A is a subset of B\n") : (cout << "A is not a subset of B\n");
			system("pause");

			choice = 0;
			break;
		case 6:
			Menu();
			break;
		default:
			cout << "\n\nInvaild command or an unimplemented option\n\n";
			system("pause");
			break;

		}

	}
}

void CombinatoricsMenu()
{
	int choice = 0;

	while (choice < 1 || choice > 4)
	{
		system("cls");

		cout << "\nDMCP library/Lexicographic permutation\n\n";
		cout << "\t >>> (1) Find lexicographic permutation for value its length, which equals n\n";
		cout << "\t >>> (2) Byte operations\n";
		cout << "\t >>> (3) Set operations\n";
		cout << "\t >>> (4) Cartesian product\n";
		cout << "\t >>> (5) Back\n";

		cout << "\nEnter the number of one of the options above: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Lexicographic_permutations();
			break;
		case 5:
			Menu();
		}

	}
}

/* Prints the matrix in a single row instead of a grid */
void PrintMatrixInRow(float** X, int n, int m)
{
	cout << "{";
	for (int i = 0; i < n; i++)
	{
		cout << "(";
		for (int j = 0; j < m; j++)
		{
			cout << X[i][j];
			(j == m - 1) ? (cout << ")") : (cout << ", ");
		}
		(i == n - 1) ? (cout << "}") : (cout << ", ");
	}
}

/* Calculates a Cartesian product of n sets from array X */
float** CartesianProduct(Set* X, int n)
{
	int pLen = 1;
	float** P;
	int arrPos = 0;
	int* setPos = new int[n];
	for (int i = 0; i < n; i++)
	{
		setPos[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		pLen *= X[i].Length();
	}

	P = new float*[pLen];
	for (int i = 0; i < pLen; i++)
	{
		P[i] = new float[n];
	}

	while (arrPos < pLen)
	{
		for (int i = 0; i < n; i++)
		{
			P[arrPos][i] = X[i][setPos[i]];			
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (setPos[i] != X[i].Length() - 1)
			{
				setPos[i]++;
				break;
			}
			else
			{
				for (int j = i - 1; j >= 0 ; j++)
				{
					if (setPos[j] == 0)
					{
						setPos[i] = 0;
						break;
					}
				}
			}
		}
		arrPos++;
	}

	return P;
}