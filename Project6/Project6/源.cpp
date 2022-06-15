#include<iostream>
#include<string>
using namespace std;
class student
{
public:
	student(int i = 2021001, string c = "Lili", int a = 19, float s = 89.5)
	{
		id = i;
		age = a;
		score = s;
		name = c;
	}
	student(student&);
	~student();
private:
	int id;
	string name;
	int age;
	float score;
};
student::~student()
{
	cout << id << "," << name << "," << "~~~" << endl;
}
int main()
{
	//student stu1;
	int id;
	string name;
	int age;
	float score;
	cin >> id >> name >> age >> score;
	student stu2;
	student stu1(id, name, age, score);
	//stu1.~student();
	//stu2.~student();
}
