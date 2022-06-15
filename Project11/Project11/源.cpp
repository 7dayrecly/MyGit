#include<iostream>
using namespace std;

void fuc(int n, int num);

int main()
{
	int n, num;
	cout << "n=";
	cin >> n; 
	cout << "num=";
	cin >> num;
	fuc(n, num);
	return 0;
}

void fuc(int n, int num)//n为进位制，num为十进制数。
{
	if (num >= n)//用递归函数，若num大于n则将num赋值为num/n传递给递归的下一次函数。
	{
		fuc(n, num / n);
	}
	//输出num%n，此时num%n就为更换进位制下的某位数
	//当num本身小于n时，此时递归到尽头，这时输出的就是第一位数，输出完后退出，再来输出的num%n即为第二位数。
	//以此类推。
	if (num % n < 10)
	{
		cout << num % n;
	}
	else
	{
		char temp;
		temp = 'A' + num % n - 10;
		cout << temp;
	}
	
}