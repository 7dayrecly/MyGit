#include<iostream>
using namespace std;

int Fning(int n, int a[]);

int main()
{
	int n;
	cin >> n;
	int a[] = { 0 };
	cout << Fning(n, a) << endl;
	return 0;
}


int Fning(int n, int a[])
{
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	for (int i = 0; i < n; i++)
	{
		if (!((i == 1) || (i == 2)))
		{

		}
	}
}