#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<list>
#include <algorithm>
#include<Windows.h>
#include<graphics.h>
using namespace std;

struct person
{
	int start;
	int end;
	bool io;
};

class Elevator
{
private:
	int EndStep;
	int direction;
	vector<person> EPerson;
	int NowStep;

public:

	Elevator() { EndStep = 1; direction = 0; NowStep = 1; }

	static bool cmp(person &A, person &B) { return A.end > B.end; }
	void IsIn(vector<person> &People, IMAGE up[2], IMAGE down[2]);
	void IsOut(IMAGE up[2], IMAGE down[2]);
	void FindEndStep(vector<person> &People);
	void Move(vector<person> &People, IMAGE up[2], IMAGE down[2]);
	void Print(vector<person> &People);
};

void Elevator::FindEndStep(vector<person> &People)
{
	int end = EndStep;
	if (direction == 0)
	{
		if (EPerson.empty() && People.empty())//当电梯内没人且没有人等电梯的时候，电梯方向归零（不动）。
			return;
		if (!People.empty())
		{
			int nextstep = People[0].start, diff = abs(People[0].start - NowStep);
			for (int i = 0; i < People.size(); i++)//寻找最近的有需求的层数
			{
				if (abs(People[i].start - NowStep) < diff)
				{
					nextstep = People[i].start;
					diff = abs(People[i].start - NowStep);
				}
			}
			EndStep = nextstep;
		}
		if (EndStep > NowStep)
			direction = 1;
		else if (EndStep < NowStep)
			direction = -1;
		else
		{
			if (!EPerson.empty())//寻找电梯内要到达的层数
			{
				EndStep = EPerson[0].end;
				if (EndStep > NowStep)
					direction = 1;
				else if (EndStep < NowStep)
					direction = -1;
			}
		}
	}
	else if (direction == 1)
	{
		if (!EPerson.empty())
			end = EPerson[0].end;

		for (int i = 0; i < People.size(); i++)
		{
			if ((People[i].end > People[i].start ? People[i].end : People[i].start) > end)
				end = (People[i].end > People[i].start ? People[i].end : People[i].start);
		}

		EndStep = end;

	}
	else
	{
		if (!EPerson.empty())
			end = EPerson.back().end;

		for (int i = 0; i < People.size(); i++)
		{
			if ((People[i].end < People[i].start ? People[i].end : People[i].start) < end)
				end = (People[i].end < People[i].start ? People[i].end : People[i].start);
		}

		EndStep = end;

	}

}

void Elevator::IsIn(vector<person> &People, IMAGE up[2], IMAGE down[2])
{
	setfillcolor(BLUE);
	if (People.empty())
	{
		return;
	}
	for (int i = 0; i < People.size();)
	{
		if (People[i].start == NowStep && (People[i].end - People[i].start)*direction >= 0)//当乘客与电梯同进退时才进电梯。
		{
			if (People[i].end < People[i].start)//下面是消除电梯门外的方向按钮
			{
				fillrectangle(560, (People[i].start - 1) * 105, 610, (People[i].start - 1) * 105 + 50);
				putimage(560, (People[i].start - 1) * 105, &up[1], SRCAND);
				putimage(560, (People[i].start - 1) * 105, &up[0], SRCPAINT);

			}
			else
			{
				fillrectangle(560, (People[i].start - 1) * 105 + 50, 610, (People[i].start - 1) * 105 + 100);
				putimage(560, (People[i].start - 1) * 105 + 50, &down[1], SRCAND);
				putimage(560, (People[i].start - 1) * 105 + 50, &down[0], SRCPAINT);
			}
			People[i].start = 0;
			EPerson.push_back(People[i]);
			People.erase(People.begin() + i);
			sort(EPerson.begin(), EPerson.end(), cmp);
			continue;
		}
		i++;
	}
}

void Elevator::IsOut(IMAGE up[2], IMAGE down[2])
{
	if (EPerson.empty())
		return;

	settextcolor(BLACK);
	for (int i = 0; i < EPerson.size();)
	{
		if (EPerson[i].end == NowStep)//消除电梯门内按钮
		{
			char off = '0' + NowStep;
			outtextxy(645, (NowStep - 1) * 105 + 10, off);
			EPerson.erase(EPerson.begin() + i);
			sort(EPerson.begin(), EPerson.end(), cmp);
			continue;
		}
		i++;
	}
}

