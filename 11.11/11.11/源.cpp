#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	int* pa = &a;
	cout << &a << "---" << pa << endl << &pa << "---" << *pa << endl;
	
	
	char *chPtr; //  
	int *iPtr; //  
	struct Something
	{
		int nX, nY, nZ;
	};
	Something *somethingPtr;

	std::cout << sizeof(chPtr) << '\n';
	std::cout << sizeof(iPtr) << '\n';
	std::cout << sizeof(somethingPtr) << '\n';
	
	//short *ptr;
	//*ptr = 9;

	int k1[10] = { 11,24,37,44,58,66,79,86,93,108 }, *pk = NULL;
	pk = &k1[0];		//数组第一个元素的地址赋值给指针k
	for (int i = 0; i < 10; i = i + 2)	//每次循环，指针加2
		std::cout << "k1[" << i << "]=" << *(pk + i) << endl;


	return  0;

}