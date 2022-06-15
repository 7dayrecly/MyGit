#include<iostream>
#include<iomanip>
#include<vector>
#include <stdio.h>
#include "Polynomial.cpp"
//#include"Polynomial.h"
using namespace std;

int main()
{
	//float x1[3] = { 1,2,3 }, x2[4] = { 2,5,6,3 };
	//int e1[3] = { 3,5,1 }, e2[4] = { 2,3,6,4 };
	
	vector <float> x1, x2;
	vector <int> e1, e2;

	
	int tempexpn;
	float tempnum;
	cout << "请输入第一个多项式的系数：" << endl;
 	while (cin >> tempnum)
	{
		x1.push_back(tempnum);
		//if (cin.get() == '/n')
		//		break;
	}
	
	cin.clear();
	cin.sync();
	//cout << cin.rdstate();
	//cin >> tempexpn;

	cout << "请输入第一个多项式的次数：" << endl;
	while (cin >> tempexpn)
	{
		
		e1.push_back(tempexpn);
		//if (cin.get() == '/n')
		//	break;
	}
	cin.clear();
	cin.sync();

	cout << "请输入第二个多项式的系数：" << endl;
	while (cin >> tempnum)
	{
		x2.push_back(tempnum);
		//if (cin.get() == '/n')
		//	break;
	}
	cin.clear();
	cin.sync();

	cout << "请输入第一个多项式的次数：" << endl;
	while (cin >> tempexpn)
	{
		e2.push_back(tempexpn);
		//if (cin.get() == '/n')
		//	break;
	}
	cin.clear();
	cin.sync();
	
	
	Ploynomial<20> f1(x1, e1, x1.size());
	Ploynomial<20> f2(x2, e2, x2.size());
	//Ploynomial<20> f1(x1, e1, 3);
	//Ploynomial<20> f2(x2, e2, 4);
	cout << "f1为："; f1.PrintList();
	cout << "f2为："; f2.PrintList();
	
	Ploynomial<20> f3;
	//显示各种运算
	cout << "加法" << endl;
	f3 = f1 + f2;
	f3.PrintList();

	cout << "减法" << endl;
	f3 = f1 - f2;
	f3.PrintList();

	cout << "乘法" << endl;
	f3 = f1 * f2;
	f3.PrintList();

	cout << "求导" << endl;
	f3 = f1.Derivation();
	cout << "f1求导为："; f3.PrintList();
	f3 = f2.Derivation();
	cout << "f2求导为："; f3.PrintList();

	return 0;
}