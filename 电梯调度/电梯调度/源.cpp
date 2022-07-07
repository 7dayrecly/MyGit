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
	void IsIn(vector<person> &People);
	void IsOut();
	void FindEndStep(vector<person> &People);
	void Move(vector<person> &People);
	void Print(vector<person> &People);
};

void Elevator::FindEndStep(vector<person> &People)
{
	int end = EndStep;
	if (direction == 0)
	{
		if (EPerson.empty() && People.empty())
			return;
		if (!People.empty())
		{
			int nextstep = People[0].start, diff = abs(People[0].start - NowStep);
			for (int i = 0; i < People.size(); i++)
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
			if (!EPerson.empty())
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

void Elevator::IsIn(vector<person> &People)
{
	if (People.empty())
		return;
	
	for (int i = 0; i < People.size();)
	{
		if (People[i].start == NowStep && (People[i].end - People[i].start)*direction >= 0)//当乘客与电梯同进退时才进电梯。
		{
			People[i].start = 0;
			EPerson.push_back(People[i]);
			People.erase(People.begin()+i);
			sort(EPerson.begin(), EPerson.end(), cmp);
			continue;
		}
		i++;
	}
}

void Elevator::IsOut()
{
	if (EPerson.empty())
		return;

	for (int i = 0; i < EPerson.size();)
	{
		if (EPerson[i].end == NowStep)
		{
			EPerson.erase(EPerson.begin() + i);
			sort(EPerson.begin(), EPerson.end(), cmp);
			continue;
		}
		i++;
	}
}

void Elevator::Move(vector<person> &People)
{
	if (direction == 1)
		NowStep++;
	else if (direction == -1)
		NowStep--;

	IsOut();
	IsIn(People);

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
	cout << "电梯所在层数:" << NowStep << "   状态:" << State(direction) /*<< "   终点:" << EndStep */<<endl;
	
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


int main()
{
	vector<person> People;
	Elevator elevator;
	
	initgraph(1120, 630, EW_SHOWCONSOLE);

	vector<person> test;
	person A; A.start = 3; A.end = 4; A.io = 0;
	person B; B.start = 5; B.end = 2; B.io = 0;
	person C; C.start = 4; C.end = 7; C.io = 0;
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
			break;
		}

		elevator.Move(People);
		i++;
		Sleep(2000);
	}

	return 0;
}