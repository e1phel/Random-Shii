#ifndef binarya_H
#define binarya_H
#include<iostream>

class binary_algo
{
	int size,target;
	int* list = new int[size];
public:	
	binary_algo(){}
	void verify();
	void search();
	void disp();
};
#endif
