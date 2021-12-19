// C++ code to convert a given binary tree
// to a tree that holds logical AND property.
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int key)
{
	struct Node* node = new Node;
	node->data= key;
	node->left = node->right = NULL;
	return node;
}

void convertTree(Node *root)
{
	if (root == NULL)
		return;

	convertTree(root->left);

	convertTree(root->right);

	if (root->left != NULL && root->right != NULL)
		root->data = (root->left->data) & (root->right->data);
}

void printInorder(Node* root)
{
	if (root == NULL)
		return;
	printInorder(root->left);
	printf("%d ", root->data);
	printInorder(root->right);
}

int main()
{
	Node *root=newNode(0);
	root->left=newNode(1);
	root->right=newNode(0);
	root->left->left=newNode(0);
	root->left->right=newNode(1);
	root->right->left=newNode(1);
	root->right->right=newNode(1);
	printf("\n Inorder traversal before conversion ");
	printInorder(root);

	convertTree(root);

	printf("\n Inorder traversal after conversion ");
	printInorder(root);
	return 0;
}
