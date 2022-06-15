#include "ContralFish.h"
#include<graphics.h>
#include<iostream>
#include<conio.h> //管键盘输入
using namespace std;

ContralFish::ContralFish(int x, int y, int size, int get) :Fish(x, y, size)
{
	goal = get;
	cout << "一个玩家的鱼已经生成..." << endl;
}

void ContralFish::ControlMove(IMAGE *back, char key)
{
	//putimage(_x, _y, 187, 117, back, _x, _y, SRCCOPY); //

	int direction = Judgekey(key);

	direction = JudgeWall(direction);

	switch (direction)
	{
	case 0: //不动
		break;
	case 1: //up
		_y -= 20;
		break;
	case 2: //down
		_y += 20;
		break;
	case 3: //left
		_x -= 20;
		break;
	case 4: //right
		_x += 20;
		break;
	}


	PrintFish(direction);
}

int ContralFish::Judgekey(char key)
{
	switch (key)
	{
	case 'w': return 1; break;
	case 's': return 2; break;
	case 'a': return 3; break;
	case 'd': return 4; break;
	default: return 0; break;
	}
}

void ContralFish::SizeUP()
{
	goal++;
	if (goal <= 8)
		size = 1;
	else if (goal > 8 && goal <= 16)
		size = 2;
	else
		size = 3;
}