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
	cout << "�Ѵ���ˮ�ݡ���" << endl;
}

void Grass::Setfish(int i)
{
	_x = rand() % 821 + 200;
	_y = rand() % 215 + 315;
	size = 1;
	cout << i << " Grass�Ѵ����� " << endl;
}

void Grass::SetfishPicture()
{
	loadimage(&picture[0], _T("./photo/ˮ��/Ұ�ݺڵ�ԭͼ.png"));
	loadimage(&picture[1], _T("./photo/ˮ��/Ұ�ݰ׵�����.png"));
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