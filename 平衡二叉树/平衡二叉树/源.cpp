#include<iostream>
#include<math.h>

using namespace std;

template<class T>class BiNode
{
public:
	T data;
	int dif;
	BiNode<T> *lch;
	BiNode<T> *rch;
	//int GetHeight(BiNode<T> *R);
	BiNode() { lch = NULL; rch = NULL; dif = 0; }
};



template<class T>class BST
{
public:
	BiNode<T> *Root;
	
	BST(T r[], int n);
	~BST();
	BiNode<T> *Search(BiNode<T> *R, T key);//���Ҷ�Ӧ�Ľڵ�
	void InsertBST(BiNode<T> *&R, BiNode<T> *S);//����
	void Delete(BiNode<T> *&R);//ɾ��
	bool FindDelete(BiNode<T> *&R, T key);//ɾ���ĸ���������Ѱ��ɾ���Ľڵ�

	void InorderTraversal(BiNode<T> *R);//�������
	void PreorderTraversal(BiNode<T> *R);//ǰ�����

	void Release(BiNode<T> *R);//����

	
private:
	bool IsBanlanceTree(BiNode<T> *R); //�ж��Ƿ�Ϊƽ���������û�á�
	int GetHeight(BiNode<T> *R); //�õ��������
	void Banlance(BiNode<T> *R); //�Է�ƽ��Ķ���������ƽ��
	int difference(BiNode<T> *R) { return GetHeight(R->lch) - GetHeight(R->rch); }//����ýڵ��ƽ������
	
	//���ҵĸ����Ĵָָ���㣬��ָ��ת����Ϊ�ڵ�ı仯����˳ʱ����������ʱ������
	void LL(BiNode<T> *R); //������
	void RR(BiNode<T> *R); //������
	void LR(BiNode<T> *R); //������������
	void RL(BiNode<T> *R); //������������
	
};

template<class T>
BiNode<T> *BST<T>::Search(BiNode<T> *R, T key)
{
	if (R == NULL) return NULL;
	if (key == R->data) return R;
	else if (key < R->data) return Search(R->lch, key);
	else return Search(R->rch, key);
}

template<class T>
void BST<T>::InsertBST(BiNode<T> *&R, BiNode<T> *s)//�ڵ�Ĳ��룬���Ӹ��ڵ���롣
{
	if (R == NULL)
	{
		R = s;
		Banlance(Root);//ÿ�β�����������������ƽ�⣬ɾ��Ҳ��һ��
	}
	else if (s->data == R->data)
		return;
	else if (s->data < R->data)
	{
		InsertBST(R->lch, s);
	}
	else
	{
		InsertBST(R->rch, s);
	}
}

template<class T>
BST<T>::BST(T r[], int n)
{
	Root = NULL;
	for (int i = 0; i < n; i++)
	{
		BiNode<T> *s = new BiNode<T>;
		s->data = r[i];
		s->lch = s->rch = NULL;
		InsertBST(Root, s);
	}
}

template<class T>
bool BST<T>::FindDelete(BiNode<T> *&R, T key)
{
	if (R == NULL)
	{
		cout << "�����ڸ�ֵ��" << endl;
		return false;
	}
	else
	{
		if (key == R->data)
		{
			cout << "��ɾ��" << R->data << endl;
			Delete(R);
			return true;
		}
		else if (key < R->data)
			return FindDelete(R->lch, key);
		else
			return FindDelete(R->rch, key);
	}
}

template<class T>
void BST<T>::Delete(BiNode<T> *&R)
{
	BiNode<T> *q, *s;
	if (R->lch == NULL)
	{
		q = R;
		R = R->rch;
		delete q;
		Banlance(Root);
	}
	else if (R->rch == NULL)
	{
		q = R;
		R = R->lch;
		delete q;
		Banlance(Root);
	}
	else
	{
		q = R;  s = R->lch;
		while (s->rch != NULL)
		{
			q = s; s = s->rch;
		}
		R->data = s->data;
		if (q != R)
			q->rch = s->lch;
		else
			R->lch = s->lch;
		delete s;
		Banlance(Root);
	}
}

template<class T>
void BST<T>::InorderTraversal(BiNode<T> *R)
{
	if (R == NULL)
		return;
	InorderTraversal(R->lch);
	cout << R->data << " ";
	InorderTraversal(R->rch);
}

