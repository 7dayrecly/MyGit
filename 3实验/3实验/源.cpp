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
	prestudent StudentA(1, 100, "��", 98);
	int num, GOAL;
	string NAME;
	cout << "ĳ�쿼��C++������......\n";
	cout << "��ͬѧ�ĳɼ�Ϊ��" << StudentA.getcoutgoal() << endl;
	cout << "��ͬѧ�кܶ����⣬��������ɼ���ѯ��\n";
	cout << "���������ѧ�š��������ɼ���\n";

	while (1)
	{
		cin >> num >> NAME >> GOAL;
		if (num == StudentA.getnumber() && NAME == StudentA.getname())
		{
			if (GOAL != StudentA.getgoal())
			{
				cout << "��ѯ����ĳɼ�������ȷ�ɼ�ӦΪ��" << StudentA.getgoal() << endl;
				StudentA.setgoal(100);
			}
			else
			{
				cout << "��ѯ����ĳɼ�������ذɡ�" << endl;
			}
			break;
		}
		else
		{
			cout << "�����ѧ�Ż���������ƥ�䣬���������롣\n";
		}
	}

	cout << "ѧ�ţ�" << StudentA.getnumber() << " ����Ϊ��" << StudentA.getname() << " �ɼ�Ϊ��" << StudentA.getgoal() << endl;
	return 0;
}