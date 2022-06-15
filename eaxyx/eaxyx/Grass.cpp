#include "Grass.h"
#include<iostream>
#include<graphics.h>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;

Grass::Grass() :Fish()
{
	hight = 100; weight = 100; ProduceOxygen = 5;
	cout << "已创建水草。。" << endl;
}

void Grass::Setfish(int i)
{
	_x = rand() % 821 + 200;
	_y = rand() % 215 + 315;
	size = 1;
	cout << i << " Grass已创建。 " << endl;
}

void Grass::SetfishPicture()
{
	loadimage(&picture[0], _T("./photo/水草/野草黑底原图.png"));
	loadimage(&picture[1], _T("./photo/水草/野草白底掩码.png"));
}

void Grass::PrintFish()
{
	putimage(_x, _y, 100, 100, &picture[1], 0, 0, SRCAND);
	putimage(_x, _y, 100, 100, &picture[0], 0, 0, SRCPAINT);
}

bool Grass::JudgeTouch(int x, int y, int H, int W)
{
	if (abs(x - _x) <= W && abs(y - _y) <= H && size != 0)
		return 1;
	else
		return 0;
}