#include<iostream>
using namespace std;

class A
{
public:
	A();
	A(int i, int j);
	~A();
	void Set(int i, int j) { a = i; b = j; }
private:
	int a, b;
};

A::A()
{
	a = 0;
	b = 0;
	cout << "a,b=0" << endl;
}

A::A(int i, int j)
{
	a = i;
	b = j;
	cout << "a=" << a << ",b=" << b << endl;
}

A::~A()
{
	cout << "Í?" << endl;
}

int main()
{
	cout << "start1" << endl;
	A a[3];
	for (int i = 0; i < 3; i++)
		a[i].Set(2 * i + 1, (i + 1) * 2);
	cout << "end1\n";
	cout << "start2\n";
	A b[3] = { A(1,2), A(3,4),A(5,6) };
	cout << "end2\n";

	return 0;
}