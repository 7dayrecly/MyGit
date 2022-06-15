#include "Huffman.h"
#include<iostream>
#include<string>
using namespace std;

void Huffman::CreateHTree(vector<int> &a, int n, vector<char> &name)
{
	N = n;
	HCodeTable = new HCode[N];
	HTree = new HNode[2 * N - 1];//句子中共有N个字符，相应的Haffman树有2N-1个节点。
	for (int i = 0; i < N; i++)//先输入各个字符及其权重到HTree的前N个节点中。
	{
		HTree[i].weight = a[i];
		HTree[i].LChild = HTree[i].RChild = HTree[i].parent = -1;//初始化每个节点的父亲为-1。
		HCodeTable[i].data = name[i];
	}
	int x, y;
	for (int i = n; i < 2 * N - 1; i++)
	{
		SelectMin(&x,&y,i);//从i个已经生成的节点中不重复获取权重最小的两个节点。
		HTree[x].parent = HTree[y].parent = i;
		HTree[i].weight = HTree[x].weight + HTree[y].weight;
		HTree[i].LChild = x;
		HTree[i].RChild = y;
		HTree[i].parent = -1;//新生成一个节点储存x，y两个节点的权重和。
	}
}


/*
从i个已经生成的节点中不重复获取权重最小的两个节点。
设计该算法的时候麻烦处在于以下两点。
一、由于数据特性，上次获取的最小的两个权重必定会出现在下次检索的范围内，如果不弄什么判断条件的话，每次都会重复选到同样的两个最小权重。
	这里的解决方式是通过判断该节点是否有父亲来筛除已经选择的节点。
二、由于上面的情况，再次比较的时候要筛除一些已经有父亲的节点，因此应该从哪个节点开始是个不太能确定的问题。
	但毫无疑问，每个开始的节点都应该满足一个条件，没有父亲节点，且小于n
	这里设置了两个sta1，sta2来指向要开始的节点，中途还出现了一些小插曲，下面sta2处细说。
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
	这里我的sta2是sta1+1。这么设置有一段插曲。
	由于前面sta1已经检索过，因此sta1之前的节点必定是已有父亲的节点，sta2从sta1后一个开始往后是完全合理的想法。
	但我一开始算法设置的是在定义（1）处sta2与sta1都是从零开始，然后再在sta2处增加一个 sta2 ！= sta1 条件来规避sta1与sta2相同的问题。
	结果运行的时候两个sta双双停在了第一个地方，后来检查的时候发现原来是因为 HTree[sta2].parent != -1 该条件与上另外两条条件时，
	由于满足sta1的节点该条件必定为零（因为没有父亲），导致后面两个条件无论是真是假都不影响整个条件为0，因此sta2不会加1而与sta1停在同一个位置。
*/
	while (sta2 < n && HTree[sta2].parent != -1)
	{
		sta2++;
	}

	if (HTree[sta1].weight < HTree[sta2].weight)//先比较两个开始的节点的权重大小。
	{
		min1 = sta1;
		min2 = sta2;
	}
	else
	{
		min2 = sta1;
		min1 = sta2;
	}

	for (int i = sta2 + 1; i < n; i++)//依次比较各个节点的大小
	{
		if (HTree[i].parent != -1)//去掉有父亲的
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
	if (HTree[i].LChild == -1)//判断是否为叶子节点，是则输入编码并停止，否则向下。
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

void Huffman::Encode(string message)//根据输入的内容用HCodeTable的编码编码。
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
	cout << "编码为：\n" << secret << endl;
}

void Huffman::Decode(string secret, string information)//解码
{
	int i = 0;
	while (i < secret.length())
	{
		int parent = 2 * N - 2;//每次从根节点出发
		while (HTree[parent].LChild != -1)//判断是否到达叶子节点，否则根据编码的内容继续向左或向右直至找到叶子节点。
		{
			if (secret[i] == '0')
				parent = HTree[parent].LChild;
			else
				parent = HTree[parent].RChild;
			i++;
		}
		information += HCodeTable[parent].data;//得到叶子节点的数据。
	}
	cout << "解码为：\n" << information << endl;
}

void Huffman::PrintHCode()
{
	cout << "编码表为：" << endl;
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
	cout << "Huffman树数据已释放。" << endl;
}