#include<iostream>
using namespace std;

void fuc(int n, int num);

int main()
{
	int n, num;
	cout << "n=";
	cin >> n; 
	cout << "num=";
	cin >> num;
	fuc(n, num);
	return 0;
}

void fuc(int n, int num)//nΪ��λ�ƣ�numΪʮ��������
{
	if (num >= n)//�õݹ麯������num����n��num��ֵΪnum/n���ݸ��ݹ����һ�κ�����
	{
		fuc(n, num / n);
	}
	//���num%n����ʱnum%n��Ϊ������λ���µ�ĳλ��
	//��num����С��nʱ����ʱ�ݹ鵽��ͷ����ʱ����ľ��ǵ�һλ�����������˳������������num%n��Ϊ�ڶ�λ����
	//�Դ����ơ�
	if (num % n < 10)
	{
		cout << num % n;
	}
	else
	{
		char temp;
		temp = 'A' + num % n - 10;
		cout << temp;
	}
	
}