#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct HNode
{
	int weight;
	int parent;
	int LChild;
	int RChild;
};

struct HCode
{
	char data;
	string code;
};

class Huffman
{
private:
	HNode *HTree;
	HCode *HCodeTable;
	int N;
	void code(int i, string newcode);

public:
	void CreateHTree(vector<int> &a, int n, vector<char> &name);
	void CreateCodeTable();
	void SelectMin(int *x, int *y, int n);
	void Encode(string message);
	void Decode(string secret, string information);
	void CalLong();
	void PrintHTree();
	void PrintHCode();
	~Huffman();
};

