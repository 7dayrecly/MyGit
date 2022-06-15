#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
enum Mostertype{ slime, spider, orge, orc, giant, dargen };
struct Moster
{
	Mostertype type;
	char name[20];
	int health;
	int power;
	int defence;
}mos[2];


int main()
{
	srand((unsigned)time(NULL));
	int a[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "¹ÖÎï" << (i + 1) << "ÊÇ£º";
		a[i] = rand() % 6;
		mos[i].type = static_cast<Mostertype>(a[i]);
		switch (mos[i].type)
		{
		case orge:
			mos[i].health = 100 * a[i] + rand() % 50;
			mos[i].power = a[i] * 8 + rand() % 10;
			mos[i].defence = a[i] * 5 + rand() % 8;
			cout << "orge£¬";
			break;
		case slime:
			mos[i].health = 100 * (a[i] + 1) + rand() % 10;
			mos[i].power = 5 + rand() % 20;
			mos[i].defence = a[i] * 5 + rand() % 10;
			cout << "slime£¬";
			break;
		case spider:
			mos[i].health = 60 * a[i] + rand() % 30;
			mos[i].power = a[i] * 15 + rand() % 25;
			mos[i].defence = a[i] * 4 + rand() % 8;
			cout << "spider£¬";
			break;
		case orc:
			mos[i].health = 60 * a[i] + rand() % 60;
			mos[i].power = a[i] * 10 + rand() % 10;
			mos[i].defence = a[i] * 6 + rand() % 8;
			cout << "orc£¬";
			break;
		case giant:
			mos[i].health = 80 * a[i] + rand() % 70;
			mos[i].power = a[i] * 10 + rand() % 10;
			mos[i].defence = a[i] * 10 + rand() % 8;
			cout << "giant£¬";
			break;
		case dargen:
			mos[i].health = 100 * a[i] + rand() % 100;
			mos[i].power = a[i] * 10 + rand() % 10;
			mos[i].defence = a[i] * 8 + rand() % 30;
			cout << "dargen£¬";
			break;
		default:
			break;
		}
		cout << mos[i].health << "  " << mos[i].power << "  " << mos[i].defence << endl;
	}
	/*int act;*/

	bool order = 0;
	while (true)
	{
		//Action(mos, order);
		if (order == 1)
		{
			int a = (rand() % 100 - (1 - mos[0].defence / mos[1].power) * 20 + 10);
			mos[0].health -= (a >= 0 ? a : 0);
			cout << "¹ÖÊÞ2¶Ô¹ÖÊÞ1Ôì³É" << (a >= 0 ? a : 0) << "µãÉËº¦£¬¹ÖÊÞ1»¹Ê£" << mos[0].health << "HP¡£" << endl;
		}
		else
		{
			int b = (rand() % 100 - (1 - mos[1].defence / mos[0].power) * 20 + 10);
			mos[1].health -= (b >= 0 ? b : 0);
			cout << "¹ÖÊÞ1¶Ô¹ÖÊÞ2Ôì³É" << (b >= 0 ? b : 0) << "µãÉËº¦£¬¹ÖÊÞ2»¹Ê£" << mos[1].health << "HP¡£" << endl;
		}
		if (mos[0].health <= 0)
		{
			cout << "ÓÎÏ·½áÊø£¬¹ÖÊÞ2»ñÊ¤¡£" << endl;
			break;
		}
		else if (mos[1].health <= 0)
		{
			cout << "ÓÎÏ·½áÊø£¬¹ÖÊÞ1»ñÊ¤¡£" << endl;
			break;
		}
		order = !order;

	}



	return 0;
}

void Action(Moster mos[2], bool order)
{
	if (order == 1)
	{
		int a = (rand() % 100 - (1 - mos[0].defence / mos[1].power) * 20 + 10);
		mos[0].health -= (a >= 0 ? a : 0);
		cout << "¹ÖÊÞ2¶Ô¹ÖÊÞ1Ôì³É" << (a >= 0 ? a : 0) << "µãÉËº¦£¬¹ÖÊÞ1»¹Ê£" << mos[0].health << "HP¡£" << endl;
	}
	else
	{
		int b = (rand() % 100 - (1 - mos[1].defence / mos[0].power) * 20 + 10);
		mos[1].health -= (b >= 0 ? b : 0);
		cout << "¹ÖÊÞ1¶Ô¹ÖÊÞ2Ôì³É" << (b >= 0 ? b : 0) << "µãÉËº¦£¬¹ÖÊÞ2»¹Ê£" << mos[1].health << "HP¡£" << endl;
	}
}