#include <stdio.h>
#include <WinSock2.h>
#pragma comment (lib, "ws2_32.lib")  //���� ws2_32.dll
int main() {
	//��ʼ�� DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//�����׽���
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//���׽���
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
	sockAddr.sin_family = PF_INET;  //ʹ��IPv4��ַ
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //�����IP��ַ
	sockAddr.sin_port = htons(1234);  //�˿�
	bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	//�������״̬
	listen(servSock, 20);
	//���տͻ�������
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
	
	
	
	
	//��ͻ��˷�������
	const char *str = "Hello World!";
	send(clntSock, str, strlen(str) + sizeof(char), NULL);
	//�ر��׽���
	closesocket(clntSock);
	closesocket(servSock);
	//��ֹ DLL ��ʹ��
	WSACleanup();
	return 0;
}


/*#include<winsock2.h>
#include<iostream>
#include<string>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[]) {

	//��ʼ��DLL
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsdata;
	if (WSAStartup(sockVersion, &wsdata) != 0)
	{
		return 1;
	}

	//�����׽���
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET)
	{
		cout << "Socket error" << endl;
		return 1;
	}


	//���׽���
	sockaddr_in sockAddr;
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(8888);
	sockAddr.sin_addr.S_un.S_addr = INADDR_ANY;

	if (bind(serverSocket, (sockaddr*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR) {
		cout << "Bind error" << endl;
		return 1;
	}

	//��ʼ����
	if (listen(serverSocket, 10) == SOCKET_ERROR) {
		cout << "Listen error" << endl;
		return 1;
	}


	SOCKET clientSocket;
	sockaddr_in client_sin;
	char msg[100];//�洢���͵���Ϣ
	int flag = 0;//�Ƿ��Ѿ�������
	int len = sizeof(client_sin);
	while (true) {
		if (!flag)
			cout << "�ȴ�����..." << endl;
		clientSocket = accept(serverSocket, (sockaddr*)&client_sin, &len);
		if (clientSocket == INVALID_SOCKET) {
			cout << "Accept error" << endl;
			flag = 0;
			return 1;
		}
		if (!flag)
			cout << "���յ�һ�����ӣ�" << inet_ntoa(client_sin.sin_addr) << endl;
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