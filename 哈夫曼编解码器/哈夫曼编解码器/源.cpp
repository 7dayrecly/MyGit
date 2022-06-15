#include"Huffman.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void init(string message, vector<int> &a, vector<char> &name, int &n);

int main()
{
	string message;
	vector<int> a;
	vector<char> name;
	int n = 0;
	
	//message = "I love data Structure and I love Computer.I will try my best to study data Structure.";
	//encode = "I am a student"
	//decode = "011111110110001111110110111010001001100110111010010111100"
	
	cout << "请输入句子生成Haffman表。" << endl;

	getline(cin, message);
	init(message, a, name, n);
	
	
	Huffman huffman;
	huffman.CreateHTree(a, n, name);
	huffman.CreateCodeTable();
	
	
	string decode;

	while (1)
	{
		int a;
		cout << "请输入指令：1为输出编码表，2为编码，3为译码，否则为退出。" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			huffman.PrintHCode();
			break; 
		}
		case 2:
		{
			cout << "请输入句子。" << endl;
			string encode;
			cin.ignore();
			getline(cin, encode);
			huffman.Encode(encode);
			break; 
		}
		case 3:
		{
			cout << "请输入编码。" << endl;
			string decode;
			cin.ignore();
			getline(cin, decode);
			huffman.Decode(decode, "");
			break; 
		}
		default:
			goto end;
		}
	}

	end:
	return 0;
}

void init(string message, vector<int> &a, vector<char> &name, int &n)
{
	int asc[128] = { 0 };
	int len = message.length();

	for (int i = 0; i < len; i++)
	{
		char name = message[i];
		asc[name]++;//对应ASCII码位置加一
	}

	for (int i = 0; i < 128; i++)
	{
		if (asc[i] != 0)
		{
			n++;
			a.push_back(asc[i]);
			name.push_back(i);
		}
	}
}