#include <iostream>

using namespace std;

void fill_initial_array(int *arr, int length_array)
{
	/*��������� ��������� ������������*/
	for (int i = 1; i <= length_array; i++)
	{
		arr[i - 1] = i;
	}
}

void print_array(int *arr, int length_array)
{
	/*���� ������������*/
	for (int m = 0; m < length_array; m++)
	{
		cout << arr[m];
	}

	cout << endl;
	system("pause");
}

void sorting_arr(int *arr, int i, int length)
{
	/*���������� �� ���������� ��� �������� ������������, ������� ���� ����������� � ����� �� i �� length-1.*/
	int temp;
	for (int k = i + 1; k < length; k++)
	{
		for (int j = k; j < length; j++)
		{
			if (arr[k] > arr[j])
			{
				temp = arr[k];
				arr[k] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

bool stop_find(int *arr, int length)
{
	/*�������� ����, �� ������������ ��������. ���� ���, �� ����������� �������� ���������.*/
	for (int i = 0; i < length - 1; i++)
	{
		if (arr[i] < arr[i + 1])
			return false;
	}

	return true;
}

void find_next_permutation(int *arr, int mini_index, int zmina, int n)
{
	/*����� �������� ������������ �� ��� ��, ���� ���� �� ����� ������������.*/
	while (!stop_find(arr, n))
	{
		for (int i = n - 2; i >= 0; i--)
		{
			if (arr[i] < arr[i + 1])
			{
				int mini = arr[i + 1];
				for (int j = i + 1; j < n; j++)
				{
					if (arr[j] > arr[i] && arr[j] < mini)
					{
						mini = arr[j];
						mini_index = j;
						zmina++;
					}
				}

				if (zmina)
					arr[mini_index] = arr[i];
				else
					arr[i + 1] = arr[i];

				arr[i] = mini;
				zmina = 0;

				sorting_arr(arr, i, n);
				cout << "The next permutation: " << endl;
				print_array(arr, n);

			}
		}
	}

	cout << "Finding is stopped" << endl;

}

void Lexicographic_permutations()
{
	/*������ ���������� ����� n. ���������� � ����������������� ������� �� ������������ �������� �������{1,2,...,n}.*/
	int len, mini_index = 0;
	int zmina = 0;
	cout << "Enter the value for n:";
	cin >> len;
	int *arr = new int[len];

	fill_initial_array(arr, len);
	cout << "The initial permutation: " << endl;
	print_array(arr, len);
	find_next_permutation(arr, mini_index, zmina, len);
}