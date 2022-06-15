//#include<iostream>
//#include<string.h>
//using namespace std;

//void change(char *str1, char *str2);
/*float aver(int num[])
{
	float sum = 0;
	const int size = sizeof(num);
	int *ip = 0;
	ip = new int[size];
	//int *ip2 = ip;
	for (int i = 0; i < size; i++)
	{
		*ip = num[i];
		sum += *ip;
		ip++;
	}
	return sum / size;
}*/

/*int main()
{
	//const char *s1 = "hello";
	
	int val = 100;
	int *p1 = &val;
	int *p2;
	cout << p1 << "  " << *p1 << endl;
	//cout << p2 << "  " /<< *p2 /<< endl;
	return 0;
	
}*/

/*int main()
{
	int va, vb, vc;
	cin >> va >> vb >> vc;
	int *pa = &va;
	cout << (*pa > *(pa + 1) ? (*pa > *(pa + 2) ? *pa : *(pa + 2)) : (*(pa + 1) > *(pa + 2) ? *(pa + 1) : *(pa + 2)));
	return 0;
}*/

/*int main()
{
	int num1[4] = { 1,2,3,4 };
	int num2[2][3] = { 5,6,7,8,9,0 };
	cout << aver(num1) << endl;
	return 0;
}*/
///*
#include<iostream>
#include<cmath>
#include<iomanip>
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
		x1++;
		x2++;
		y1++;
		y2++;
	}
	d = sqrt(sum);
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << d;
	return 0;
}
//*/