#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	float x, e, sum = 0, JieCheng = 1, Mi = 0;
	int n;
	cin >> x >> n;
	for (int i = 1; i <= n; i++)
	{
		Mi = pow(x,i);
		JieCheng *= i;
		sum += (Mi / JieCheng);
	}
	e = sum + 1;
	cout << setiosflags(ios::fixed) << setprecision(4) << e;
}