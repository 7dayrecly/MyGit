#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main()
{
//冒泡序列。
/*	const int Size = 10;
	int num[Size] = { 2,5,4,9,1,8,6,7,10,3 };
	int i = 0, hold;
	int pos, bound;
	cout << "请输入十个整数：" << endl;
	while (cin >> num[i])
	{
		i++;
	}
	cout << "Origin: ";
	for (i = 0; i < Size; i++)
		cout << setw(4) << num[i];
	pos = Size - 1;
	while (pos)
	{
		bound = pos; //bound为上轮交换的位置。
		pos = 0;
		for (i = 0; i < bound; i++) //i从上轮发生交换的最大位置开始，以下的位置已经排序好了。
		{
			if (num[i] > num[i + 1])
			{
				hold = num[i];
				num[i] = num[i + 1];
				num[i + 1] = hold;
				pos = i;      //记录此刻交换的数字所在位置。
			}
		}
	}
	cout << "\nOrder: ";
	for (i = 0; i < Size; i++)
		cout << setw(4) << num[i];
	cout << endl;
*/
	
//4.12
/*	int num[100];
	ofstream ofile;
	ofile.open("d:\\C++file\\Data.text.txt", ios::binary | ios::app);
	for (int i = 0; i < 100; i++)
	{
		num[i] = i + 1;
		ofile << num[i] << endl;
	}
	ofile.close();
*/

//4.13
/*	ifstream ifile("d:\\C++file\\Data.text.txt");
	int num[100];
	for (int i = 0; i < 100; i++)
	{
		ifile >> num[i];
		cout << num[i] << endl;
	}
*/

//4.14
/*	int cus[100] = {0};
	int i = 0, a = 0;
	float sum = 0, adv;
	while (cin >> a)
	{
		cus[i] = a;
		i++;
	}
	for (i = 0; cus[i] != 0; i++)
	{
		sum += cus[i];
		adv = sum / i;
	}
	for (i = 0; cus[i] != 0; i++)
	{
		cout << "顾客" << i << "  " << cus[i] << endl;
	}
	cout << "总购买额为" << sum << ",平均购买额为" << adv << endl;
*/

//4.18
/*	struct item
	{
		char PartNo[8];
		char desc[20];
		float price;
		int stockID;
	}inventory[100];

	inventory[32].price = 12.33; //(1)
	inventory[11].PartNo[0] = 'X'; //(2)
	inventory[96] = { {1,2,2,3,4,4,5,6},{0},6.66,666 };
	inventory[11] = inventory[96];
	cout << inventory[11].price;
*/

//4.19(有问题）
/*	struct student
	{
		char name[20];
		bool sex;
		int age;
		int num;
	}students[30];
	cout << "请输入姓名、性别、年龄、学号：" << endl;
	for (int i = 0; i < 30; i++)
	{
		cin >> students[i].name >> students[i].sex >> students[i].age >> students[i].num;
		cout << students[i].name << " " << students[i].sex << " " << students[i].age << " " << students[i].num << endl;
	}
	ofstream ofile;
	ofile.open("d:\\C++file\\Students data.txt", ios::binary | ios::app);
	for (int i = 0; i < 30; i++)
		ofile << students[i].name << " " << students[i].sex << " " << students[i].age << " " << students[i].num << endl;
*/

	return 0;
}