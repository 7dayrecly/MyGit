#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
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
}