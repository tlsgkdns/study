#include <iostream>
#include <vector>
using namespace std;

typedef struct _Node
{
	_Node* left;
	_Node* right;
	int value;
	_Node(int v)
	{
		left = NULL;
		right = NULL;
		value = v;
	}
	void insertNode(int nv)
	{
		if (nv < value)
		{
			if (left == NULL)
				left = new _Node(nv);
			else
				left->insertNode(nv);
		}
		else
		{
			if (right == NULL)
				right = new _Node(nv);
			else
				right->insertNode(nv);
		}
	}

	void preorder(_Node* n)
	{
		if (n->left != NULL)
			preorder(n->left);
		if (n->right != NULL)
			preorder(n->right);
		cout << n->value << '\n';
	}
} Node;
int main()
{
	Node* tree = new Node(-1);
	int a;
	while (cin >> a)
	{
		if (tree->value == -1)
			tree->value = a;
		else
			tree->insertNode(a);
	}

	tree->preorder(tree);
}

// https://www.acmicpc.net/problem/5639

/*
Reminding knowledge that I learned at college. 
*/