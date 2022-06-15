#include<iostream>
#include<string>
using namespace std;

enum country{China, computer, erciyuan, MgGuo, K_on, Moon};

struct Player
{
	int order;
	int num;
	string name;
	country country;
	int age;
	int goal;
}player[8] =
{
{ 0, 1, "嗯so胖", China, 18, 66.9},
{ 0, 2, "舞俊羊", China, 18, 66.8},
{ 0, 3, "乌龟盐", China, 18, 99.6},
{ 0, 4, "污菌养", China, 18, 77.7},
{ 0, 5, "鹀龜鴹", Moon, 999, 36.4},
{ 0, 6, "无君痒", erciyuan, 3, 66.6},
{ 0, 7, "wujunyang", MgGuo, 114514, 23.3},
{ 0, 8, "5-jun-young", computer, 1919810, 10.0}
};

//冒泡排序+成绩排名
void change(int chengji[8])
{
	const int size = sizeof(chengji) / sizeof(int);
	for (int i = 1; i <= size - 1; i++)
	{
		for (int j = 0; j <= size - i; j++)
		{
			int midvalue = 0;
			if (chengji[j] >= chengji[j + 1])
			{
				midvalue = chengji[j];
				chengji[j] = chengji[j + 1];
				chengji[j + 1] = midvalue;
			}
		}
	}

	for (int i = 8; i >= 1; i--)
	{
		for (int j = 0; i <= 7; j++)
		{
			if (player[j].goal == chengji[i - 1])
			{
				player[j].order = 9 - i;
				cout << "获得第" << player[j].order << "名的是" << player[j].name << endl;
				break;
			}
		}
	}
	
}


string Imformation(int i) //参赛选手的介绍词。
{
	switch (i)
	{
	case 1:
		return "嗯童鞋虽然有着中英混搭的性质，其实是报名时一个小小的意外，据某位热心市民透露，嗯so胖为他掩埋自己背后的身份用来的化名，其真实目的尚未明晰。主办方认为应该严查身份，但却因重重阻力而收效甚微。总之，身为观众，谜样男子蜜汁身份，带来多少意外和惊喜呢？";
	case 2:
		return "";
	case 3:
		return "乌同学来自China的一个古老的渔村，古老的传统无法阻止乌同学滑蛋的热情，最终，他冲破重重阻碍来到这里一展自身技艺。古老的滑蛋技巧与当下水乳交融，乌同学究竟会走到那一步呢？温馨提示，受乌同学匿名委托，请大家年他中间的字时念jun谢谢。";
	case 4:
		return "";
	case 5:
		return "";
	case 6:
		return "";
	case 7:
		return "";
	case 8:
		return "";
	}
}

int main()
{
	

	cout << "欢迎来到世界男子500m滑滑蛋大赛，下面有请参赛选手。本节目由吴氏非凡企业赞助播出，非凡之选，每一个针男人的选择。" << endl;
	
	
	//依次打印选手信息。
	for (int i = 0; i < 8; i++)
	{
		cout << "下面有请" << player[i].num << "号选手" << player[i].name << "童鞋：\n" << Imformation(player[i].num) << endl;
	}

	cout << "经历了一番激烈的角逐......" << endl;

	//开始排序（冒泡）,并输出。
	int chengji[8] = { player[0].goal, player[1].goal, player[2].goal, player[3].goal, player[4].goal, player[5].goal, player[6].goal, player[7].goal};
	change(chengji);

	return 0;
}