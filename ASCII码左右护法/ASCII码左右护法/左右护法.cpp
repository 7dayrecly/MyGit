#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	char cha;
	int asc,i = 1;
	while (cin >> cha)
	{
		asc = cha;
		if (i % 2 == 1)
		{
			cout <<  setw(4) << left <<asc;
		}
		else
		{
			cout << setw(4) << right << asc << endl;
		}
		i++;
	}
	return 0;
}