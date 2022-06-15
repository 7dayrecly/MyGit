#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[] =
{
	0,1,0,0,0,1,0,
	1,0,1,0,0,0,1,
	0,1,0,1,0,0,0,
	0,0,1,0,1,0,0,
	0,0,0,1,0,0,1,
	1,0,0,0,0,0,1,
	0,1,0,0,1,1,0
};

struct Node
{
	int Index;   //��Ӧ�˶��ı��
	int degree;  //��Ӧ�˶��Ķ�
	int mark;    //��Ӧ�˶�����ɫ
};

bool cmp(Node a, Node b)
{
	return a.degree > b.degree;
}

void Cout(int n)//����˶���Ŀ
{
	switch (n+1)
	{
	case 1: cout << "���� "; break;
	case 2: cout << "��Զ "; break;
	case 3: cout << "100���� "; break;
	case 4: cout << "200���� "; break;
	case 5: cout << "���� "; break;
	case 6: cout << "Ǧ�� "; break;
	case 7: cout << "��ǹ "; break;
	}
}

int fillcolor(int map[], int n, vector<int> &mark, vector<Node> &node)
{
	int countMark = 0;
	
	node.resize(n);
	
	//node[i].Index
	
	for (int i = 0; i < n; i++)//��ʼ����������ÿ���ڵ�Ķ�
	{
		node[i].degree = node[i].mark = 0;
		node[i].Index = i;
		for (int j = 0; j < n; j++)
		{
			if (map[i*n + j] == 1) node[i].degree++;
		}
	}

	sort(node.begin(), node.end(), cmp);//�����ݰ����ɴ�С��������
	

	for (int i = 0; i < n; i++)
	{
		//���㷨�����뷨�����ȶԽڵ����Ⱦɫ������ýڵ���֮ǰ���ڱ�Ⱦͬ��ɫ�Ľڵ�����ʱ��ȡ����Ⱦɫ
		for (int j = 0; j < mark.size(); j++)
		{
			if (node[i].mark == 0)
				node[i].mark = mark[j];
			for (int k = 0; k < n; k++)
			{
				if (map[node[i].Index * n + node[k].Index] == 1 && node[k].mark == node[i].mark)
					node[i].mark = 0;
			}
		}
		//���ڴ����������ݣ������ǰ��markΪ0������δ��Ⱦɫ����Ⱦɫ��ȡ������������Ҫ����һ����ɫ����ʾ��
		if (node[i].mark == 0)
		{
			mark.push_back(++countMark);
			node[i].mark = mark.back();
		}
		
	}

	return countMark;
}


int main()
{
	

	vector<int> mark;
	vector<Node> node;
	int n = fillcolor(map, 7, mark, node);
	
	cout << "����Ҫ����" << n << "�졣" << endl;
	
	//��������ճ̱�
	cout << "�����ճ�Ϊ��" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "��" << i << "��:\n";
		for (int j = 0; j < node.size(); j++)
		{
			if (node[j].mark == i)
				Cout(node[j].Index);
		}
		cout << endl;
	}

	return 0;
}

