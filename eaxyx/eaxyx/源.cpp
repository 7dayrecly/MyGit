#include<iostream>
#include<string>
#include<stdio.h>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
#include<graphics.h> //图形处理函数
#include<conio.h> //管键盘输入
#include<tchar.h>
#include"Fish.h"
#include"Grass.h"
#include"ContralFish.h"
#pragma comment (lib,"winmm.lib")
using namespace std;

int Leval(int &totalfish);
void Pictureinit(IMAGE &background,IMAGE begin[2],IMAGE oend[2], IMAGE tend[2]);

int main()
{
	//产生背景。
	initgraph(1120, 630, EW_SHOWCONSOLE);
	IMAGE background, begin[2], oend[2], tend[2];
	Pictureinit(background, begin, oend, tend);
	putimage(0, 0, &background);
	putimage(360, 115, &begin[1], SRCAND);
	putimage(360, 115, &begin[0], SRCPAINT);
	srand((unsigned)::time(NULL));
	
	ExMessage mouse;
	while (1)
	{
		if (peekmessage(&mouse, EM_MOUSE))
		{
			switch (mouse.message)
			{
			case WM_LBUTTONDOWN:
				if (mouse.x >= 455 && mouse.x <= 765 && mouse.y >= 270 && mouse.y <= 335)
					goto gamestart;
				break;
			default:
				break;
			}
		}
	}
	//IMAGE Fish[2];
	//loadimage(&Fish[0], "./photo/Fish1/丑鱼原图.png");
	//loadimage(&Fish[1], "./photo/Fish1/丑鱼掩码.png");
	//putimage(0, 0, &Fish[1], NOTSRCERASE);
	//putimage(0, 0, &Fish[0], SRCINVERT);
	
	//Fish fish1(0, 0, 1);
	//fish1.PrintFish();
	
gamestart:
	Sleep(1000);

	//生成玩家。
	ContralFish player(510, 315, 1, 0);
	player.SetfishPicture(1);
	player.PrintFish(0);
	
	//别的鱼，size=0的为幽灵鱼，即不存在。
	Fish fish[6];
	int direction[6][2] = { 0 };//
	int turn[6][2] = { 0 };
	//unsigned int SendSeed[6] = { 0 };//心理安慰式地改变随机数种子？完全没用。

	//初始化水草，size=0为幽灵草。
	Grass plant[10];

	//初始化环境氧量
	int Oxygen = 70;

	
	int fishnumber = 1, plantnumber = 0;
	int pace = 0;//time用来调节鱼游动以及鱼产生的频率。
	int fishtotal = 0;//fishtotal用来控制鱼的生成大小，一开始应该只生成小鱼防止大鱼骑脸游戏结束。
	char control=0; //玩家按键盘操作。wsad为上下左右。
	bool end;//玩家的两种结局，1为氧尽，0为身死。

	//游戏开始。
	while (1)
	{
		BeginBatchDraw();//开始双缓冲绘图，减少屏幕闪烁。
		
		if (pace % 80 == 0)
		{Oxygen += (plantnumber * 5 - fishnumber * 7);}
		
		if (Oxygen < 0)
		{
			end = 1;
			goto endgame;
		}
		
		control = 0;

		for (int i = 0; i <= 5; i++) //别的鱼的接触
		{
			if (fish[i].JudgeTouch(player.GetX(), player.GetY(), player.Gethight(), player.Getweight()))//调用成员函数记得加括号（^_^!）
			{
				if (fish[i].JudgeSize(player.Getsize()))
				{
					fish[i].DestoryFish();
					player.SizeUP();
					cout << i << " 吃草" << endl;
					fishnumber--;
				}
				else
				{
					end = 0;
					goto endgame;  //用goto结束循环。
				}
			}

		}

		for (int i = 0; i < 10; i++)//草接触
		{
			if (plant[i].JudgeTouch(player.GetX(), player.GetY(), player.Gethight(), player.Getweight()))//调用成员函数记得加括号（^_^!）
			{
				plant[i].DestoryFish();
				player.SizeUP();
				plantnumber--;
			}
		}

		putimage(0, 0, &background);//加载背景覆盖之前产生的鱼。

		if (pace%100 == 0) //大约每0.5秒生成一棵草，最多10
		{
			for (int i = 0; i < 10; i++)
			{
				if (plant[i].Getsize() == 0)
				{
					plant[i].SetfishPicture();
					plant[i].Setfish(i);
					plant[i].PrintFish();
					plantnumber++;
					break;
				}
			}
		}

		if (pace == 200) //大约每1秒生成一条鱼，最多六条鱼
		{
			for (int i = 0; i <= 5; i++)
			{
				if (fish[i].Getsize() == 0)
				{
					fish[i].SetfishPicture(Leval(fishtotal));
					fish[i].Setfish(i);
					fish[i].PrintFish(3);
					fishnumber++;
					fishtotal++;
					break;
				}
			}
			pace = 1;
		}

		//开始依次输出草，自由鱼，player
		
		for (int i = 0; i < 10; i++)
		{
			if (plant[i].Getsize() != 0)
				plant[i].PrintFish();
		}
		
		//time调速用
		if (pace % 4 + 1 == 4)
		{
			for (int i = 0; i <= 5; i++) //别的鱼的移动
			{
				if (fish[i].Getsize() != 0)
				{
					for (int j = 0; j < 2; j++)
					{
						if (turn[i][j] == 0)//贼麻烦的复方向生成...但对于鱼的鬼畜舞蹈作用几何有待商榷。
						{
							int k = !j;//用于对比另一个方向
							if (direction[i][k] == 0)//对比另一个方向，另一个方向为不动，该方向上下左右皆可
								direction[i][j] = rand() % 4 + 1;
							else if (direction[i][k] == 1 || direction[i][k] == 2)//另一个方向为上下，则该方向可为不动或者左右
							{
								switch (rand() % 3)
								{
								case 0: direction[i][j] = 0; break;
								case 1: direction[i][j] = 3; break;
								case 2: direction[i][j] = 4; break;
								}
							}
							else//另一个方向为左右，则该方向可为不动或者上下
								direction[i][j] = rand() % 3;
							turn[i][j] = rand() % 30 + 20;
						}
					}
				}

				if (fish[i].Getsize() != 0)
				{
					fish[i].Move(&background, i, direction, turn);
					//fish[i].PrintFish(direction[i]);
				}
			}
		}
		else 
		{
			for (int i = 0; i <= 5; i++) //别的鱼的移动
			{
				if (fish[i].Getsize() != 0)
					fish[i].PrintFish(0);
			}
		}
		
		if (_kbhit())
		{
			control = _getch();//getch放外面程序会停下。
		}
		player.ControlMove(&background, control);//玩家控制的鱼。

		char EnImformation[20] = { 0 };
		sprintf_s(EnImformation, "氧气量为：%d", Oxygen);
		char SizeImformation[20] = { 0 };
		int getsize = player.Getsize();
		sprintf_s(SizeImformation, "Size：%d", getsize);
		setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		outtextxy(0, 0, EnImformation);
		outtextxy(0, 20, SizeImformation);

		EndBatchDraw();//结束双缓冲，输出缓冲区图片
		//fish1.Move(&background);
		//cout << time << " ";
		
		pace++;
		Sleep(5);//程序停止0.005秒。
	}
	

endgame:
	cout << "游戏结束。" << endl;
	putimage(0, 0, &background);
	if (end)
	{
		putimage(0, 0, &oend[1], SRCAND);
		putimage(0, 0, &oend[0], SRCPAINT);
	}
	else
	{
		putimage(0, 0, &tend[1], SRCAND);
		putimage(0, 0, &tend[0], SRCPAINT);
	}
	
	EndBatchDraw();
	Sleep(5000);
	while (1) { if (_kbhit()) break; };//阻止程序结束,然后按任意建结束。
	return 0;
}

int Leval(int &fishtotal)
{
	if (fishtotal <= 4)
		return 1;
	else if (fishtotal > 4 && fishtotal <= 8)
		return 2;
	else 
		return 3;
}

void Pictureinit(IMAGE &background, IMAGE begin[2], IMAGE oend[2], IMAGE tend[2])
{
	loadimage(&background, _T("./photo/背景/宁静.jpg"));
	loadimage(&begin[0], _T("./photo/UI用/始/始黑.png"));
	loadimage(&begin[1], _T("./photo/UI用/始/始白.png"));
	loadimage(&oend[0], _T("./photo/UI用/氧尽/氧尽黑底.png"));
	loadimage(&oend[1], _T("./photo/UI用/氧尽/氧尽白底.png"));
	loadimage(&tend[0], _T("./photo/UI用/身死/身死黑底.png"));
	loadimage(&tend[1], _T("./photo/UI用/身死/身死白底.png"));

}