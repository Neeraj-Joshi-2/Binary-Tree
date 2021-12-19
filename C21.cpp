// C++ program to Print root to leaf path WITHOUt using recursion
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void printTopToBottomPath(Node* curr, map<Node*, Node*> parent)
{
	stack<Node*> stk;

	while (curr)
	{
		stk.push(curr);
		curr = parent[curr];
	}

	while (!stk.empty())
	{
		curr = stk.top();
		stk.pop();
		cout << curr->data << " ";
	}
	cout << endl;
}


void printRootToLeaf(Node* root)
{
	if (root == NULL)
		return;

	stack<Node*> nodeStack;
	nodeStack.push(root);

	map<Node*, Node*> parent;

	parent[root] = NULL;

	while (!nodeStack.empty())
	{
		Node* current = nodeStack.top();
		nodeStack.pop();


		if (!(current->left) && !(current->right))
			printTopToBottomPath(current, parent);

		if (current->right)
		{
			parent[current->right] = current;
			nodeStack.push(current->right);
		}
		if (current->left)
		{
			parent[current->left] = current;
			nodeStack.push(current->left);
		}
	}
}

int main()
{
	Node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);

	printRootToLeaf(root);

	return 0;
}
