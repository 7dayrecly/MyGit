#include<iostream>
#include<string>
#include<stdio.h>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
#include<graphics.h> //ͼ�δ�����
#include<conio.h> //�ܼ�������
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
	//����������
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
	//loadimage(&Fish[0], "./photo/Fish1/����ԭͼ.png");
	//loadimage(&Fish[1], "./photo/Fish1/��������.png");
	//putimage(0, 0, &Fish[1], NOTSRCERASE);
	//putimage(0, 0, &Fish[0], SRCINVERT);
	
	//Fish fish1(0, 0, 1);
	//fish1.PrintFish();
	
gamestart:
	Sleep(1000);

	//������ҡ�
	ContralFish player(510, 315, 1, 0);
	player.SetfishPicture(1);
	player.PrintFish(0);
	
	//����㣬size=0��Ϊ�����㣬�������ڡ�
	Fish fish[6];
	int direction[6][2] = { 0 };//
	int turn[6][2] = { 0 };
	//unsigned int SendSeed[6] = { 0 };//����οʽ�ظı���������ӣ���ȫû�á�

	//��ʼ��ˮ�ݣ�size=0Ϊ����ݡ�
	Grass plant[10];

	//��ʼ����������
	int Oxygen = 70;

	
	int fishnumber = 1, plantnumber = 0;
	int pace = 0;//time�����������ζ��Լ��������Ƶ�ʡ�
	int fishtotal = 0;//fishtotal��������������ɴ�С��һ��ʼӦ��ֻ����С���ֹ����������Ϸ������
	char control=0; //��Ұ����̲�����wsadΪ�������ҡ�
	bool end;//��ҵ����ֽ�֣�1Ϊ������0Ϊ������

	//��Ϸ��ʼ��
	while (1)
	{
		BeginBatchDraw();//��ʼ˫�����ͼ��������Ļ��˸��
		
		if (pace % 80 == 0)
		{Oxygen += (plantnumber * 5 - fishnumber * 7);}
		
		if (Oxygen < 0)
		{
			end = 1;
			goto endgame;
		}
		
		control = 0;

		for (int i = 0; i <= 5; i++) //�����ĽӴ�
		{
			if (fish[i].JudgeTouch(player.GetX(), player.GetY(), player.Gethight(), player.Getweight()))//���ó�Ա�����ǵü����ţ�^_^!��
			{
				if (fish[i].JudgeSize(player.Getsize()))
				{
					fish[i].DestoryFish();
					player.SizeUP();
					cout << i << " �Բ�" << endl;
					fishnumber--;
				}
				else
				{
					end = 0;
					goto endgame;  //��goto����ѭ����
				}
			}

		}

		for (int i = 0; i < 10; i++)//�ݽӴ�
		{
			if (plant[i].JudgeTouch(player.GetX(), player.GetY(), player.Gethight(), player.Getweight()))//���ó�Ա�����ǵü����ţ�^_^!��
			{
				plant[i].DestoryFish();
				player.SizeUP();
				plantnumber--;
			}
		}

		putimage(0, 0, &background);//���ر�������֮ǰ�������㡣

		if (pace%100 == 0) //��Լÿ0.5������һ�òݣ����10
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

		if (pace == 200) //��Լÿ1������һ���㣬���������
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

		//��ʼ��������ݣ������㣬player
		
		for (int i = 0; i < 10; i++)
		{
			if (plant[i].Getsize() != 0)
				plant[i].PrintFish();
		}
		
		//time������
		if (pace % 4 + 1 == 4)
		{
			for (int i = 0; i <= 5; i++) //�������ƶ�
			{
				if (fish[i].Getsize() != 0)
				{
					for (int j = 0; j < 2; j++)
					{
						if (turn[i][j] == 0)//���鷳�ĸ���������...��������Ĺ����赸���ü����д���ȶ��
						{
							int k = !j;//���ڶԱ���һ������
							if (direction[i][k] == 0)//�Ա���һ��������һ������Ϊ�������÷����������ҽԿ�
								direction[i][j] = rand() % 4 + 1;
							else if (direction[i][k] == 1 || direction[i][k] == 2)//��һ������Ϊ���£���÷����Ϊ������������
							{
								switch (rand() % 3)
								{
								case 0: direction[i][j] = 0; break;
								case 1: direction[i][j] = 3; break;
								case 2: direction[i][j] = 4; break;
								}
							}
							else//��һ������Ϊ���ң���÷����Ϊ������������
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
			for (int i = 0; i <= 5; i++) //�������ƶ�
			{
				if (fish[i].Getsize() != 0)
					fish[i].PrintFish(0);
			}
		}
		
		if (_kbhit())
		{
			control = _getch();//getch����������ͣ�¡�
		}
		player.ControlMove(&background, control);//��ҿ��Ƶ��㡣

		char EnImformation[20] = { 0 };
		sprintf_s(EnImformation, "������Ϊ��%d", Oxygen);
		char SizeImformation[20] = { 0 };
		int getsize = player.Getsize();
		sprintf_s(SizeImformation, "Size��%d", getsize);
		setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		outtextxy(0, 0, EnImformation);
		outtextxy(0, 20, SizeImformation);

		EndBatchDraw();//����˫���壬���������ͼƬ
		//fish1.Move(&background);
		//cout << time << " ";
		
		pace++;
		Sleep(5);//����ֹͣ0.005�롣
	}
	

endgame:
	cout << "��Ϸ������" << endl;
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
	while (1) { if (_kbhit()) break; };//��ֹ�������,Ȼ�����⽨������
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
	loadimage(&background, _T("./photo/����/����.jpg"));
	loadimage(&begin[0], _T("./photo/UI��/ʼ/ʼ��.png"));
	loadimage(&begin[1], _T("./photo/UI��/ʼ/ʼ��.png"));
	loadimage(&oend[0], _T("./photo/UI��/����/�����ڵ�.png"));
	loadimage(&oend[1], _T("./photo/UI��/����/�����׵�.png"));
	loadimage(&tend[0], _T("./photo/UI��/����/�����ڵ�.png"));
	loadimage(&tend[1], _T("./photo/UI��/����/�����׵�.png"));

}