#include "Polynomial.h"
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

template<int N>
Ploynomial<N>::Ploynomial(Ploynomial &x)
{
	maxexpn = x.GetMaxexpn();
	for (int i = 0; i <= maxexpn; i++)
	{
		data[i] = x.Get(i);
	}
}

template<int N>
Ploynomial<N>::Ploynomial(vector <float> a, vector <int> b, int n)
{
	maxexpn = b[0];
	for (int i = 0; i < n; i++)
	{
		if (b[i] > N)
			throw "ָ������";
		data[b[i]] = a[i];
		if (b[i] > maxexpn)
			maxexpn = b[i];
	}
}

template<int N>
Ploynomial<N>::Ploynomial(float a[], int b[], int n)
{
	maxexpn = b[0];
	for (int i = 0; i < n; i++)
	{
		if (b[i] > N)
			throw "ָ������";
		data[b[i]] = a[i];
		if (b[i] > maxexpn)
			maxexpn = b[i];
	}
}

template<int N>
void Ploynomial<N>::PrintList()//��������С�������
{
	cout << setiosflags(ios::fixed);
	for (int i = 0; i <= maxexpn; i++)
	{
		if (i < maxexpn && data[i] != 0)
			cout << setprecision(2) << "(" << data[i] << ")x^" << i << " +";
		else if (i == maxexpn)
			cout << setprecision(2) << "(" << data[i] << ")x^" << i << endl;
	}
}

template<int N>
void Ploynomial<N>::Insert(int i, float x)
{
	if (i > N)
		throw "ָ������";
	data[i] = x;
	if (i > maxexpn)
		maxexpn = i;
}

template<int N>
float Ploynomial<N>::Delete(int i)
{
	if (i > N)
		throw "ָ������";
	float temp = data[i];
	data[i] = 0;
	cout << "��ɾ��x^" << i << "��ϵ����";
	return temp;
}

template<int N>
int Ploynomial<N>::Locate(float x)
{
	for (int i = 0; i <= maxexpn; i++)
	{
		if (data[i] == x)
			return i;
	}
	cout << "������ϵ��Ϊx���" << endl;
	return -1;
}

template<int N>
Ploynomial<N> Ploynomial<N>::operator +(Ploynomial &x2)
{
	Ploynomial<20> temp;
	int tempmax = maxexpn >= x2.GetMaxexpn() ? maxexpn : x2.GetMaxexpn();
	//����һ��Ϊ��ö���ʽ��Ӻ����߿��ܴ�������߿��ܴ��������ý�����ѭ���Ĵ�����
	for (int i = 0; i <= tempmax; i++)
	{
		float tempnum = data[i] + x2.Get(i);
		//��Ӧ��ϵ�����
		temp.Insert(i, tempnum);
	}
	temp.SetMaxexpn(tempmax);
	return temp;
}

template<int N>
Ploynomial<N> Ploynomial<N>::operator -(Ploynomial &x2)
{
	Ploynomial<20> temp;
	int tempmax = maxexpn >= x2.GetMaxexpn() ? maxexpn : x2.GetMaxexpn();
	for (int i = 0; i <= tempmax; i++)
	{
		float tempnum = data[i] - x2.Get(i);
		//��Ӧ���������
		temp.Insert(i, tempnum);
	}
	for (int i = tempmax; i >= 0; i--)
	{
		if (temp.Get(i) == 0)
			tempmax--;
		else
			break;
	}
	temp.SetMaxexpn(tempmax);
	return temp;
}
//�Ӽ���ͬС�죬��������Ǹ�����������������ӷ�Ӧ��Ҳ�У���ʱ���ǲ��ܡ�

template<int N>
Ploynomial<N> Ploynomial<N>::operator *(Ploynomial &x2)
{
	Ploynomial<20> temp;
	int tempmax = maxexpn + x2.GetMaxexpn();
	if (tempmax > N)
		throw "ָ������";
	for (int i = 0; i <= maxexpn; i++)
	{
		for (int j = 0; j <= x2.GetMaxexpn(); j++)
		{
			float tempnum = data[i] * x2.Get(j) + temp.Get(i + j);
			//����ʽ�ĳ˷�Ϊ��Ӧ����ϵ��������˵��ܺͣ�������ı��ʽ���ܹ������÷����ܹ����ر�ʾ�˷�����Խ�ԡ�
			//data[i]*x2.Get(j)��һ��Ϊ��������ʽ��ĳ����֮����temp��i+j����Ϊ�����Ķ�Ӧ��i+j��ϵ����
			//ͨ����������������ӣ��ܹ�������©�������˷��Ľ����
			temp.Insert(i + j, tempnum);
		}
	}
	temp.SetMaxexpn(tempmax);
	return temp;
}

template<int N>
Ploynomial<N> Ploynomial<N>::Derivation()
{
	Ploynomial<20> temp;
	if (maxexpn == 0)//��ߴ���Ϊ�㣬Ҳ���ǳ���������Ϊ��
		return temp;
	int tempmax = maxexpn - 1;
	for (int i = 1; i <= maxexpn; i++)
	{
		float tempnum = data[i] * i;//��ʱϵ�����Դ�����
		temp.Insert(i - 1, tempnum);//����ʽ�󵼺������һ��
	}
	temp.SetMaxexpn(tempmax);
	return temp;
}