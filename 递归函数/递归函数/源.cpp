#include<iostream>
using namespace std;

int dizen(int x);

int main()
{
	int x;
	cin >> x;
	cout << dizen(x) << endl;
	return 0;
}

int dizen(int x)
{
	if (x == 1)
		return 10;
	else
		return dizen(x - 1) + 2;
}