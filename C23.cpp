// A C++ program to find the all full nodes in a given binary tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


void findFullNode(Node *root)
{
	if (root != NULL)
	{
		findFullNode(root->left);
		if (root->left != NULL && root->right != NULL)
			cout << root->data << " ";
		findFullNode(root->right);
	}
}


int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->right = newNode(7);
	root->right->right->right = newNode(8);
	root->right->left->right->left = newNode(9);
	findFullNode(root);
	return 0;
}
