#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define minum 0x3f3f3f3f
struct HNode
{
	int weight;    //���Ȩֵ
	int parent;    //˫�������±�
	int LChild;    //���������±�
	int RChild;    //�Һ��������±�
};
struct HCode
{
	char data;
	string code;
};
class Huffman
{
private:
	HNode*HTree;         //��������
	HCode *HCodeTable;  //��������
	int N;              //Ҷ�ӽ������
	void code(int i, string newcode);
public:
	//void CreateHTree(int a[], int n, char name[]);//������������
	void CreateHTree(vector<int> &a, int n, vector<char> &name);
	void CreateCodeTable();                       //���������
	void Encode(string s, char*d);                 //����
	void Decode(char *s, char*d);                  //����
	void SelectMin(int &x, int &y, int m, int n);   //��m+1��n��ѡ��������Ȩֵ��С�Ľ��
	~Huffman();
};
//a[]Ϊ����ÿ���ַ���Ȩֵ��name[]Ϊ�����ַ�������
//void Huffman::CreateHTree(int a[], int n, char name[])


void Huffman::CreateHTree(vector<int> &a, int n, vector<char> &name)
{
	N = n;             //nΪ�ַ�������
	HCodeTable = new HCode[N];
	HTree = new HNode[2 * N - 1];    //����Ȩ������a[0..n-1]��ʼ����������
	for (int i = 0; i < N; i++)
	{
		HTree[i].weight = a[i];
		HTree[i].LChild = HTree[i].RChild = HTree[i].parent = -1;
		HCodeTable[i].data = name[i];
	}
	int x, y;
	for (int i = 0; i < 2 * N - 1; i++)//��ʼ����������
	{
		SelectMin(x, y, 0, i);
		HTree[x].parent = HTree[y].parent = i;
		HTree[i].weight = HTree[x].weight + HTree[y].weight;
		HTree[i].LChild = x;
		HTree[i].RChild = y;
		HTree[i].parent = -1;
		HTree[x].weight = HTree[y].weight = minum;
	}
}
void Huffman::SelectMin(int &x, int &y, int m, int n)
{
	int a = minum, b = minum;
	for (int i = m; i < n; i++)
	{
		if (HTree[i].weight < a)
		{
			a = HTree[i].weight;
			x = i;
		}
	}
	for (int i = m; i < n; i++)
	{
		if (HTree[i].weight < b)
		{
			int temp = y;
			y = i;
			if (x == y)
			{
				y = temp;
				continue;
			}
			b = HTree[i].weight;
		}
	}
}
void Huffman::code(int i, string newcode)
{
	if (HTree[i].LChild == -1)
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
void Huffman::Encode(string s, char*d)   //sΪ���봮��dΪ�������ַ���
{
	int a = 0;
	while (s[a] != '\0')
	{
		for (int i = 0; i < N; i++)
		{
			if (HCodeTable[i].data == s[a])
			{
				int k = 0;
				while (HCodeTable[i].code[k] != '\0')
				{
					k++;
				}
				for (int j = 0; j < k; j++)
				{
					*d = HCodeTable[i].code[j];
					d++;
				}
			}
		}
		a++;
	}
}
void Huffman::Decode(char* s, char*d)
{
	while (*s != '\0')
	{
		int parent = 2 * N - 2;
		while (HTree[parent].LChild != -1)
		{
			if (*s == '0')
			{
				parent = HTree[parent].LChild;
			}
			else
			{
				parent = HTree[parent].RChild;
			}
			s++;
		}
		*d = HCodeTable[parent].data;
		d++;
	}
}
Huffman::~Huffman()
{
	N = 0;
	HTree = NULL;
	HCodeTable = NULL;
}
void init(string message, vector<int> &a, vector<char> &name, int &n);
int main()
{
	cout << "�����ַ������ո����»��ߴ��棩" << endl;
	/*
	string s;
	cin >> s;

	char name[256];
	char name2[256];
	int  Time[256] ;
	int  Time2[256];
	//39Ϊ���ţ�46Ϊ��ţ�65��90�Ǵ�д��95Ϊ�ո�97��122Ϊ��д
	memset(Time, 0, sizeof(Time));
	memset(Time2, 0, sizeof(Time2));
	int len = s.length();


	int n=0;
	for (int i = 0; i < 60; i++)
	{
		if (Time2[i] != 0)
		{
			Time[n] = Time[i];
			name[n] = name2[i];
			n++;
		}
	}

	name[n] = '\0';
	*/
	string message;
	vector<int> a;
	vector<char> name;
	int n = 0;
	getline(cin, message);
	init(message, a, name, n);
	Huffman myHuffman;
	myHuffman.CreateHTree(a, n, name);
	myHuffman.CreateCodeTable();
	char *d1 = new char[n];
	char *d2 = new char[n];
	myHuffman.Encode(message, d1);
	cout << "����Ľ��Ϊ��" << endl;
	cout << d1;
	myHuffman.Decode(d1, d2);
	cout << "����Ľ��Ϊ��" << endl;
	cout << d2;
	cin >> n;
}
void init(string message, vector<int> &a, vector<char> &name, int &n)
{
	int asc[128] = { 0 };
	int len = message.length();

	for (int i = 0; i < len; i++)
	{
		char name = message[i];
		asc[name]++;
	}

	for (int i = 0; i < 128; i++)
	{
		if (asc[i] != 0)
		{
			n++;
			a.push_back(asc[i]);//��a�������Ԫ��asc��i��
			name.push_back(i);//��name�������Ԫ��i
		}
	}
}
