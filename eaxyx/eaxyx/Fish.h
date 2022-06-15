#pragma once
#include<graphics.h>
//#include"easyx.h"


class Fish
{
protected:
	int hight;   //鱼的图片长宽。
	int weight;  //英语不好，貌似把wide打成了weight (-_-")，height也打错了...
	int _x;
	int _y;
	int size;
	int twards;
	IMAGE picture[2]; //在这里规定0为原图，1为掩码图。

public:
	Fish(int x, int y, int Size);//用于player初始化
	Fish();
	~Fish();
	
	void Move(IMAGE *back, int seed, int direction[6][2], int turn[6][2]);//主要是控制别的鱼移动
	void PrintFish(int direction); //输出鱼图
	void SetfishPicture(int level);
	void Setfish(int i);
	void DestoryFish() { size = 0; hight = 0; weight = 0; } //接触后销毁鱼，但并非删除对象，只是初始化鱼类size使其无法输出图像。

	int JudgeWall(int direction);//判断撞墙
	bool JudgeTouch(int x, int y, int H, int W);//判断鱼相碰
	bool JudgeSize(int size);

	int Getsize() { return size; }
	int GetX() { return _x; }
	int GetY() { return _y; }
	int Gethight() { return hight; }
	int Getweight() { return weight; }

};

