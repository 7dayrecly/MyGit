#include <WinSock2.h>
#include <stdio.h> 
//#include <pthread.h>
#pragma comment(lib, "ws2_32.lib")
#include<iostream>
using namespace std;
void* recv1(SOCKET sockConn)
{
	char recvBuf[10000];
	memset(recvBuf, 0, sizeof(recvBuf));//ÿ���ֽڶ���0��� 
	//��������
	while (true) {
		int nRecv = ::recv(sockConn, recvBuf, sizeof(recvBuf), 0);
		if (nRecv > 0) {
			cout << "client receive:" << recvBuf << endl;
		}
		else break;
	}
}
void* send1(void* args)
{
	SOCKET sockClient1 = *((SOCKET*)args);
	while (true) {
		char buff1[10000];
		cin >> buff1;
		if (buff1 == "") {
			break;
		}
		int e = send(sockClient1, buff1, sizeof(buff1), 0);
		if (e == SOCKET_ERROR) {
			printf("send failed");
			break;
		}
		cout << "client send:" << buff1 << endl;
	}

}
int main()
{
	//�����׽���
	WSADATA wsaData;
	char buff[1024];
	memset(buff, 0, sizeof(buff));

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)//��ʼ��DDL 
	{
		printf("Failed to load Winsock");
		return 0;
	}

	SOCKADDR_IN addrSrv; //����˵�ַ
	addrSrv.sin_family = AF_INET;//IPV4 
	addrSrv.sin_port = htons(5099);//port 
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//serverIP��ַ��inet_addr�����ʮ���Ƶ�ַת��Ϊ�޷���4�ֽڵ�������ַ

	//�����ͻ����׽���
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);//����ָ����������socket�������׽���
	if (SOCKET_ERROR == sockClient) {
		printf("Socket() error:%d", WSAGetLastError());
		return 0;
	}

	//�������������������
	if (connect(sockClient, (struct  sockaddr*)&addrSrv, sizeof(addrSrv)) == INVALID_SOCKET) {
		printf("Connect failed:%d", WSAGetLastError());
		return 0;
	}
	else {
		pthread_t tids[2];
		int ret = pthread_create(&tids[0], NULL, send1, (void*)&sockClient);
		if (ret != 0) //�����̳߳ɹ�����0
		{
			cout << "pthread_create error:error_code=" << ret << endl;
		}
		//��������
		recv(sockClient, buff, sizeof(buff), 0);
		printf("%s\n", buff);
	}
	recv1(sockClient);