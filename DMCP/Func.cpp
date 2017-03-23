#include "Func.h"
#include "Set.h"

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

	while (choice < 1 || choice > 4)
	{
		system("cls");

		cout << "\nDMCP library/Sets\n\n";
		cout << "\t >>> (1) Expression operations\n";
		cout << "\t >>> (2) Bitwise operations\n";
		cout << "\t >>> (3) Set operations\n";
		cout << "\t >>> (4) Cartesian product\n";
		cout << "\t >>> (5) Back\n";

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
		case 5:
			Menu();
		default:
			cout << "\n\nInvaild command or an unimplemented option\n\n";
			system("pause");
			break;
		}

	}
}