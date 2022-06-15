#include "Fish.h"
#include<iostream>
#include<graphics.h>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<conio.h> //管键盘输入
using namespace std;

//运用常数作为speed
const int speed = 5;

Fish::Fish(int x, int y, int Size)
{
	_x = x;
	_y = y;
	size = Size;
	twards = 0; //对于player初始化默认向左，以解决程序开始时player对象不显示的问题。
	cout << "Fish已创建" << endl;
	//srand((unsigned)time(NULL));
}

Fish::Fish()
{
	size = 0;
	//srand((unsigned)time(NULL));
}

Fish::~Fish(){}

void Fish::PrintFish(int direction = 0)
{
	//打印鱼图,每个鱼图两个方向，上左下右。
	//关于easyx输出的一个bug？程序运行后吃了虾以后会出现鱼的身体部分残缺的情况，
	//貌似是更改weight后鱼putimage会保持原来虾的宽度100来输出(也可能是loadimage的问题？)，
	//weight好像不能很好地传到函数中（哪怕weight已经变了，这点从后台控制器中可以看出）。
	//后来统一图片像素为180*120，实际判断运用weight，输出统一180*120。尝试解决。标准化万岁！！！
	
	
	if (direction == 3)
		twards = 0;
	else if (direction == 4)
		twards = 1;

	putimage(_x, _y, 180, 120, &picture[1], 0, 120*twards, SRCAND);
	putimage(_x, _y, 180, 120, &picture[0], 0, 120*twards, SRCPAINT);

}

void Fish::Move(IMAGE *back, int now, int direction[6][2], int turn[6][2])
{
	//putimage(_x, _y, 187, 117, back, _x, _y, SRCCOPY); //加载背景覆盖之前产生的鱼。
	//初版本鱼在鬼畜地抽动，由于方向过于随机。应该让鱼做一个更持久的方向选择。
	//但鱼都是一样地游动是什么鬼？（仔细看能有细微不同？）
	//srand((unsigned)time(NULL) + (unsigned)seed);//没有卵用的操作。
	//军训鱼的被终结于12.13，通过在main函数直接对十二个方向赋值，群鱼终于获得了久违的自由，不再整齐划一地移动。
	
	
	int deside;//只有左右决定鱼的方向。
	for (int i = 0; i < 2; i++)
	{
		/*if (turn[i] == 0)//贼麻烦的复方向生成...但对于鱼的鬼畜舞蹈作用几何有待商榷。
		{
			int k = !i;//用于对比另一个方向
			if (direction[k] == 0)//对比另一个方向，另一个方向为不动，该方向上下左右皆可
				direction[i] = rand() % 4 + 1;
			else if (direction[k] == 1 || direction[k] == 2)//另一个方向为上下，则该方向可为不动或者左右
			{
				switch(rand()%3)
				{
				case 0: direction[i] = 0; break;
				case 1: direction[i] = 3; break;
				case 2: direction[i] = 4; break;
				}
			}
			else//另一个方向为左右，则该方向可为不动或者上下
				direction[i] = rand() % 3;
			turn[i] = rand() % 30 + 20;
		}
		*///已经转移到main函数，如今这里依旧残留有军校过去的荣光。一，二，一！
	
		direction[now][i] = JudgeWall(direction[now][i]);

		switch (direction[now][i])
		{
		case 0: //不动如山
			deside = direction[now][i];//必要，尽管只有左右决定方向，但一旦没有左右方向的direction时deside未定义。
			break;
		case 1: //上得厅堂
			_y -= speed;
			break;
		case 2: //下得厨房
			_y += speed;
			break;
		case 3: //左牵黄
			deside = direction[now][i];
			_x -= speed;
			break;
		case 4: //右擎苍
			deside = direction[now][i];
			_x += speed;
			break;
		}

		turn[now][i]--;
	}
	PrintFish(deside);
	
	//_x++;
	//_y++;
	//putimage(_x, _y, 187, 117, &picture[1], 0, 0, SRCAND);
	//putimage(_x, _y, 187, 117, &picture[0], 0, 0, SRCPAINT);
}

void Fish::SetfishPicture(int level)
{
	//随机数生成鱼。
	
	int kind = rand() % level + 1;
	switch (kind)
	{
	case 3://体型最大的池塘霸主，但因系统的制裁姗姗来迟。外表看来或许凶猛而丑陋，内心却满怀他人赞美自己的希望。
		loadimage(&picture[0], _T("./photo/丑鱼/丑鱼黑底原图3.png"));
		loadimage(&picture[1], _T("./photo/丑鱼/丑鱼白底掩码3.png"));
		hight = 117; weight = 187; size = 3;
		break;
	case 2://体型适中的小鱼，看起来很长其实没啥营养，也不好吃，不知道为啥程序员要放这家伙进来。
		loadimage(&picture[0], _T("./photo/修鱼/修鱼黑底原图3.png"));
		loadimage(&picture[1], _T("./photo/修鱼/修鱼白底掩码3.png"));
		hight = 130; weight = 200; size = 2;
		break;
	case 1://体型最小的生物，连刚出生的宝宝都能欺负，但哪怕是渺小的个体，一旦聚集起来向你冲过来，你就会......获得一顿大餐（确信）。
		loadimage(&picture[0], _T("./photo/虾/虾黑底原图4.png"));
		loadimage(&picture[1], _T("./photo/虾/虾白底掩码4.png"));
		hight = 93; weight = 100; size = 1;
		break;
	}
}

void Fish::Setfish(int i)
{

	_x = rand() % 800;
	_y = rand() % 400;
	cout << i << " Fish已出现 " << weight << endl;
}

int Fish::JudgeWall(int direction)
{
	switch (direction)
	{
	case 0: //不动
		return direction;
	case 1: //up
		if ((_y - speed) < 0)
			return 2;
		else
			return direction;
	case 2: //down
		if ((_y + speed) > 630 - hight)
			return 1;
		else
			return direction;
	case 3: //left
		if ((_x - speed) < 0)
			return 4;
		else
			return direction;
	case 4: //right
		if ((_x + speed) > 1120 - weight)
			return 3;
		else
			return direction;
	}
}

bool Fish::JudgeTouch(int x,int y,int H,int W)
{
	if ( size != 0 && abs(x - _x) <= W && abs(y - _y) <= H )
		return 1;
	else
		return 0;
}

bool Fish::JudgeSize(int Size)
{
	if (Size >= size)
		return 1;
	else
		return 0;
}