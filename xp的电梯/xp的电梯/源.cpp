#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<ctime>
#include<Windows.h>
using namespace std;
class Elevator
{
private:
	int x;    //���ݵ�x����
	int y;   //���ݵ�y����
public:
	Elevator(int _x, int _y) { x = _x; y = _y; }
	void printelevtor();
	void move(Elevator &s, char N);
};
void Elevator::printelevtor()
{
	setfillcolor(RED);//�����ɫ��ɫ

	//rectangle(x, y, x + 20, y + 20);//��㣨x��y���յ㣨x+20��y+20���������ε��ݡ�
	//����ע�͵���֪����Ӱ�졣
	fillrectangle(x+1, y+1, x + 18, y + 18);//���˲���
	
}
void Elevator::move(Elevator &s, char N)
{
	//	int N;//ѡ��¥��
	//	cin >> N;
	if (y == 380)
	{
		if (N == '2')
		{
			for (int i = 0; i < 2; i++)
			{
				BeginBatchDraw();//��������
				clearrectangle(x+1, y+1, x + 18, y + 18);//�Ҹ��˲���
				y -= 20;
				s.printelevtor();
				EndBatchDraw();
				//rectangle(x, y, x + 20, y + 20);
				Sleep(100);
			}
		}

		if (N == '3')
		{
			for (int i = 0; i < 3; i++)
			{
				clearrectangle(x, y, x + 20, y + 20);
				y -= 40;
				s.printelevtor();
				//rectangle(x, y, x + 20, y + 20);
				Sleep(100);
			}
		}
		if (N == '4')
		{
			for (int i = 0; i < 4; i++)
			{
				clearrectangle(x, y, x + 20, y + 20);
				y -= 40;
				s.printelevtor();
				//rectangle(x, y, x + 20, y + 20);
				Sleep(100);
			}
		}
	}
	else if (y == 340)
	{
		if (N == '1')
		{
			clearrectangle(x+1, y+1, x + 18, y + 18);
			y += 40;
			s.printelevtor();
			//rectangle(x, y, x + 20, y + 20);
			Sleep(100);
		}
		else
		{
			if (N == '3')
			{
				for (int i = 0; i < 1; i++)
				{
					clearrectangle(x, y, x + 20, y + 20);
					y -= 40;
					s.printelevtor();
					//rectangle(x, y, x + 20, y + 20);
					Sleep(100);
				}
			}
			if (N == '4')
			{
				for (int i = 0; i < 2; i++)
				{
					clearrectangle(x, y, x + 20, y + 20);
					y -= 40;
					s.printelevtor();
					//rectangle(x, y, x + 20, y + 20);
					Sleep(100);
				}
			}
		}
	}
	else if (y == 300)
	{
		if (N == '1')
		{
			for (int i = 0; i < 2; i++)
			{
				clearrectangle(x, y, x + 20, y + 20);
				y += 40;
				s.printelevtor();
				//rectangle(x, y, x + 20, y + 20);
				Sleep(100);
			}
		}
		else if (N == '2')
		{
			for (int i = 0; i < 1; i++)
			{
				clearrectangle(x, y, x + 20, y + 20);
				y += 40;
				s.printelevtor();
				//rectangle(x, y, x + 20, y + 20);
				Sleep(100);
			}
		}
		else
		{
			clearrectangle(x, y, x + 20, y + 20);
			y -= 40;
			s.printelevtor();
			//rectangle(x, y, x + 20, y + 20);
			Sleep(100);
		}
	}
	else
	{
		if (N == '1')
		{
			for (int i = 0; i < 3; i++)
			{
				clearrectangle(x, y, x + 20, y + 20);
				y -= 40;
				s.printelevtor();
				//rectangle(x, y, x + 20, y + 20);
				Sleep(100);
			}
		}

		if (N == '2')
		{
			for (int i = 0; i < 2; i++)
			{
				clearrectangle(x, y, x + 20, y + 20);
				y -= 40;
				s.printelevtor();
				//rectangle(x, y, x + 20, y + 20);
				Sleep(100);
			}
		}
		if (N == '3')
		{
			for (int i = 0; i < 3; i++)
			{
				clearrectangle(x, y, x + 20, y + 20);
				y -= 40;
				s.printelevtor();
				//rectangle(x, y, x + 20, y + 20);
				Sleep(100);
			}
		}
	}
}
int main()
{
	initgraph(640, 480, EW_SHOWCONSOLE);
	setbkcolor(WHITE);//���ñ���Ϊ��ɫ
	cleardevice();//�ñ���ɫ�����Ļ
	setlinecolor(BLACK);
	line(320, 200, 320, 400);
	line(340, 200, 340, 400);//����������
	line(320, 400, 340, 400);
	line(320, 360, 340, 360);
	line(320, 320, 340, 320);
	line(320, 280, 340, 280);//����������
	TCHAR s1[] = _T("��¥");
	settextcolor(BLACK);
	outtextxy(350, 260, s1);
	TCHAR s2[] = _T("��¥");
	outtextxy(350, 300, s2);
	TCHAR s3[] = _T("��¥");
	outtextxy(350, 340, s3);
	TCHAR s4[] = _T("һ¥");
	outtextxy(350, 380, s4);

	Elevator myelevator(320, 380);
	myelevator.printelevtor();

	while (1)
	{
		//BeginBatchDraw();ע�͵���
		
		char N;
		while (_kbhit())
		{
			N = _getch();
			myelevator.move(myelevator, N);
		}
		//EndBatchDraw();

	}
	while (1);//ά�ֱ���
}