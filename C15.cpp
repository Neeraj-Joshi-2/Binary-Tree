// C++ program to check if two trees are mirror of each other
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

int areMirror(Node* a, Node* b)
{
	if (a==NULL && b==NULL)
		return true;

	if (a==NULL || b == NULL)
		return false;

	return a->data == b->data && areMirror(a->left, b->right) && areMirror(a->right, b->left);
}

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

int main()
{
	Node *a = newNode(1);
	Node *b = newNode(1);
	a->left = newNode(2);
	a->right = newNode(3);
	a->left->left = newNode(4);
	a->left->right = newNode(5);

	b->left = newNode(3);
	b->right = newNode(2);
	b->right->left = newNode(5);
	b->right->right = newNode(4);

	areMirror(a, b)? cout << "Yes" : cout << "No";

	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data)
{
	struct Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

string areMirrors(Node *root1, Node *root2)
{
	stack<Node*> st1, st2;

	while (1)
	{
		while (root1 && root2)
		{
			if (root1->data != root2->data)
				return "No";
				
			st1.push(root1);
			st2.push(root2);
			root1 = root1->left;
			root2 = root2->right;
		}
		
		if (!(root1 == NULL && root2 == NULL))
			return "No";
			
		if (!st1.empty() && !st2.empty())
		{
			root1 = st1.top();
			root2 = st2.top();
			st1.pop();
			st2.pop();

			root1 = root1->right;
			root2 = root2->left;
		}
		
		else
			break;
	}
	
	return "Yes";
}

int main()
{
	Node *root1 = newNode(1);						
	root1->left = newNode(3);	
	root1->right = newNode(2);		
	root1->right->left = newNode(5);	
	root1->right->right = newNode(4); 
	
	Node *root2 = newNode(1);		
	root2->left = newNode(2);
	root2->right = newNode(3);		 
	root2->left->left = newNode(4);	 
	root2->left->right = newNode(5);

	cout << areMirrors(root1, root2);
	return 0;
}

*/