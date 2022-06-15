#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

template<int N>
class Ploynomial
{
public:
	Ploynomial() { maxexpn = 0; }
	Ploynomial(Ploynomial &x);
	Ploynomial(vector <float> a, vector <int> b, int n);//生成相应的多项式
	Ploynomial(float a[], int b[], int n);
	int GetMaxexpn() { return maxexpn; }
	void SetMaxexpn(int n) { maxexpn = n; }
	void PrintList();
	void Insert(int i, float x);//插入
	float Delete(int i);
	float Get(int i) { return data[i]; };
	int Locate(float x);//似乎没用到。
//运算定义
	Ploynomial operator + (Ploynomial &x2);
	Ploynomial operator - (Ploynomial &x2);
	Ploynomial operator * (Ploynomial &x2);
	Ploynomial Derivation();//求导
private:
	float data[N] = { 0 };
	int maxexpn;//多项式最高次数，在运算时有用。
};

