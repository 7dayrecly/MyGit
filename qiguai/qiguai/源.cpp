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
	LinkList(T a[], int n);//头插法构造
	LinkList(T a[], int n, int m);//尾插法构造
	void Insert(int i, T x);//插入
	T Delete(int i);//删除
	int Locate(T x);//查找
	int GetLength();//获取线性表的长度
	int DeleteLinkList();//销毁
	void PrintList();//打印线性表的内容。
private:
	Node<T>*front;
};
//头插法
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
//尾插法
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
//插入
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
		cout << "插入位置错误！" << endl;
	}
}
//删除
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
//查找
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
//获取链表的长度
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
//销毁
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
//打印线性表的内容
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
	//r为1是头插法构造，r为2是尾插法构造
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
	//m为1时执行插入操作，m为2时执行删除操作，m为3时执行查找操作，m为4时执行获取链表长度的操作，m为5时执行销毁操作，
	//m为6时执行打印链表内容的操作
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
		cout << "执行的操作错误！" << endl;
	}
	cin >> i;
}