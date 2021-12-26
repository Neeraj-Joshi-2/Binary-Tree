// CPP program to find inorder successor of a node

/*

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

void inorderSuccessor(Node* root, Node* target_node, Node* &next)
{
	if(!root)
		return;

	inorderSuccessor(root->right, target_node, next);
	
	if(root->data == target_node->data)
	{
		if(next == NULL)
			cout << "inorder successor of " << root->data << " is: null\n";
		else
			cout << "inorder successor of " << root->data << " is: " << next->data << "\n";
	}
	next = root;
	inorderSuccessor(root->left, target_node, next);
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);

	Node* next = NULL;
	inorderSuccessor(root, root->right, next);

	next = NULL;
	inorderSuccessor(root, root->left->left, next);

	next = NULL;
	inorderSuccessor(root, root->right->right, next);
	
	return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node* temp = new Node;

Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

Node* leftMostNode(Node* node)
{
	while (node != NULL && node->left != NULL)
		node = node->left;
	return node;
}

Node* rightMostNode(Node* node)
{
	while (node != NULL && node->right != NULL)
		node = node->right;
	return node;
}

Node* findInorderRecursive(Node* root, Node* x )
{
	if (!root)
		return NULL;

	if (root==x || (temp = findInorderRecursive(root->left,x)) || (temp = findInorderRecursive(root->right,x)))
	{
		if (temp)
		{   
			if (root->left == temp)
			{
				cout << "Inorder Successor of " << x->data;
				cout << " is "<< root->data << "\n";
				return NULL;
			}
		}

		return root;
	}

	return NULL;
}

void inorderSuccesor(Node* root, Node* x)
{
	if (x->right != NULL)
	{
		Node* inorderSucc = leftMostNode(x->right);
		cout<<"Inorder Successor of "<<x->data<<" is ";
		cout<<inorderSucc->data<<"\n";
	}

	if (x->right == NULL)
	{	
		int f = 0;
		
		Node* rightMost = rightMostNode(root);

		// case3: If x is the right most node
		if (rightMost == x)
			cout << "No inorder successor! Right most node.\n";
		else
			findInorderRecursive(root, x);
	}
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);

	inorderSuccesor(root, root->right);

	inorderSuccesor(root, root->left->right);

	inorderSuccesor(root, root->right->right);

	return 0;
}

