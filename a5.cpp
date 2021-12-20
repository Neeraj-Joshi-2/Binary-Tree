// C++ program to find maximum difference between node and its ancestor
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node* left, *right;
};

struct Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

int maxDiffUtil(Node* t, int *res)
{
	if (t == NULL)
		return INT_MAX;

	if (t->left == NULL && t->right == NULL)
		return t->key;

	int val = min(maxDiffUtil(t->left, res), maxDiffUtil(t->right, res));

	*res = max(*res, t->key - val);

	return min(val, t->key);
}

int maxDiff(Node *root)
{
	int res = INT_MIN;

	maxDiffUtil(root, &res);

	return res;
}

void inorder(Node* root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

int main()
{
	Node* root;
	root = newNode(8);
	root->left = newNode(3);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	root->right = newNode(10);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);

	printf("Maximum difference between a node and"
		" its ancestor is : %d\n", maxDiff(root));
}
