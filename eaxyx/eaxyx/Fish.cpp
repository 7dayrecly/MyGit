#include "Fish.h"
#include<iostream>
#include<graphics.h>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<conio.h> //�ܼ�������
using namespace std;

//���ó�����Ϊspeed
const int speed = 5;

Fish::Fish(int x, int y, int Size)
{
	_x = x;
	_y = y;
	size = Size;
	twards = 0; //����player��ʼ��Ĭ�������Խ������ʼʱplayer������ʾ�����⡣
	cout << "Fish�Ѵ���" << endl;
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
	//��ӡ��ͼ,ÿ����ͼ���������������ҡ�
	//����easyx�����һ��bug���������к����Ϻ�Ժ�����������岿�ֲ�ȱ�������
	//ò���Ǹ���weight����putimage�ᱣ��ԭ��Ϻ�Ŀ��100�����(Ҳ������loadimage�����⣿)��
	//weight�����ܺܺõش��������У�����weight�Ѿ����ˣ����Ӻ�̨�������п��Կ�������
	//����ͳһͼƬ����Ϊ180*120��ʵ���ж�����weight�����ͳһ180*120�����Խ������׼�����꣡����
	
	
	if (direction == 3)
		twards = 0;
	else if (direction == 4)
		twards = 1;

	putimage(_x, _y, 180, 120, &picture[1], 0, 120*twards, SRCAND);
	putimage(_x, _y, 180, 120, &picture[0], 0, 120*twards, SRCPAINT);

}

void Fish::Move(IMAGE *back, int now, int direction[6][2], int turn[6][2])
{
	//putimage(_x, _y, 187, 117, back, _x, _y, SRCCOPY); //���ر�������֮ǰ�������㡣
	//���汾���ڹ���س鶯�����ڷ�����������Ӧ��������һ�����־õķ���ѡ��
	//���㶼��һ�����ζ���ʲô������ϸ������ϸ΢��ͬ����
	//srand((unsigned)time(NULL) + (unsigned)seed);//û�����õĲ�����
	//��ѵ��ı��ս���12.13��ͨ����main����ֱ�Ӷ�ʮ��������ֵ��Ⱥ�����ڻ���˾�Υ�����ɣ��������뻮һ���ƶ���
	
	
	int deside;//ֻ�����Ҿ�����ķ���
	for (int i = 0; i < 2; i++)
	{
		/*if (turn[i] == 0)//���鷳�ĸ���������...��������Ĺ����赸���ü����д���ȶ��
		{
			int k = !i;//���ڶԱ���һ������
			if (direction[k] == 0)//�Ա���һ��������һ������Ϊ�������÷����������ҽԿ�
				direction[i] = rand() % 4 + 1;
			else if (direction[k] == 1 || direction[k] == 2)//��һ������Ϊ���£���÷����Ϊ������������
			{
				switch(rand()%3)
				{
				case 0: direction[i] = 0; break;
				case 1: direction[i] = 3; break;
				case 2: direction[i] = 4; break;
				}
			}
			else//��һ������Ϊ���ң���÷����Ϊ������������
				direction[i] = rand() % 3;
			turn[i] = rand() % 30 + 20;
		}
		*///�Ѿ�ת�Ƶ�main����������������ɲ����о�У��ȥ���ٹ⡣һ������һ��
	
		direction[now][i] = JudgeWall(direction[now][i]);

		switch (direction[now][i])
		{
		case 0: //������ɽ
			deside = direction[now][i];//��Ҫ������ֻ�����Ҿ������򣬵�һ��û�����ҷ����directionʱdesideδ���塣
			break;
		case 1: //�ϵ�����
			_y -= speed;
			break;
		case 2: //�µó���
			_y += speed;
			break;
		case 3: //��ǣ��
			deside = direction[now][i];
			_x -= speed;
			break;
		case 4: //�����
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
	//����������㡣
	
	int kind = rand() % level + 1;
	switch (kind)
	{
	case 3://�������ĳ�������������ϵͳ���Ʋ������١�������������Ͷ���ª������ȴ�������������Լ���ϣ����
		loadimage(&picture[0], _T("./photo/����/����ڵ�ԭͼ3.png"));
		loadimage(&picture[1], _T("./photo/����/����׵�����3.png"));
		hight = 117; weight = 187; size = 3;
		break;
	case 2://�������е�С�㣬�������ܳ���ʵûɶӪ����Ҳ���óԣ���֪��Ϊɶ����ԱҪ����һ������
		loadimage(&picture[0], _T("./photo/����/����ڵ�ԭͼ3.png"));
		loadimage(&picture[1], _T("./photo/����/����׵�����3.png"));
		hight = 130; weight = 200; size = 2;
		break;
	case 1://������С��������ճ����ı��������۸�������������С�ĸ��壬һ���ۼ�����������������ͻ�......���һ�ٴ�ͣ�ȷ�ţ���
		loadimage(&picture[0], _T("./photo/Ϻ/Ϻ�ڵ�ԭͼ4.png"));
		loadimage(&picture[1], _T("./photo/Ϻ/Ϻ�׵�����4.png"));
		hight = 93; weight = 100; size = 1;
		break;
	}
}

void Fish::Setfish(int i)
{

	_x = rand() % 800;
	_y = rand() % 400;
	cout << i << " Fish�ѳ��� " << weight << endl;
}

int Fish::JudgeWall(int direction)
{
	switch (direction)
	{
	case 0: //����
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