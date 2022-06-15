#pragma once
#include "Fish.h"
class Grass :
	public Fish
{
private:
	int ProduceOxygen;

public:
	Grass();
	
	int GetO() { return ProduceOxygen; }

	void SetfishPicture();
	void Setfish(int i);
	void PrintFish();
	bool JudgeTouch(int x, int y, int H, int W);
};

