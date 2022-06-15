/*#include<iostream>
#include<string>
using namespace std;
struct Sales_data
{
	unsigned units_sold = 0;
	double revenue = 0.0
};
int main()
{
	
	return 0;
}*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
using namespace std;

int main()
{
	float x;
	int i;
	scanf_s("%f %d", &x, &i);
	int a = 1;
	int n = 0;
	float e = 1;
	
	while (n <= (i + 1))
	{
		int s = 1;
		if (n <= 1)
		{
			n = 1;
		}
		else
		{
			int q = 1;
			while (q <= n)
			{
				s *= q;
				q++;
			}
		}
		x = pow(x, a);
		e = e + x / s;
		n++;
		a = n;
	}
	printf("%.4f", e);
	cin >> a;
	return 0;
}
