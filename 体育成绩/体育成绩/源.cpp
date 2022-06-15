#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct student
{
	int num;
	char name[20];
	float sx;
	float yw;
	float cx;
}stu[5];

int main()
{
	/*
		int num[10] = { 0 };
		int max, min, i = 1,s1 = 1,s2 = 1;
		float adv, sum = 0;
		cin >> num[0];
		max = num[0];
		min = num[0];
		while (cin >> num[i])
		{
			if (i > 9)
				break;
			if (num[i] > max)
			{
				max = num[i];
			}
			else if (num[i] == max)
			{
				s1++;
			}
			if (num[i] < min)
			{
				min = num[i];
			}
			else if (num[i] == min)
			{
				s2++;
			}
			sum += num[i];
			i++;
		}
		adv = (sum + num[0] - max * s1 - min * s2) / (i - s1 - s2);
		printf("%.2f\n", adv);
		return 0;
	*/





	int i;
	float sum;
	for (i = 0; i <= 4; i++)
	{
		cin >> stu[i].num >> stu[i].name >> stu[i].sx >> stu[i].yw >> stu[i].cx;
	}
	for (i = 0; i <= 4; i++)
	{
	sum = stu[i].sx + stu[i].yw + stu[i].cx;
	cout << stu[i].num <<  "," << stu[i].name << "," << sum;
	}
		return 0;
}