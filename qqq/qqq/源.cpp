#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
void calculate(double ranking[8])
{
	for (int j = 1; j < 8; j++)
	{
		for (int i = 0; i < 7 - j; i++)
		{
			if (ranking[i] > ranking[i + 1])
			{
				j = ranking[i];
				ranking[i] = ranking[i + 1];
				ranking[i + 1] = j;
			}
		}
	}
}//¬?”r–¼
struct people
{
	int number;//???†
	int ranking;//”r–¼
	int old;//”N?
	string name;//–¼š
	string country;
	double time;//¬?
}stu[8] = { {1,1,14,"Yuuki Asuna","JAPAN",44.321},{2,8,14,"Emilia","JAPAN",49.321},{3,5,18,"??–ƒˆß","JAPAN",47.324},{4,3,16,"ç”½“c?—Ú","JAPAN",45.111},{5,4,18,"’Å–¼^”’","JAPAN",46.35},{6,7,18,"–x‹q","JAPAN",47.234},{7,6,14,"Œäâ”ü‹Õ","JAPAN",48.241},{8,3,16,"˜aò??","JAPAN",44.444} };
void main()
{
	int i = 0, b;
	cout << "?Œ}—ˆ““ú–Ÿ‘¬ŠŠ500•Ä™r?" << endl << "‰º–Ê¥Q??èM‘§" << endl;
	for (; i < 8; i++)
	{
		people *a = stu + i;
		cout << a->number << "†" << " " << a->country << " " << setw(12) << a->name << " " << a->old << "?" << " " << "—p?" << a->time << " " << a->ranking << endl;
	}
	cout << "‰º–Êª˜”ä?¬?”r–¼" << endl;
	double time[8] = { 45.111,49.321,47.324,45.111,46.35,47.234,48.241 ,44.444 };
	calculate(time);
	for (int i = 0; i < 8; i++)
	{
		cout << time[i] << endl;
	}
}