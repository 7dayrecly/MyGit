//#include<iostream>
//#include<fstream>
//using namespace std;
//int main()
//{

	/*ifstream ifile("d:\data.txt");
	int sum, value1, value2;
	ifile >> value1 >> value2;
	sum = value1 + value2;
	ifile.close();
	ofstream ofile;
	ofile.open("d:\data.txt",ios::app);
	ofile << endl << "---\n" << sum;
	cout << "data: " << value1 << ", " << value2 << endl;
	cout << "sum is: " << sum << endl;*/

	/*for (int i = 0; i <= 10; i++)
		cout << i << endl;*/

	//cout << "Hi! \x4dO\115" << endl;
	//return 0;
//}



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
using namespace std;

int main()
{
	float x;
	int i;
	scanf_s("%f %d", &x, &i);
	int a = 1;
	int n = 0;
	float e = 1;
	int s = 1;
	while (n <= (i + 1))
	{
		if (n <= 1)
		{
			n = 1;
		}
		else
		{
			int q = 1;
			while (q <= n)
			{
				s *= q;
				q++;
			}
		}
		x = pow(x, a);
		e = e + x / s;
		n++;
		a = n;
	}
	printf("%.4f", e);
	cin >> a;
	return 0;
}
