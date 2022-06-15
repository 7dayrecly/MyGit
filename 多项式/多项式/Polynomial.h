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
	Ploynomial(vector <float> a, vector <int> b, int n);//������Ӧ�Ķ���ʽ
	Ploynomial(float a[], int b[], int n);
	int GetMaxexpn() { return maxexpn; }
	void SetMaxexpn(int n) { maxexpn = n; }
	void PrintList();
	void Insert(int i, float x);//����
	float Delete(int i);
	float Get(int i) { return data[i]; };
	int Locate(float x);//�ƺ�û�õ���
//���㶨��
	Ploynomial operator + (Ploynomial &x2);
	Ploynomial operator - (Ploynomial &x2);
	Ploynomial operator * (Ploynomial &x2);
	Ploynomial Derivation();//��
private:
	float data[N] = { 0 };
	int maxexpn;//����ʽ��ߴ�����������ʱ���á�
};

