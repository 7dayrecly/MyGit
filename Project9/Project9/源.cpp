
#include<iostream>
#include<graphics.h>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<conio.h> //�ܼ�������
using namespace std;

int main()
{
	IMAGE picture[2];
	initgraph(1120, 630, EW_SHOWCONSOLE);
	
	int w = 100, h = 93;
	loadimage(&picture[0], "C:\\Users\\wujun\\source\\repos\\eaxyx\\eaxyx\\photo/Ϻ/Ϻ�ڵ�ԭͼ.png");
	loadimage(&picture[1], "C:\\Users\\wujun\\source\\repos\\eaxyx\\eaxyx\\photo/Ϻ/Ϻ�׵�����.png");
	putimage(0, 0, w, h, &picture[1], 0, 0, SRCAND);
	putimage(0, 0, w, h, &picture[0], 0, 0, SRCPAINT);
	
	w = 187; h = 117;
	loadimage(&picture[0], "C:\\Users\\wujun\\source\\repos\\eaxyx\\eaxyx\\photo/����/����ڵ�ԭͼ.png");
	loadimage(&picture[1], "C:\\Users\\wujun\\source\\repos\\eaxyx\\eaxyx\\photo/����/����׵�����.png");
	putimage(600, 330, w, h, &picture[1], 0, 0, SRCAND);
	putimage(600, 330, w, h, &picture[0], 0, 0, SRCPAINT);

	while(true){}
}