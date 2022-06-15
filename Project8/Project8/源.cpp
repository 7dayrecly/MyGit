#include<iostream>
#include<string>
using namespace std;
class Student
{
protected:
	int id;
	string name;
	int age;
	float score;
public:
	Student(int i = 2021001, string n = "Lili", int a = 19, float s = 89.5)
	{
		id = i; name = n; age = a; score = s;
	}
	~Student() { cout << id << "," << name << "," << "~~~" << endl; }
};
class Postgraduate :public Student
{
protected:
	string dirc;
public:
	Postgraduate(string d, int i, string n, int a, float s);
	~Postgraduate() { cout << id << "," << name << "," << dirc << "," << "~~~" << endl; }
};
Postgraduate::Postgraduate(string d = "AI", int i = 2021001, string n = "Lili", int a = 19, float s = 89.5) :Student(i, n, a, s)
{
	cout << "construction" << endl;
	cin >> d;
	cout << d;
	dirc = d; id = i; name = n; age = a; score = s;
}
int main()
{
	Student s1;
	Postgraduate P1;
}
