/*#include<iostream>
using namespace std;

int f(int a, int b);

int main()
{
	int i = 2, p = 100;
	p = f(i, i + 1);
	cout << p << endl;
}
int f(int a, int b)
{
	cout << "此行为证，f0曾悄悄来过！" << endl;
	int c;
	c = a;
	if (a > b)
		c = 1;
	else if (a == b)
		c = 0;
	else
		c = -1;
	return c;
}*/


/*#include <iostream>
using namespace std;
int fun1(int x, int y);
int fun2(int x, int y);
void main()
{
	int  x, y;
	cout << "input x,y:";
		cin >> x >> y;
	cout << fun1(x, y) << endl;
	cout << "x = " << x << "; " << "y=" << y << endl;
	cout << fun2(x, y) << endl;
}

int fun1(int x, int y)
{
	int n;
	n = x * x + y * y;
	cout << "x*x + y*y=" << n << endl;
	x = n; y = n;
	return n;
}
int fun2(int x, int y)
{
	int m;
	cout << "x and y are still the old ones？ : ";
		cout << "x=" << x << ";" << "y=" << y << endl;
	m = x * x - y * y;
	cout << "x*x - y*y=" << m << endl;
	return m;
}*/