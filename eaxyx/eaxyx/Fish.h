#pragma once
#include<graphics.h>
//#include"easyx.h"


class Fish
{
protected:
	int hight;   //���ͼƬ����
	int weight;  //Ӣ�ﲻ�ã�ò�ư�wide�����weight (-_-")��heightҲ�����...
	int _x;
	int _y;
	int size;
	int twards;
	IMAGE picture[2]; //������涨0Ϊԭͼ��1Ϊ����ͼ��

public:
	Fish(int x, int y, int Size);//����player��ʼ��
	Fish();
	~Fish();
	
	void Move(IMAGE *back, int seed, int direction[6][2], int turn[6][2]);//��Ҫ�ǿ��Ʊ�����ƶ�
	void PrintFish(int direction); //�����ͼ
	void SetfishPicture(int level);
	void Setfish(int i);
	void DestoryFish() { size = 0; hight = 0; weight = 0; } //�Ӵ��������㣬������ɾ������ֻ�ǳ�ʼ������sizeʹ���޷����ͼ��

	int JudgeWall(int direction);//�ж�ײǽ
	bool JudgeTouch(int x, int y, int H, int W);//�ж�������
	bool JudgeSize(int size);

	int Getsize() { return size; }
	int GetX() { return _x; }
	int GetY() { return _y; }
	int Gethight() { return hight; }
	int Getweight() { return weight; }

};

