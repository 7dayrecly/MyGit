#include<iostream>
using namespace std;

void pp(int a, int *b);
//int *p;
int main()
{
	
	/*
	int a = 1, b = 2, c = 3;
	p = &b;
	pp(a + c, &b);
	cout << a << "\t " << b << "\t " << c << "\t " << *p << endl;
	*/

	//�ѵ㡣
	/*
	const char *  member_name[] = { "Merry", "John", "Hill" };

	cout << "The namelist show as:\n";
	for (int i = 0; i < 3; ++i)
	{
		cout << member_name[i] << '\n';
		cout << *(member_name + i) << '\n';

		cout << member_name << '\n';
		cout << *member_name << '\n';

		cout << *member_name[i] << '\n';

	}
	*/
//ָ�����ҡ�
	//char *pch1, *pch2;
	//pch1 = new char('A');
	//pch2 = pch1;
	//*pch2 = 'B';
	//delete  pch1;
	//*pch2 = 'c';
	////*pch2 = 'd';
	//cout << *pch2 << endl;
	//delete  pch2;//�Ƿ������ڴ棬����ϵͳǿ��ֹͣӦ�ó���


	return 0;
}

/*
void pp(int a, int *b)
{
	int c = 4;
	*p = *b + c;
	a = *p - c;
	cout << "in pp procedure, :" << a << "and" << *b << "and" << *p << endl;
}
*/