// C++ program to check whether a given Binary Tree is full or not
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left, *right;
};

struct Node *newNode(char k)
{
	struct Node *node = new Node;
	node->key = k;
	node->right = node->left = NULL;
	return node;
}

bool isFullTree (Node* root)
{
	if (root == NULL)
		return true;

	if (root->left == NULL && root->right == NULL)
		return true;

	if ((root->left) && (root->right))
		return (isFullTree(root->left) && isFullTree(root->right));

	return false;
}

int main()
{
	struct Node* root = NULL;
	root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);

	root->left->right = newNode(40);
	root->left->left = newNode(50);
	root->right->left = newNode(60);
	root->right->right = newNode(70);

	root->left->left->left = newNode(80);
	root->left->left->right = newNode(90);
	root->left->right->left = newNode(80);
	root->left->right->right = newNode(90);
	root->right->left->left = newNode(80);
	root->right->left->right = newNode(90);
	root->right->right->left = newNode(80);
	root->right->right->right = newNode(90);

	if (isFullTree(root))
		cout << "The Binary Tree is full\n";
	else
		cout << "The Binary Tree is not full\n";

	return(0);
}



/*
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* getNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

bool isFullBinaryTree(Node* root)
{
	if (!root)
		return true;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) 
	{
		Node* node = q.front();
		q.pop();

		if (node->left == NULL && node->right == NULL)
			continue;

		if (node->left == NULL || node->right == NULL)
			return false;

		q.push(node->left);
		q.push(node->right);
	}

	return true;
}

int main()
{
	Node* root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);

	if (isFullBinaryTree(root))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}

*/