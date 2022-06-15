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
			throw "指数过大";
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
			throw "指数过大";
		data[b[i]] = a[i];
		if (b[i] > maxexpn)
			maxexpn = b[i];
	}
}

template<int N>
void Ploynomial<N>::PrintList()//按次数从小到大输出
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
		throw "指数过大！";
	data[i] = x;
	if (i > maxexpn)
		maxexpn = i;
}

template<int N>
float Ploynomial<N>::Delete(int i)
{
	if (i > N)
		throw "指数过大！";
	float temp = data[i];
	data[i] = 0;
	cout << "已删除x^" << i << "的系数。";
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
	cout << "不存在系数为x的项。" << endl;
	return -1;
}

template<int N>
Ploynomial<N> Ploynomial<N>::operator +(Ploynomial &x2)
{
	Ploynomial<20> temp;
	int tempmax = maxexpn >= x2.GetMaxexpn() ? maxexpn : x2.GetMaxexpn();
	//上面一步为获得多项式相加后的最高可能次数，最高可能次数的运用将减少循环的次数。
	for (int i = 0; i <= tempmax; i++)
	{
		float tempnum = data[i] + x2.Get(i);
		//对应项系数相加
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
		//对应次数相减。
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
//加减大同小异，另外后面那个获得相减后的最大次数加法应该也有，当时考虑不周。

template<int N>
Ploynomial<N> Ploynomial<N>::operator *(Ploynomial &x2)
{
	Ploynomial<20> temp;
	int tempmax = maxexpn + x2.GetMaxexpn();
	if (tempmax > N)
		throw "指数过大！";
	for (int i = 0; i <= maxexpn; i++)
	{
		for (int j = 0; j <= x2.GetMaxexpn(); j++)
		{
			float tempnum = data[i] * x2.Get(j) + temp.Get(i + j);
			//多项式的乘法为对应项数系数两两相乘的总和，由这里的表达式就能够看出该方法能够简洁地表示乘法的优越性。
			//data[i]*x2.Get(j)这一项为两个多项式的某两项之积，temp（i+j）即为计算后的对应第i+j项系数。
			//通过这样逐项地相乘相加，能够做到不漏项地算出乘法的结果。
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
	if (maxexpn == 0)//最高次数为零，也就是常数，导数为零
		return temp;
	int tempmax = maxexpn - 1;
	for (int i = 1; i <= maxexpn; i++)
	{
		float tempnum = data[i] * i;//求导时系数乘以次数。
		temp.Insert(i - 1, tempnum);//多项式求导后次数减一。
	}
	temp.SetMaxexpn(tempmax);
	return temp;
}