#include<iostream>
#include<stdio.h>
#include<fstream>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib") //加载 ws2_32.dll
using namespace std;


//此地为接收端，理应为解密端

void rekasa(int n, char text[1000]);


int main() {
	
	//初始化DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//创建套接字
	SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//向服务器发起请求
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
	sockAddr.sin_family = PF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("10.21.239.196");
	sockAddr.sin_port = htons(1234);
	cout << "开始加密通话,请等待对方传来信息\n";
	connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	
	
	//接收服务器传回的数据
	char szBuffer[1000] = { 0 };
	char key[1] = { 0 };
	recv(sock, szBuffer, 1000, NULL);
	recv(sock, key, sizeof(int), NULL);
	//输出接收到的数据
	cout << "Message form server: " << endl << szBuffer << endl;
	Sleep(2000);
	
	ofstream ofile("D:/C++file/recvtext.txt", ios::app);
	ofile << "--------\n" << szBuffer << endl;
	ofile.close();
	cout << "密文已生成文件recvtext.txt。" << endl;
	int n;
	n = key[0];
	cout << "密钥为：" << n << endl;
	int type;
	cout << "请输入密钥：";
	cin >> type;
	
	if (type == n)
	{
		cout << "正在解密，请等待4秒......" << endl;
		Sleep(4000);
		//解密生成returntext.txt。
		cout << "解密成功，解密后原文为：\n";
		rekasa(type, szBuffer);   //会输出原文
		ofile.open("D:/C++file/returntext.txt", ios::app);
		ofile << "--------\n" << szBuffer << endl;
		ofile.close();
		cout << "解密后已生成原文returntext.txt。" << endl;

		//回返服务器文字
		send(sock, szBuffer, 1000, NULL);
		cout << "原文已返回。" << endl;
	}
	else
	{
		cout << "你照抄都能抄错？\n";
	}
	
	
	//关闭套接字
	closesocket(sock);
	//终止使用 DLL
	WSACleanup();
	system("pause");
	return 0;
}


void rekasa(int n, char text[1000])
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
	cout << "\n--------\n";
}