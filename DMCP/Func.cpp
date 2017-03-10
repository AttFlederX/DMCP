#include "Func.h"

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


	}
}