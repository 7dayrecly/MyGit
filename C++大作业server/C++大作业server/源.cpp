#include<iostream>
#include<stdio.h>
#include<fstream>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib") //加载 ws2_32.dll
using namespace std;

//此地为发出端，也就是加密端

void kasa(int n, char text[500]);

int main()
{
	//初始化 DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//创建套接字
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//绑定套接字
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
	sockAddr.sin_family = PF_INET;  //使用IPv4地址
	//sockAddr.sin_addr.s_addr = inet_addr("10.21.237.96");  //具体的IP地址
	sockAddr.sin_port = htons(INADDR_ANY);  //端口
	bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	//进入监听状态
	listen(servSock, 20);
	cout << "正在监听客户端......\n";
	//接收客户端请求
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
	cout << "已和解密端联系。\n";

	//读取文件原文。
	ifstream ifile("D:/C++file/sendtext.txt");
	char text[500] = { 0 },c;
	int i = 0;
	while ((c = ifile.get()) != EOF)
	{
		text[i] = c;
		i++;
	}

	//创建密钥。
	int key;
	cout << "请输入密钥：";
	cin >> key;

	//加密处函数。 
	kasa(key, text);
	cout << "原文已加密。\n";
	
	//向客户端发送数据
	char sendkey[1] = {0};
	sendkey[0] = key;
	send(clntSock, text, strlen(text) + sizeof(char), NULL);
	send(clntSock, sendkey, sizeof(int), NULL);
	cout << "密文、密钥已发送。\n";
	
	//接受客户端回文
	char backminwen[500] = { 0 };
	recv(clntSock, backminwen, 1000, NULL);
	cout << "已接收返回明文" << endl;

	//
	ofstream ofile("D:/C++file/backtext.txt", ios::app);
	ofile << "-----\n" << backminwen << endl;
	cout << "已生成backtext.txt。" << endl;
	

	//关闭套接字
	shutdown(servSock, SD_SEND);
	//closesocket(clntSock);
	//closesocket(servSock);
	//终止 DLL 的使用
	WSACleanup();
	return 0;
}


void kasa(int n, char text[500])
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
	cout << endl;
}


