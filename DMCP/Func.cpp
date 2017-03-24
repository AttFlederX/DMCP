#include "Func.h"
#include "Lexicographic permutations.h"

void Menu()
{
	int choice = 0;

	while (choice < 1 || choice > 6)
	{
		system("cls");

		cout << "\nDMCP library\n\n";
		cout << "\t >>> (1) Sets\n";
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

		}

	}
}

void SetsMenu()
{
	int choice = 0;

	while (choice < 1 || choice > 4)
	{
		system("cls");

		cout << "\nDMCP library/Sets\n\n";
		cout << "\t >>> (1) Expression operations\n";
		cout << "\t >>> (2) Byte operations\n";
		cout << "\t >>> (3) Set operations\n";
		cout << "\t >>> (4) Cartesian product\n";
		cout << "\t >>> (5) Back\n";

		cout << "\nEnter the number of one of the options above: ";
		cin >> choice;

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
		case 5:
			Menu();
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