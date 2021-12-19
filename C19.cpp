/* C++ program to print all of its root-to-leaf paths for a tree*/
#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
};

void printArray(int [], int);
void printPathsRecur(node*, int [], int);
node* newNode(int );
void printPaths(node*);


void printPaths(node* node)
{
	int path[1000];
	printPathsRecur(node, path, 0);
}

void printPathsRecur(node* node, int path[], int pathLen)
{
	if (node == NULL) return;
	
	path[pathLen] = node->data;
	pathLen++;
	
	if (node->left == NULL && node->right == NULL)
	{
		printArray(path, pathLen);
	}
	else
	{
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
	}
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	
	return(Node);
}

void printArray(int ints[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		cout << ints[i] << " ";
	}
	cout << endl;
}

int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	printPaths(root);
	return 0;
}
