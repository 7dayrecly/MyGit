#include<iostream>
using namespace std;
struct stu
{
	char name[20];
	int num;
};

int main()
{
	stu student[3];
	for (int i = 0; i <= 2; i++)
	{
		cin >> student[i].name >> student[i].num;
	}
	Student(&student[0]);
	return 0;
}

void Student(stu *stud)
{
	for (int i = 0; i <= 2; i++)
	{
		cout << stud->name << stud->num << endl;
		stud++;
	}
}