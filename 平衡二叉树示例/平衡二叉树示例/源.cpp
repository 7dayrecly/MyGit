#include <iostream>
#include <algorithm>
using namespace std;

template<class T>class BiNode
{
public:
	T data;
	int height;
	BiNode<T> *lch;
	BiNode<T> *rch;
	BiNode() { lch(NULL), rch(NULL) };
};

template<class T>class BST
{
public:
	BST(T r[], int n);
	~BST();
	BiNode<T> *Search(BiNode<T> *R, T key);
	void InsertBST(BiNode<T> *&R, BiNode<T> *S);
	void Delete(BiNode<T> *&R);
	bool FindDelete(BiNode<T> *&R, T key);

	void Release(BiNode<T> *R);//析构


private:
	BiNode<T> *Root;
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
void BST<T>::InsertBST(BiNode<T> *&R, BiNode<T> *s)
{
	if (R == NULL)
		R = s;
	else if (s->data < R->data)
	{
		s->height++;
		InsertBST(R->lch, s);
	}
	else
	{
		s->height++;
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
		s->height = 0;
		s->data = r[i];
		s->lch = s->rch = NULL;
		InsertBST(Root, s);
		//平衡二叉树要在此处翻转。
		if ()
	}
}

template<class T>
bool BST<T>::FindDelete(BiNode<T> *&R, T key)
{
	if (R == NULL) return false;
	else
	{
		if (key == R->data)
		{
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
	}
	else if (R->rch == NULL)
	{
		q = R;
		R = R->lch;
		delete q;
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
	}
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