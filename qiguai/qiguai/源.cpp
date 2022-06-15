#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T data;
	struct Node<T>*next;
};
template <class T>
class LinkList
{
public:
	LinkList() { front = new Node<T>; front->next = NULL; }
	LinkList(T a[], int n);//ͷ�巨����
	LinkList(T a[], int n, int m);//β�巨����
	void Insert(int i, T x);//����
	T Delete(int i);//ɾ��
	int Locate(T x);//����
	int GetLength();//��ȡ���Ա�ĳ���
	int DeleteLinkList();//����
	void PrintList();//��ӡ���Ա�����ݡ�
private:
	Node<T>*front;
};
//ͷ�巨
template <class T>
LinkList<T>::LinkList(T a[], int n)
{
	front = new Node<T>;
	front->next = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		Node <T>*s = new Node<T>;
		s->data = a[i];
		s->next = front->next;
		front->next = s;
	}
}
//β�巨
template <class T>
LinkList<T>::LinkList(T a[], int n, int m)
{
	front = new Node<T>;
	Node <T>*r = front;
	for (m = 0; m < n; m++)
	{
		Node<T>*s = new Node<T>;
		s->data = a[m];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
//����
template <class T>
void LinkList<T>::Insert(int i, T x)
{
	Node<T>*p = front;
	if (i != 1)
	{
		for (int m = 0; m < i - 1; m++)
		{
			p = p->next;
		}
	}
	if (p)
	{
		Node<T>*s = new Node <T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	else
	{
		cout << "����λ�ô���" << endl;
	}
}
//ɾ��
template <class T>
T LinkList<T>::Delete(int i)
{
	Node <T>*p = front;
	if (i != 1)
	{
		for (int m = 0; m < i - 1; m++)
		{
			p = p->next;
		}
	}
	Node<T>*s = p->next;
	T x = s->data;
	p->next = s->next;
	delete s;
	return x;
}
//����
template <class T>
int LinkList<T>::Locate(T x)
{
	Node<T>*p = front->next;
	int j = 1;
	while (p)
	{
		if (p->data == x)
		{
			return j;
		}
		p = p->next;
		j++;
	}
	return -1;
}
//��ȡ����ĳ���
template <class T>
int LinkList<T>::GetLength()
{
	Node<T>*p = front->next;
	int j = 1;
	while (p)
	{
		if (p->next == NULL)
		{
			return j;
		}
		p = p->next;
		j++;
	}
	return -1;
}
//����
template<class T>
int LinkList<T>::DeleteLinkList()
{
	Node<T>*p = front;
	while (p)
	{
		front = p;
		p = p->next;
		delete front;
	}
	return 1;
}
//��ӡ���Ա������
template <class T>
void LinkList<T>::PrintList()
{
	Node<T>*p = front->next;
	while (p)
	{
		front = p;
		p = p->next;
		cout << front->data << " ";
	}
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	int *a;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	//int r;
	//cin >> r;
	//rΪ1��ͷ�巨���죬rΪ2��β�巨����
	//if (r == 1)
	//{
	LinkList<int>myLinkList(a, n);
	//}
	//else if (r == 2)
	//{
	LinkList<int> myLinkList1(a, n, n);
	//}
	int m, i, x;
	cin >> m >> i >> x;
	//mΪ1ʱִ�в��������mΪ2ʱִ��ɾ��������mΪ3ʱִ�в��Ҳ�����mΪ4ʱִ�л�ȡ�����ȵĲ�����mΪ5ʱִ�����ٲ�����
	//mΪ6ʱִ�д�ӡ�������ݵĲ���
	switch (m)
	{
	case 1:
	{
		myLinkList.Insert(i, x);
		myLinkList.PrintList();
	}
	break;
	case 2:
	{
		myLinkList.Delete(i);
		myLinkList.PrintList();
	}
	break;
	case 3:
	{
		cout << myLinkList.Locate(x);
	}
	break;
	case 4:
	{
		cout << myLinkList.GetLength();
	}
	break;
	case 5:
	{
		myLinkList.DeleteLinkList();
	}
	break;
	case 6:
	{
		myLinkList.PrintList();
	}
	break;
	default:
		cout << "ִ�еĲ�������" << endl;
	}
	cin >> i;
}