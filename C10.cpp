/* C++ program to check if all three given traversals are of the same tree */
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int search(int arr[], int strt, int end, int value)
{
	for (int i = strt; i <= end; i++)
	{
		if(arr[i] == value)
			return i;
	}
}

Node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if(inStrt > inEnd)
		return NULL;

	Node *tNode = newNode(pre[preIndex++]);

	if (inStrt == inEnd)
		return tNode;


	int inIndex = search(in, inStrt, inEnd, tNode->data);

	tNode->left = buildTree(in, pre, inStrt, inIndex-1);
	tNode->right = buildTree(in, pre, inIndex+1, inEnd);

	return tNode;
}

int checkPostorder(Node* node, int postOrder[], int index)
{
	if (node == NULL)
		return index;

	index = checkPostorder(node->left,postOrder,index);
	
	index = checkPostorder(node->right,postOrder,index);

	if (node->data == postOrder[index])
		index++;
	else
		return -1;

	return index;
}

int main()
{
	int inOrder[] = {4, 2, 5, 1, 3};
	int preOrder[] = {1, 2, 4, 5, 3};
	int postOrder[] = {4, 5, 2, 3, 1};

	int len = sizeof(inOrder)/sizeof(inOrder[0]);

	Node *root = buildTree(inOrder, preOrder, 0, len - 1);

	int index = checkPostorder(root,postOrder,0);

	if (index == len)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
