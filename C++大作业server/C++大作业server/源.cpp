#include<iostream>
#include<stdio.h>
#include<fstream>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib") //���� ws2_32.dll
using namespace std;

//�˵�Ϊ�����ˣ�Ҳ���Ǽ��ܶ�

void kasa(int n, char text[500]);

int main()
{
	//��ʼ�� DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//�����׽���
	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//���׽���
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
	sockAddr.sin_family = PF_INET;  //ʹ��IPv4��ַ
	//sockAddr.sin_addr.s_addr = inet_addr("10.21.237.96");  //�����IP��ַ
	sockAddr.sin_port = htons(INADDR_ANY);  //�˿�
	bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
	//�������״̬
	listen(servSock, 20);
	cout << "���ڼ����ͻ���......\n";
	//���տͻ�������
	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
	cout << "�Ѻͽ��ܶ���ϵ��\n";

	//��ȡ�ļ�ԭ�ġ�
	ifstream ifile("D:/C++file/sendtext.txt");
	char text[500] = { 0 },c;
	int i = 0;
	while ((c = ifile.get()) != EOF)
	{
		text[i] = c;
		i++;
	}

	//������Կ��
	int key;
	cout << "��������Կ��";
	cin >> key;

	//���ܴ������� 
	kasa(key, text);
	cout << "ԭ���Ѽ��ܡ�\n";
	
	//��ͻ��˷�������
	char sendkey[1] = {0};
	sendkey[0] = key;
	send(clntSock, text, strlen(text) + sizeof(char), NULL);
	send(clntSock, sendkey, sizeof(int), NULL);
	cout << "���ġ���Կ�ѷ��͡�\n";
	
	//���ܿͻ��˻���
	char backminwen[500] = { 0 };
	recv(clntSock, backminwen, 1000, NULL);
	cout << "�ѽ��շ�������" << endl;

	//
	ofstream ofile("D:/C++file/backtext.txt", ios::app);
	ofile << "-----\n" << backminwen << endl;
	cout << "������backtext.txt��" << endl;
	

	//�ر��׽���
	shutdown(servSock, SD_SEND);
	//closesocket(clntSock);
	//closesocket(servSock);
	//��ֹ DLL ��ʹ��
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


