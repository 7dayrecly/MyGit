#include<iostream>
#include <string>
using namespace std;
enum ItemType
{
	ITEMTYPE_SWORD,
	ITEMTYPE_TORCH,
	ITEMTYPE_POTION
};
/*string getltemName(ItemType itemType)
{
	if (itemType == ITEMTYPE_SWORD)
		return std::string("Sword");
	if (itemType == ITEMTYPE_TORCH)
		return std::string("Torch");
	if (itemType == ITEMTYPE_POTION)
		return std::string("Potion");
}*/
struct person
{
	int num;
	char name[10];
	char sex;
	char job; //人员的类别 
	union  //无名联合作为结构体的内嵌成员 
	{
		int classes;  //为学生存放班级 
		char position[10]; //为教师存放职称 
	};
} p[2];
int main()
{
/*
	char array[20] = "hello\0\t world!";
	cout << strlen(array) << endl;
	cout << sizeof(array) << endl;
	cout << array;
*/
/*/
	int n[2] = { 0 }, i, j, k = 2;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			n[j] = n[i] + 1;
		}
	}
	cout << n[j - 2] << endl;
*/
/*/
	ItemType itemType(ITEMTYPE_TORCH);
	std::cout << "You are carrying a " <<  getltemName(itemType) << "\n";
*/
/*
	enum weekday { sun, mon, tue, wed, thu, fri, sat };
	cout << "今天是星期（请输入一个数0-6）：";
	int n;
	cin >> n;
	weekday today = (weekday)n;
	weekday thatday = (weekday)((today + 10) % 7);
	switch (thatday)
	{
	case sun:
		cout << "Thatday is Sunday." << endl;
		break;
	case mon:
		cout << " Thatday is Monday." << endl;
		break;
	case tue:
		cout << " Thatday is Tuesday." << endl;
		break;
	case wed:
		cout << " Thatday is Wednesday." << endl;
		break;
	case thu:
		cout << " Thatday is Thursday." << endl;
		break;
	case fri:
		cout << " Thatday is Friday." << endl;
		break;
	case sat:
		cout << " Thatday is Saturday." << endl;
		break;
	default:
		cout << "input error!" << endl;
	}
*/
/*/
	int i;
	for (i = 0; i < 2; i++)
	{
		cin >> p[i].num >> p[i].name >> p[i].sex >> p[i].job;
		if (p[i].job == 's')
			cin >> p[i].classes;
		else if (p[i].job == 't')
			cin >> p[i].position;
		else
			cout << "input error!" << endl;
	}
	for (i = 0; i < 2; i++) //按学生或教师显示信息 
	{
		if (p[i].job == 's')
			cout << p[i].name << " is a student of class"
			<< p[i].classes << "." << endl;
		else if (p[i].job == 't')
			cout << p[i].name << " is a teacher, he is a"
			<< p[i].position << ".\n";
	}
	*/




	return 0;


}