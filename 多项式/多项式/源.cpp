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
	cout << "�������һ������ʽ��ϵ����" << endl;
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

	cout << "�������һ������ʽ�Ĵ�����" << endl;
	while (cin >> tempexpn)
	{
		
		e1.push_back(tempexpn);
		//if (cin.get() == '/n')
		//	break;
	}
	cin.clear();
	cin.sync();

	cout << "������ڶ�������ʽ��ϵ����" << endl;
	while (cin >> tempnum)
	{
		x2.push_back(tempnum);
		//if (cin.get() == '/n')
		//	break;
	}
	cin.clear();
	cin.sync();

	cout << "�������һ������ʽ�Ĵ�����" << endl;
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
	cout << "f1Ϊ��"; f1.PrintList();
	cout << "f2Ϊ��"; f2.PrintList();
	
	Ploynomial<20> f3;
	//��ʾ��������
	cout << "�ӷ�" << endl;
	f3 = f1 + f2;
	f3.PrintList();

	cout << "����" << endl;
	f3 = f1 - f2;
	f3.PrintList();

	cout << "�˷�" << endl;
	f3 = f1 * f2;
	f3.PrintList();

	cout << "��" << endl;
	f3 = f1.Derivation();
	cout << "f1��Ϊ��"; f3.PrintList();
	f3 = f2.Derivation();
	cout << "f2��Ϊ��"; f3.PrintList();

	return 0;
}