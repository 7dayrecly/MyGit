#include <stdio.h>
#include <WinSock2.h>
#pragma comment (lib, "ws2_32.lib")  //加载 ws2_32.dll
int main() {
	//初始化 DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//创建套接字
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//绑定套接字
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
	sockAddr.sin_family = PF_INET;  //使用IPv4地址
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
	sockAddr.sin_port = htons(1234);  //端口
	bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	//进入监听状态
	listen(servSock, 20);
	//接收客户端请求
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
	
	
	
	
	//向客户端发送数据
	const char *str = "Hello World!";
	send(clntSock, str, strlen(str) + sizeof(char), NULL);
	//关闭套接字
	closesocket(clntSock);
	closesocket(servSock);
	//终止 DLL 的使用
	WSACleanup();
	return 0;
}


/*#include<winsock2.h>
#include<iostream>
#include<string>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[]) {

	//初始化DLL
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsdata;
	if (WSAStartup(sockVersion, &wsdata) != 0)
	{
		return 1;
	}

	//创建套接字
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET)
	{
		cout << "Socket error" << endl;
		return 1;
	}


	//绑定套接字
	sockaddr_in sockAddr;
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(8888);
	sockAddr.sin_addr.S_un.S_addr = INADDR_ANY;

	if (bind(serverSocket, (sockaddr*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR) {
		cout << "Bind error" << endl;
		return 1;
	}

	//开始监听
	if (listen(serverSocket, 10) == SOCKET_ERROR) {
		cout << "Listen error" << endl;
		return 1;
	}


	SOCKET clientSocket;
	sockaddr_in client_sin;
	char msg[100];//存储传送的消息
	int flag = 0;//是否已经连接上
	int len = sizeof(client_sin);
	while (true) {
		if (!flag)
			cout << "等待连接..." << endl;
		clientSocket = accept(serverSocket, (sockaddr*)&client_sin, &len);
		if (clientSocket == INVALID_SOCKET) {
			cout << "Accept error" << endl;
			flag = 0;
			return 1;
		}
		if (!flag)
			cout << "接收到一个链接：" << inet_ntoa(client_sin.sin_addr) << endl;
		flag = 1;
		int num = recv(clientSocket, msg, 100, 0);
		if (num > 0)
		{
			msg[num] = '\0';
			cout << "Client say: " << msg << endl;

		}

		string data;
		getline(cin, data);
		const char * sendData;
		sendData = data.c_str();
		send(clientSocket, sendData, strlen(sendData), 0);
		closesocket(clientSocket);
	}

	closesocket(serverSocket);
	WSACleanup();



	return 0;
}*/