void Elevator::Move(vector<person> &People, IMAGE up[2], IMAGE down[2])
{
	if (direction == 1)
	{
		NowStep++;
		for (int i = 1; i < 6; i++)
		{
			BeginBatchDraw();
			clearrectangle(0, 0, 550, 630);
			rectangle(50, (NowStep - 2) * 105 + 21 * i, 450, (NowStep - 1) * 105 + 21 * i);
			EndBatchDraw();
			Sleep(500);
		}
	}
	else if (direction == -1)
	{
		NowStep--;
		for (int i = 1; i < 6; i++)
		{
			BeginBatchDraw();
			clearrectangle(0, 0, 550, 630);
			rectangle(50, NowStep * 105 - 21 * i, 450, (NowStep + 1) * 105 - 21 * i);
			EndBatchDraw();
			Sleep(500);
		}
	}

	//人员进出
	IsOut(up, down);
	IsIn(People, up, down);

	//目标层数的更新
	for (int i = 0; i < EPerson.size(); i++)
	{
		settextcolor(GREEN);
		char on = '0' + EPerson[i].end;
		outtextxy(645, (EPerson[i].end - 1) * 105 + 10, on);
	}

	if (EndStep == NowStep)
		direction = 0;
	FindEndStep(People);

	Print(People);
}

string State(int direction)
{
	switch (direction)
	{
	case 1:
		return "上行";
		break;
	case 0:
		return "暂停";
		break;
	case -1:
		return "下行";
		break;
	}
}

void Elevator::Print(vector<person> &People)
{
	cout << "-----------" << endl;
	cout << "电梯所在层数:" << NowStep << "   状态:" << State(direction) /*<< "   终点:" << EndStep */ << endl;

	cout << "等电梯人:";
	for (int i = 0; i < People.size(); i++)
	{
		cout << "(" << People[i].start << "->" << People[i].end << ") ";
	}
	cout << endl;

	cout << "电梯内人:";
	for (int i = 0; i < EPerson.size(); i++)
	{
		cout << "(" << EPerson[i].end << ") ";
	}
	cout << endl;
}

void init(IMAGE up[2],IMAGE down[2])
{
	loadimage(&up[0], _T("./photo/upblack.png"));
	loadimage(&up[1], _T("./photo/upwhite.png"));
	loadimage(&down[0], _T("./photo/downblack.png"));
	loadimage(&down[1], _T("./photo/downwhite.png"));
	initgraph(1120, 630, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	setfillcolor(BLUE);
	settextcolor(BLACK);
	settextstyle(80, 30, _T("Number"));

	cleardevice();
	line(560, 0, 560, 630);
	line(710, 0, 710, 630);
	

	//输出按钮、楼层图形。
	for (int i = 0; i < 6; i++)
	{
		fillrectangle(560, i * 105, 610, i * 105 + 50);
		putimage(560, i * 105, &up[1], SRCAND);
		putimage(560, i * 105, &up[0], SRCPAINT);

		fillrectangle(560, i * 105 + 50, 610, i * 105 + 100);
		putimage(560, i * 105 + 50, &down[1], SRCAND);
		putimage(560, i * 105 + 50, &down[0], SRCPAINT);

		line(560, i * 105, 1120, i * 105);

		char c = '1'+ i;
		outtextxy(645, i * 105 + 10, c);
	}

	rectangle(50, 0, 450, 105);
}

int main()
{
	vector<person> People;
	Elevator elevator;

	
	IMAGE upbuttom[2];
	IMAGE downbuttom[2];
	init(upbuttom, downbuttom);
	
	
	
	
	
	



	vector<person> test;
	person A; A.start = 3; A.end = 4; A.io = 0;
	person B; B.start = 5; B.end = 2; B.io = 0;
	person C; C.start = 4; C.end = 6; C.io = 0;
	person D; D.start = 2; D.end = 4; D.io = 0;
	person E; E.start = 6; E.end = 3; E.io = 0;
	test.push_back(A);
	test.push_back(B);
	test.push_back(C);
	test.push_back(D);
	test.push_back(E);

	int i = 0;



	while (1)
	{
		

		while (i < 5)
		{
			People.push_back(test[i]);
			setfillcolor(YELLOW);
			if (People.back().end < People.back().start)
			{
				fillrectangle(560, (People.back().start - 1) * 105, 610, (People.back().start - 1) * 105 + 50);
				putimage(560, (People.back().start - 1) * 105, &upbuttom[1], SRCAND);
				putimage(560, (People.back().start - 1) * 105, &upbuttom[0], SRCPAINT);
				
			}
			else
			{
				fillrectangle(560, (People.back().start - 1) * 105 + 50, 610, (People.back().start - 1) * 105 + 100);
				putimage(560, (People.back().start - 1) * 105 + 50, &downbuttom[1], SRCAND);
				putimage(560, (People.back().start - 1) * 105 + 50, &downbuttom[0], SRCPAINT);
			}
			break;
		}

		elevator.Move(People, upbuttom, downbuttom);
		i++;

		
	}

	return 0;
}