template<class T>
void BST<T>::PreorderTraversal(BiNode<T> *R)
{
	if (R == NULL)
		return;
	cout << R->data << " ";
	PreorderTraversal(R->lch);
	PreorderTraversal(R->rch);
}

template<class T>
void BST<T>::Release(BiNode<T> *R)
{
	if (R != NULL)
	{
		Release(R->lch);
		Release(R->rch);
		delete R;
	}
}

template<class T>
BST<T>::~BST()
{
	Release(Root);
}

template<class T>
int BST<T>::GetHeight(BiNode<T> *R)
{
	if (R == NULL)
		return 0;
	else
	{
		int m, n;
		m = GetHeight(R->lch);
		n = GetHeight(R->rch);
		return (m > n ? m : n)+1;
	}
}

template<class T>
bool BST<T>::IsBanlanceTree(BiNode<T> *R)//������û��
{
	if (R == NULL)
		return true;
	return (abs(difference(R)) <= 1 && IsBanlanceTree(R->lch) && IsBanlanceTree(R->rch));
}

/*
����ÿ�β������ɾ����һ���ڵ��������ԣ�һ���ڵ���ܳ��ֵ�ƽ������ֻ������2��1��0��-1��-2
������һ��ƽ������Ϊ2�Ľڵ㣬һ��������������Ҫƽ�⣬������Ҫ���еĲ����������ӵ�ƽ��������1����-1�йء�
-2ͬ����һ������ƽ���������ʱ��һֱ���ʵ��սڵ㣬��������κβ�����
*/
template<class T>
void BST<T>::Banlance(BiNode<T> *R)
{
	if (R == NULL)
		return;
	if (difference(R) >= 0)
	{
		if (difference(R) == 2)
		{
			if (difference(R->lch) == -1)
			{
				LR(R);
			}
			else if (difference(R->lch) == 1)
			{
				LL(R);
			}
			else
			{
				Banlance(R->lch);
			}
		}
		else
		{
			Banlance(R->lch);
			Banlance(R->rch);
		}
	}
	if (difference(R) <= 0)
	{
		if (difference(R) == -2)
		{
			if (difference(R->rch) == -1)
			{
				RR(R);
			}
			else if (difference(R->rch) == 1)
			{
				RL(R);
			}
			else
			{
				Banlance(R->rch);
			}
		}
		else
		{
			Banlance(R->lch);
			Banlance(R->rch);
		}
	}
}


template<class T>
void BST<T>::LL(BiNode<T> *R)
{
	T temp;
	BiNode<T> *p = R, *s = R->lch;
	temp = p->data; p->data = s->data; s->data = temp;
	p->lch = s->lch;
	s->lch = s->rch;
	s->rch = p->rch;
	p->rch = s;
}

template<class T>
void BST<T>::RR(BiNode<T> *R)
{
	T temp;
	BiNode<T> *p = R, *s = R->rch;
	temp = p->data; p->data = s->data; s->data = temp;
	p->rch = s->rch;
	s->rch = s->lch;
	s->lch = p->lch;
	p->lch = s;
}

template<class T>
void BST<T>::LR(BiNode<T> *R)
{
	RR(R->lch);
	LL(R);
}

template<class T>
void BST<T>::RL(BiNode<T> *R)
{
	LL(R->rch);
	RR(R);
}





int main()
{
	int arr[] = { 13,24,37,90,53,44,87,64 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BST<int> bst(arr, n);
	cout << "��ƽ�������Ϊ��\n���������";
	bst.InorderTraversal(bst.Root);
	cout << endl << "ǰ�������";
	bst.PreorderTraversal(bst.Root);
	cout << endl;

	int deletenum;
	cout << "��������Ҫɾ��������" << endl;
	cin >> deletenum;
	bst.FindDelete(bst.Root, deletenum);
	cout << "��ƽ�������Ϊ��\n���������";
	bst.InorderTraversal(bst.Root);
	cout << endl << "ǰ�������";
	bst.PreorderTraversal(bst.Root);
	cout << endl;

	cout << "��������Ҫ���������" << endl;
	BiNode<int> *InsertNum = new BiNode<int>;
	cin >> InsertNum->data;
	bst.InsertBST(bst.Root, InsertNum);
	cout << "��ƽ�������Ϊ��\n���������";
	bst.InorderTraversal(bst.Root);
	cout << endl << "ǰ�������";
	bst.PreorderTraversal(bst.Root);
	cout << endl;

	return 0;
}