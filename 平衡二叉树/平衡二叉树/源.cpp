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
	BiNode<T> *Search(BiNode<T> *R, T key);//查找对应的节点
	void InsertBST(BiNode<T> *&R, BiNode<T> *S);//插入
	void Delete(BiNode<T> *&R);//删除
	bool FindDelete(BiNode<T> *&R, T key);//删除的辅助函数，寻找删除的节点

	void InorderTraversal(BiNode<T> *R);//中序遍历
	void PreorderTraversal(BiNode<T> *R);//前序遍历

	void Release(BiNode<T> *R);//析构

	
private:
	bool IsBanlanceTree(BiNode<T> *R); //判断是否为平衡二叉树，没用。
	int GetHeight(BiNode<T> *R); //得到树的深度
	void Banlance(BiNode<T> *R); //对非平衡的二叉树进行平衡
	int difference(BiNode<T> *R) { return GetHeight(R->lch) - GetHeight(R->rch); }//计算该节点的平衡因子
	
	//左右的概念：用拇指指向你，四指旋转方向即为节点的变化方向。顺时针左旋，逆时针右旋
	void LL(BiNode<T> *R); //单左旋
	void RR(BiNode<T> *R); //单右旋
	void LR(BiNode<T> *R); //先右旋后左旋
	void RL(BiNode<T> *R); //先左旋后右旋
	
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
void BST<T>::InsertBST(BiNode<T> *&R, BiNode<T> *s)//节点的插入，均从根节点插入。
{
	if (R == NULL)
	{
		R = s;
		Banlance(Root);//每次插入后需对整个树重新平衡，删除也是一样
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
		cout << "不存在该值。" << endl;
		return false;
	}
	else
	{
		if (key == R->data)
		{
			cout << "已删除" << R->data << endl;
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
bool BST<T>::IsBanlanceTree(BiNode<T> *R)//这玩意没用
{
	if (R == NULL)
		return true;
	return (abs(difference(R)) <= 1 && IsBanlanceTree(R->lch) && IsBanlanceTree(R->rch));
}

/*
对于每次插入或者删除了一个节点的情况而言，一个节点可能出现的平衡因子只可能是2，1，0，-1，-2
当存在一个平衡因子为2的节点，一定是其左子树需要平衡，而且需要进行的操作与其左孩子的平衡因子是1还是-1有关。
-2同理。当一个树是平衡二叉树的时候，一直访问到空节点，无需进行任何操作。
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
	cout << "该平衡二叉树为：\n中序遍历：";
	bst.InorderTraversal(bst.Root);
	cout << endl << "前序遍历：";
	bst.PreorderTraversal(bst.Root);
	cout << endl;

	int deletenum;
	cout << "请输入你要删除的数据" << endl;
	cin >> deletenum;
	bst.FindDelete(bst.Root, deletenum);
	cout << "该平衡二叉树为：\n中序遍历：";
	bst.InorderTraversal(bst.Root);
	cout << endl << "前序遍历：";
	bst.PreorderTraversal(bst.Root);
	cout << endl;

	cout << "请输入你要插入的数据" << endl;
	BiNode<int> *InsertNum = new BiNode<int>;
	cin >> InsertNum->data;
	bst.InsertBST(bst.Root, InsertNum);
	cout << "该平衡二叉树为：\n中序遍历：";
	bst.InorderTraversal(bst.Root);
	cout << endl << "前序遍历：";
	bst.PreorderTraversal(bst.Root);
	cout << endl;

	return 0;
}