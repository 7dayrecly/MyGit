
#include<iostream>
#include<graphics.h>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<conio.h> //¹Ü¼üÅÌÊäÈë
using namespace std;

int main()
{
	IMAGE picture[2];
	initgraph(1120, 630, EW_SHOWCONSOLE);
	
	int w = 100, h = 93;
	loadimage(&picture[0], "C:\\Users\\wujun\\source\\repos\\eaxyx\\eaxyx\\photo/Ïº/ÏººÚµ×Ô­Í¼.png");
	loadimage(&picture[1], "C:\\Users\\wujun\\source\\repos\\eaxyx\\eaxyx\\photo/Ïº/Ïº°×µ×ÑÚÂë.png");
	putimage(0, 0, w, h, &picture[1], 0, 0, SRCAND);
	putimage(0, 0, w, h, &picture[0], 0, 0, SRCPAINT);
	
	w = 187; h = 117;
	loadimage(&picture[0], "C:\\Users\\wujun\\source\\repos\\eaxyx\\eaxyx\\photo/³óÓã/³óÓãºÚµ×Ô­Í¼.png");
	loadimage(&picture[1], "C:\\Users\\wujun\\source\\repos\\eaxyx\\eaxyx\\photo/³óÓã/³óÓã°×µ×ÑÚÂë.png");
	putimage(600, 330, w, h, &picture[1], 0, 0, SRCAND);
	putimage(600, 330, w, h, &picture[0], 0, 0, SRCPAINT);

	while(true){}
}