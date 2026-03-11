#ifndef binarya_H
#define binarya_H

class binary_algo
{
	bool tick = false;
	int size,target;
	int* list = new int[size];
public:	
	void input();
	void verify();
	void search();
	~binary_algo() { delete[]list; }
};
#endif
