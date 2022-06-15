#pragma once
#include "Fish.h"
class ContralFish :
	public Fish
{
public:
	ContralFish(int x, int y, int size, int get);
	void SizeUP();
	void ControlMove(IMAGE *back, char key);
	int Judgekey(char key);

	//void skillone();
private:
	int goal = 0;
};

