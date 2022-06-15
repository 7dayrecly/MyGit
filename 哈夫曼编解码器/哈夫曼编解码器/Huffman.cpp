#include "Huffman.h"
#include<iostream>
#include<string>
using namespace std;

void Huffman::CreateHTree(vector<int> &a, int n, vector<char> &name)
{
	N = n;
	HCodeTable = new HCode[N];
	HTree = new HNode[2 * N - 1];//�����й���N���ַ�����Ӧ��Haffman����2N-1���ڵ㡣
	for (int i = 0; i < N; i++)//����������ַ�����Ȩ�ص�HTree��ǰN���ڵ��С�
	{
		HTree[i].weight = a[i];
		HTree[i].LChild = HTree[i].RChild = HTree[i].parent = -1;//��ʼ��ÿ���ڵ�ĸ���Ϊ-1��
		HCodeTable[i].data = name[i];
	}
	int x, y;
	for (int i = n; i < 2 * N - 1; i++)
	{
		SelectMin(&x,&y,i);//��i���Ѿ����ɵĽڵ��в��ظ���ȡȨ����С�������ڵ㡣
		HTree[x].parent = HTree[y].parent = i;
		HTree[i].weight = HTree[x].weight + HTree[y].weight;
		HTree[i].LChild = x;
		HTree[i].RChild = y;
		HTree[i].parent = -1;//������һ���ڵ㴢��x��y�����ڵ��Ȩ�غ͡�
	}
}


/*
��i���Ѿ����ɵĽڵ��в��ظ���ȡȨ����С�������ڵ㡣
��Ƹ��㷨��ʱ���鷳�������������㡣
һ�������������ԣ��ϴλ�ȡ����С������Ȩ�رض���������´μ����ķ�Χ�ڣ������Ūʲô�ж������Ļ���ÿ�ζ����ظ�ѡ��ͬ����������СȨ�ء�
	����Ľ����ʽ��ͨ���жϸýڵ��Ƿ��и�����ɸ���Ѿ�ѡ��Ľڵ㡣
�������������������ٴαȽϵ�ʱ��Ҫɸ��һЩ�Ѿ��и��׵Ľڵ㣬���Ӧ�ô��ĸ��ڵ㿪ʼ�Ǹ���̫��ȷ�������⡣
	���������ʣ�ÿ����ʼ�Ľڵ㶼Ӧ������һ��������û�и��׽ڵ㣬��С��n
	��������������sta1��sta2��ָ��Ҫ��ʼ�Ľڵ㣬��;��������һЩС����������sta2��ϸ˵��
*/
void Huffman::SelectMin(int *x,int *y,int n)
{
	int min1, min2, sta1 = 0, sta2;/*(1)*/

	while (HTree[sta1].parent != -1 && sta1 < n)
	{
		sta1++;
	}
	sta2 = sta1 + 1;
/*
	�����ҵ�sta2��sta1+1����ô������һ�β�����
	����ǰ��sta1�Ѿ������������sta1֮ǰ�Ľڵ�ض������и��׵Ľڵ㣬sta2��sta1��һ����ʼ��������ȫ������뷨��
	����һ��ʼ�㷨���õ����ڶ��壨1����sta2��sta1���Ǵ��㿪ʼ��Ȼ������sta2������һ�� sta2 ��= sta1 ���������sta1��sta2��ͬ�����⡣
	������е�ʱ������sta˫˫ͣ���˵�һ���ط�����������ʱ����ԭ������Ϊ HTree[sta2].parent != -1 ����������������������ʱ��
	��������sta1�Ľڵ�������ض�Ϊ�㣨��Ϊû�и��ף������º��������������������Ǽٶ���Ӱ����������Ϊ0�����sta2�����1����sta1ͣ��ͬһ��λ�á�
*/
	while (sta2 < n && HTree[sta2].parent != -1)
	{
		sta2++;
	}

	if (HTree[sta1].weight < HTree[sta2].weight)//�ȱȽ�������ʼ�Ľڵ��Ȩ�ش�С��
	{
		min1 = sta1;
		min2 = sta2;
	}
	else
	{
		min2 = sta1;
		min1 = sta2;
	}

	for (int i = sta2 + 1; i < n; i++)//���αȽϸ����ڵ�Ĵ�С
	{
		if (HTree[i].parent != -1)//ȥ���и��׵�
			continue;
		if (HTree[i].weight < HTree[min1].weight)
		{
			min2 = min1;
			min1 = i;
		}
		else if (HTree[i].weight >= HTree[min1].weight && HTree[i].weight < HTree[min2].weight)
		{
			min2 = i;
		}
	}
	*x = min1;
	*y = min2;
}

void Huffman::code(int i, string newcode)
{
	if (HTree[i].LChild == -1)//�ж��Ƿ�ΪҶ�ӽڵ㣬����������벢ֹͣ���������¡�
	{
		HCodeTable[i].code = newcode;
		return;
	}
	code(HTree[i].LChild, newcode + "0");
	code(HTree[i].RChild, newcode + "1");
}

void Huffman::CreateCodeTable()
{
	code(2 * N - 2, "");
}

void Huffman::Encode(string message)//���������������HCodeTable�ı�����롣
{
	string secret = "";
	for (int j = 0; j < message.length(); j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (message[j] == HCodeTable[i].data)
				secret += HCodeTable[i].code;
		}
	}
	cout << "����Ϊ��\n" << secret << endl;
}

void Huffman::Decode(string secret, string information)//����
{
	int i = 0;
	while (i < secret.length())
	{
		int parent = 2 * N - 2;//ÿ�δӸ��ڵ����
		while (HTree[parent].LChild != -1)//�ж��Ƿ񵽴�Ҷ�ӽڵ㣬������ݱ�������ݼ������������ֱ���ҵ�Ҷ�ӽڵ㡣
		{
			if (secret[i] == '0')
				parent = HTree[parent].LChild;
			else
				parent = HTree[parent].RChild;
			i++;
		}
		information += HCodeTable[parent].data;//�õ�Ҷ�ӽڵ�����ݡ�
	}
	cout << "����Ϊ��\n" << information << endl;
}

void Huffman::PrintHCode()
{
	cout << "�����Ϊ��" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << HCodeTable[i].data << ":" << HCodeTable[i].code << endl;
	}
}

void Huffman::CalLong()
{

}

Huffman::~Huffman()
{
	delete[]HCodeTable;
	delete[]HTree;
	cout << "Huffman���������ͷš�" << endl;
}