#include<iostream>
#include<string>
using namespace std;
int main()
{
	int num, a, b, c, d;
	string Eng_num[10] = { "","one","two","three","four","five","six","seven","eight","nine" };
	string Eng_ten[10] = { "","","twenty" , "thirty","forty","fifty","sixty","seventy","eighty","ninety" };
	string Eng_tens[10] = { "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
	cin >> num;
	a = num / 1000;
	b = (num / 100) % 10;
	c = (num / 10) % 10;
	d = num % 10;
	if ((c * 10 + d >= 20) || (c == 0)) //十位数不是一的情况
	{
		cout << Eng_num[a] << " thousand " << Eng_num[b] << " hundred and " << Eng_ten[c] << " " << Eng_num[d] << endl;
	}
	else //针对十位数是一的情况
	{
		cout << Eng_num[a] << " thousand " << Eng_num[b] << " hundred and " << Eng_tens[d] << endl;
	}
	return 0;
}
