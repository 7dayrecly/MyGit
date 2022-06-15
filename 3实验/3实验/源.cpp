#include<iostream>
#include<string>
using namespace std;

class student
{
private:
	string name;
	int number;
	int goal;

public:
	student(int num, int Goal, string Name)
	{
		number = num;
		goal = Goal;
		name = Name;
	}

	int getgoal() { return goal; }
	int getnumber() { return number; }
	string getname() { return name; }

	void setgoal(int set) { goal = set; }
};

class prestudent :public student
{
private:
	int coutgoal;

public:
	prestudent(int num, int Goal, string Name, int CoutGoal):student(num, Goal, Name)
	{ coutgoal = CoutGoal; }
	int getcoutgoal() { return coutgoal; }
};


int main()
{
	prestudent StudentA(1, 100, "甲", 98);
	int num, GOAL;
	string NAME;
	cout << "某天考完C++的下午......\n";
	cout << "甲同学的成绩为：" << StudentA.getcoutgoal() << endl;
	cout << "甲同学有很多问题，请求申请成绩查询。\n";
	cout << "请输入你的学号、姓名、成绩。\n";

	while (1)
	{
		cin >> num >> NAME >> GOAL;
		if (num == StudentA.getnumber() && NAME == StudentA.getname())
		{
			if (GOAL != StudentA.getgoal())
			{
				cout << "查询到你的成绩有误，正确成绩应为：" << StudentA.getgoal() << endl;
				StudentA.setgoal(100);
			}
			else
			{
				cout << "查询到你的成绩无误，请回吧。" << endl;
			}
			break;
		}
		else
		{
			cout << "输入的学号或者姓名不匹配，请重新输入。\n";
		}
	}

	cout << "学号：" << StudentA.getnumber() << " 姓名为：" << StudentA.getname() << " 成绩为：" << StudentA.getgoal() << endl;
	return 0;
}