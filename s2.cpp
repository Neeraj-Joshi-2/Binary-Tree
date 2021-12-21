// C++ implementation to find the sum of all
// the parent nodes having child node x
#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* getNode(int data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void sumOfParentOfX(Node* root, int& sum, int x)
{
	if (!root)
		return;
	
	if ((root->left && root->left->data == x) || (root->right && root->right->data == x))
		sum += root->data;

	sumOfParentOfX(root->left, sum, x);
	sumOfParentOfX(root->right, sum, x);
	
}

int sumOfParentOfXUtil(Node* root, int x)
{
	int sum = 0;
	sumOfParentOfX(root, sum, x);
	return sum;
}

int main()
{
	Node *root = getNode(4);		 
	root->left = getNode(2);		
	root->right = getNode(5);		
	root->left->left = getNode(7);
	root->left->right = getNode(2);
	root->right->left = getNode(2);
	root->right->right = getNode(3);
	
	int x = 2;
	
	cout << "Sum = " << sumOfParentOfXUtil(root, x);
		
	return 0;
}
