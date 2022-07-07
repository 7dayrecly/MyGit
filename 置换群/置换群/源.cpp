#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

class group
{
private:
	vector<int> Matrix;//表示矩阵
	int length;
public:
	int Getlength() { return length; }
	int GetNum(int line, int row) { return Matrix[row*length + line]; }
	void SetNum(int line, int row, int num) { Matrix[row*length + line] = num; }
	group(int n) { length = n; Matrix.resize(n*n); fill(Matrix.begin(), Matrix.begin() + n * n, 0); }
	~group() { }
	void setgroup(vector<int> &temp);
	
	void trans(vector<int> tram, vector<int> &type);//转置
	group transposition();//逆置
	group operator *(group &other);//乘法
	group power(int n, group other);//次方
	void Print();//输出
};

void group::setgroup(vector<int> &temp)
{
	for (int i = 0; i < length; i++)
	{
		Matrix[i * length + temp[i] - 1] = 1;
	}
}

//相比起直接改矩阵，明显对数组改变要方便许多
void group::trans(vector<int> tram,vector<int> &type)
{
	int next = 0;//设置next指向下一次轮换的开始位置
	for (int i = 0; i < tram.size(); i = next)
	{	//每次i都从轮换的头部开始，保存第一个数。
		int temp = tram[i];
		for (int j = i; j < tram.size(); j++)
		{
			if (tram[j] == 0)
			{
				//已经来到了两次轮换的边界，直接跳出循环，下一次从next开始
				next = j + 1;
				break;
			}
			else
			{
				if (tram[j + 1] == 0)
				{
					//已经来到了轮换最后一个数，将第一个值赋给他。
					type[tram[j] - 1] = temp;
					continue;
				}
				else
				{
					//使下一个值赋给当前值。
					type[tram[j] - 1] = type[tram[j + 1] - 1];
				}
			}
		}
	}

}

group group::transposition()
{
	group temp(length);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			//交换行列。
			temp.SetNum(i, j, Matrix[i*length + j]);
		}
	}
	return temp;
}

group group::operator *(group &other)
{
	group temp(length);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			int sum = 0;
			for (int k = 0; k < length; k++)
			{
				sum += this->GetNum(k, i) * other.GetNum(j, k);
			}
			temp.SetNum(j, i, sum);
		}
	}
	return temp;
}

group group::power(int n, group other)
{
	if (n == 1)
		return other;
	else
	{
		n--;//运用递归方式简化式子。
		other = power(n, other) * other;
		return other;
	}
}

void group::Print()//对置换群输出
{
	for (int i = 0; i < length; i++)
	{
		cout << i+1;
	}
	cout << endl;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (Matrix[i*length + j] == 1)
				cout << j+1;
		}
	}
	cout << endl;
}

int main()
{
	cout << "请输入置换群的元数：" << endl;
	int n;
	cin >> n;

	group Group1(n);
	group Group2(n);

	int temp;
	cout << "请输入置换群σ的数：" << endl;
	vector<int> A;
	while (cin >> temp)
	{
		A.push_back(temp);
	}
	Group1.setgroup(A);

	cin.clear();
	cin.sync();

	cout << "请输入置换群τ的数：" << endl;
	vector<int> B;
	while (cin >> temp)
	{
		B.push_back(temp);
	}
	Group2.setgroup(B);

	cin.clear();
	cin.sync();

	cout << "请输入轮换表示（相邻的轮换之间用零隔开，最后用零结尾）:" << endl;
	vector<int> C = { 1,2,3,4,5 };
	vector<int> trans;
	while (cin >> temp)
	{
		trans.push_back(temp);
	}

	group Group3(n);

	cout << "生成的置换群为:" << endl;
	Group3.trans(trans, C);
	Group3.setgroup(C);
	Group3.Print();

	cout << "στ:" << endl;
	Group3 = Group1 * Group2;
	Group3.Print();

	cout << "τσ:" << endl;
	Group3 = Group2 * Group1;
	Group3.Print();

	cout << "σ^-1:" << endl;
	Group3 = Group1.transposition();
	Group3.Print();

	cout << "τ^-1:" << endl;
	Group3 = Group2.transposition();
	Group3.Print();

	cout << "σ^-1τσ:" << endl;
	Group3 = Group1.transposition()* Group2 * Group1;
	Group3.Print();

	cout << "σ^30:" << endl;
	Group3 = Group1.power(30,Group1);
	Group3.Print();

	cout << "τ^-30" << endl;
	Group3 = Group2.power(30, Group2);
	Group3 = Group3.transposition();
	Group3.Print();

	return 0;
}
