#include<iostream>
#include<stdio.h>
#include<fstream>
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib") //���� ws2_32.dll
using namespace std;


//�˵�Ϊ���նˣ���ӦΪ���ܶ�

void rekasa(int n, char text[500]);


int main() {

	//��ʼ��DLL
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//�����׽���
	SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//���������������
	sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
	sockAddr.sin_family = PF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("10.21.237.96");
	sockAddr.sin_port = htons(10252);
	connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));


	//���շ��������ص�����
	char szBuffer[500] = { 0 };
	char key[1] = { 0 };
	recv(sock, szBuffer, 500, NULL);
	recv(sock, key, sizeof(int), NULL);
	//������յ�������
	cout << "Message form server: " << endl << szBuffer << endl;


	ofstream ofile("D:/C++file/recvtext.txt", ios::app);
	ofile << "--------\n" << szBuffer << endl;
	ofile.close();
	cout << "�����������ļ�recvtext.txt��" << endl;
	int n;
	n = key[0];
	cout << "��ԿΪ��" << n << endl;


	//��������returntext.txt��
	cout << "���ܺ�ԭ�ģ�\n";
	rekasa(n, szBuffer);   //�����ԭ��
	ofile.open("D:/C++file/returntext.txt", ios::app);
	ofile << "--------\n" << szBuffer << endl;
	ofile.close();
	cout << "���ܺ�������ԭ��returntext.txt��" << endl;


	//�ط�����������
	send(sock, szBuffer, 500, NULL);
	cout << "ԭ���ѷ��ء�" << endl;



	//�ر��׽���
	closesocket(sock);
	//��ֹʹ�� DLL
	WSACleanup();
	system("pause");
	return 0;
}


void rekasa(int n, char text[500])
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