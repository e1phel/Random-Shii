#include"binarya.h"
#include<iostream>
using namespace std;

void binary_algo::input()
{
	cout << "\n Enter the Size of the array :\t";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "\n NO  " << i + 1 << " :\t";
		cin >> list[i];
	}
	cout << "\n Enter Your Target Number: ";
	cin >> target;
}
void binary_algo::verify()
{
	if (list[0] > list[1])
	{
		cout << "\n Algorithm WILL NOT work for an unsorted array !!";
		exit;
	}
	else
	{
		tick = true;
	}
}
void binary_algo::search()
{
	int split = 0;
	int x = 0;
	bool found = false;
	//Last Element Check
	if (list[size - 1] == target)
	{
		found = true;
		cout << "\n Number "<<list[size-1]<<" Found On " << split << " Splits";
	}
	else
	{
		split++;
		//Divide Array
		int mid;
		mid = size / 2;
		cout << endl << mid;
		int* right = new int[mid];
		int* left = new int[mid];
		//R.H.s
		for (int i = 0; i < mid; i++)
		{
			right[i] = list[i];
		}
		//L.H.S
		for (int i = mid-1; i < size; i++)
		{
			static int ini = 0;
			left[ini] = list[i];
			ini++;
		}
		for (int i = 0; i < mid; i++)
		{
			cout << "\n Right : " << right[i];
		}
		for (int i = 0; i < mid; i++)
		{
			cout << "\n Left : " << left[i];
		}
		//Look UP
		while (found == false)
		{
			if (list[mid] < target)
			{
				if (left[mid - 1] == target)
				{
					cout << "\n The Number " << left[mid - 1] << " was found on " << split << " splits";
					found = true;
				}
				else
				{
					mid /= 2;
					split++;
				}

			}
			else if (list[mid] > target)
			{
				if (right[mid - 1] == target)
				{
					cout << "\n The Number " << right[mid - 1] << " was found on " << split << " splits";
					found = true;
				}
				else
				{
					mid /= 2;
					split++;
				}
			}
		}
		delete[]right;
		delete[]left;
	}
	
}



