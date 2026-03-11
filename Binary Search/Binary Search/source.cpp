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
	int* left = new int[x];
	int* right = new int[x];
	//Split============================================
	if (list[size - 1] == target)
	{
		cout << "\n Target Found !\t" << list[size - 1]<<"on "<<split<<"splits";
		exit(0);
	}
	
	else
	{
		x = size / 2;
		for (int i = 0; i < x; i++)
		{
			left[i] = list[i];
		}
		for (int i = x-1; i < size; i++)
		{
			int n = 0;
			right[0+n] = list[i];
			n++;
		}
		split++;
	}
	//===================================================
	while (tick == true)
	{
		//X Split=========================================
		if (left[x - 1] == target)
		{
			cout << "\n Target Found !\t" << list[x - 1]<<" on Split NO "<<split;
			tick = false;
			exit;
		}
		else if (right[x - 1] == target)
		{
			cout << "\n Target Found !\t" << list[x - 1] << " on Split NO " << split;
			tick = false;
			exit;
		}
		else
		{
			x = x / 2;
			split++;
		}
	}
	delete[]left;
	delete[]right;
}



