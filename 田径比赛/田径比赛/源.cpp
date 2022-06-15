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
	int Index;   //对应运动的编号
	int degree;  //对应运动的度
	int mark;    //对应运动的颜色
};

bool cmp(Node a, Node b)
{
	return a.degree > b.degree;
}

void Cout(int n)//输出运动项目
{
	switch (n+1)
	{
	case 1: cout << "跳高 "; break;
	case 2: cout << "跳远 "; break;
	case 3: cout << "100米跑 "; break;
	case 4: cout << "200米跑 "; break;
	case 5: cout << "铁饼 "; break;
	case 6: cout << "铅球 "; break;
	case 7: cout << "标枪 "; break;
	}
}

int fillcolor(int map[], int n, vector<int> &mark, vector<Node> &node)
{
	int countMark = 0;
	
	node.resize(n);
	
	//node[i].Index
	
	for (int i = 0; i < n; i++)//初始化，并计算每个节点的度
	{
		node[i].degree = node[i].mark = 0;
		node[i].Index = i;
		for (int j = 0; j < n; j++)
		{
			if (map[i*n + j] == 1) node[i].degree++;
		}
	}

	sort(node.begin(), node.end(), cmp);//对数据按度由大到小进行排序
	

	for (int i = 0; i < n; i++)
	{
		//该算法大致想法，即先对节点进行染色，如果该节点与之前存在被染同样色的节点相邻时，取消该染色
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
		//对于传下来的数据，如果当前的mark为0，不是未曾染色就是染色后被取消，该数据需要创新一个颜色来表示。
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
	
	cout << "比赛要进行" << n << "天。" << endl;
	
	//输出比赛日程表
	cout << "比赛日程为：" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "第" << i << "天:\n";
		for (int j = 0; j < node.size(); j++)
		{
			if (node[j].mark == i)
				Cout(node[j].Index);
		}
		cout << endl;
	}

	return 0;
}

