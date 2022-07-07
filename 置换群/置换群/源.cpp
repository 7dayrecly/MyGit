#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

class group
{
private:
	vector<int> Matrix;//��ʾ����
	int length;
public:
	int Getlength() { return length; }
	int GetNum(int line, int row) { return Matrix[row*length + line]; }
	void SetNum(int line, int row, int num) { Matrix[row*length + line] = num; }
	group(int n) { length = n; Matrix.resize(n*n); fill(Matrix.begin(), Matrix.begin() + n * n, 0); }
	~group() { }
	void setgroup(vector<int> &temp);
	
	void trans(vector<int> tram, vector<int> &type);//ת��
	group transposition();//����
	group operator *(group &other);//�˷�
	group power(int n, group other);//�η�
	void Print();//���
};

void group::setgroup(vector<int> &temp)
{
	for (int i = 0; i < length; i++)
	{
		Matrix[i * length + temp[i] - 1] = 1;
	}
}

//�����ֱ�Ӹľ������Զ�����ı�Ҫ�������
void group::trans(vector<int> tram,vector<int> &type)
{
	int next = 0;//����nextָ����һ���ֻ��Ŀ�ʼλ��
	for (int i = 0; i < tram.size(); i = next)
	{	//ÿ��i�����ֻ���ͷ����ʼ�������һ������
		int temp = tram[i];
		for (int j = i; j < tram.size(); j++)
		{
			if (tram[j] == 0)
			{
				//�Ѿ������������ֻ��ı߽磬ֱ������ѭ������һ�δ�next��ʼ
				next = j + 1;
				break;
			}
			else
			{
				if (tram[j + 1] == 0)
				{
					//�Ѿ��������ֻ����һ����������һ��ֵ��������
					type[tram[j] - 1] = temp;
					continue;
				}
				else
				{
					//ʹ��һ��ֵ������ǰֵ��
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
			//�������С�
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
		n--;//���õݹ鷽ʽ��ʽ�ӡ�
		other = power(n, other) * other;
		return other;
	}
}

void group::Print()//���û�Ⱥ���
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
	cout << "�������û�Ⱥ��Ԫ����" << endl;
	int n;
	cin >> n;

	group Group1(n);
	group Group2(n);

	int temp;
	cout << "�������û�Ⱥ�ҵ�����" << endl;
	vector<int> A;
	while (cin >> temp)
	{
		A.push_back(temp);
	}
	Group1.setgroup(A);

	cin.clear();
	cin.sync();

	cout << "�������û�Ⱥ�ӵ�����" << endl;
	vector<int> B;
	while (cin >> temp)
	{
		B.push_back(temp);
	}
	Group2.setgroup(B);

	cin.clear();
	cin.sync();

	cout << "�������ֻ���ʾ�����ڵ��ֻ�֮�������������������β��:" << endl;
	vector<int> C = { 1,2,3,4,5 };
	vector<int> trans;
	while (cin >> temp)
	{
		trans.push_back(temp);
	}

	group Group3(n);

	cout << "���ɵ��û�ȺΪ:" << endl;
	Group3.trans(trans, C);
	Group3.setgroup(C);
	Group3.Print();

	cout << "�Ҧ�:" << endl;
	Group3 = Group1 * Group2;
	Group3.Print();

	cout << "�Ӧ�:" << endl;
	Group3 = Group2 * Group1;
	Group3.Print();

	cout << "��^-1:" << endl;
	Group3 = Group1.transposition();
	Group3.Print();

	cout << "��^-1:" << endl;
	Group3 = Group2.transposition();
	Group3.Print();

	cout << "��^-1�Ӧ�:" << endl;
	Group3 = Group1.transposition()* Group2 * Group1;
	Group3.Print();

	cout << "��^30:" << endl;
	Group3 = Group1.power(30,Group1);
	Group3.Print();

	cout << "��^-30" << endl;
	Group3 = Group2.power(30, Group2);
	Group3 = Group3.transposition();
	Group3.Print();

	return 0;
}
