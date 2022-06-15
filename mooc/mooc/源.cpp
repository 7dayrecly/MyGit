#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int main()
{
	int *x1, *x2, *y1, *y2, n;
	float sum = 0, d;
	cin >> n;
	x1 = new int[n];
	x2 = new int[n];
	y1 = new int[n];
	y2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> *x1 >> *y1 >> *x2 >> *y2;
		sum += (*x1 - *x2)*(*x1 - *x2) + (*y1 - *y2)*(*y1 - *y2);
		if (i + 1 != n)
		{
		x1++;
		x2++;
		y1++;
		y2++; 
		}
	}
	d = sqrt(sum);
	printf("%.2f\n", d);
	delete[]x1;
	delete[]x2;
	delete[]y1;
	delete[]y2;
	return 0;
}