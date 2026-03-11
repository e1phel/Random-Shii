#inlcude<iostream>
#include"binarya.h"

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
}
void binary_algo::verify()
{
	if (list[0] > list[1])
	{
		tick = true;
	}
	else
	{
		cout << "\n Algorithm WILL NOT work for an unsorted array !!";
		return 0;
	}
}
void binary_algo::search()
{
	int x, y;
	int* left = new int[x];
	int* right = new int[y];
	while (list[size - 1] != target)
	{
		//Split============================================
		if (list[size - 1] == target)
		{
			cout << "\n Target Found !\t" << list[size - 1];
		}
		else
		{
			x = size/2;
			y = size/2;
		}
		//================================================
		//X Split=========================================
		if (list[x - 1] == target)
		{
			cout << "\n Target Found !\t" << list[x - 1];
		}
		else
		{
			x = x / 2;
		}
	}
}


