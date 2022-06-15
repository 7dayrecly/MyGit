#include<iostream>
#include<fstream>
using namespace std;

void kasa(int n, char text[500]);
void rekasa(int n, char text[500]);

int main()
{
	ifstream ifile("D:/C++file/sendtext.txt");		
	int n,i = 0;
	char text[500] = { 0 },c;
	cin >> n;
	while ((c = ifile.get()) != EOF)
	{
		text[i] = c;
		i++;
	}
	kasa(n, text);
	cout << "\n-----------\n";
	rekasa(n, text);
	return 0;
}

void kasa(int n, char text[500] = {0})
{
	int iend = 0;
	char c;
	while (text[iend] >= 20 && text[iend] <= 122)
	{
		/*if (isalpha(text[iend]))
		{
			if (isalpha(text[iend] + n))
				text[iend] = text[iend] + n;
			else
				text[iend] = text[iend] + n - 26;
		}*/

		c = text[iend] + n;
		if ((text[iend] >= 'a' && text[iend] <= 'z') || (text[iend] >= 'A' && text[iend] <= 'Z'))
		{
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
				text[iend] = text[iend] + n;
			else
				text[iend] = text[iend] + n - 26;

			
		}
		cout << text[iend];
		iend++;
	}
}


void rekasa(int n, char text[500] = {0})
{
	int iend = 0;
	char c;
	while (text[iend] >= 20 && text[iend] <= 122)
	{
		/*if (isalpha(text[iend]))
		{
			if (isalpha(text[iend] - n))
				text[iend] = text[iend] - n;
			else
				text[iend] = text[iend] - n + 26;
		}*/
		
		c = text[iend] - n;
		if ((text[iend] >= 'a' && text[iend] <= 'z') || (text[iend] >= 'A' && text[iend] <= 'Z'))
		{
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
				text[iend] = text[iend] - n;
			else
				text[iend] = text[iend] - n + 26;

			
		}
		cout << text[iend];
		iend++;
	}
}