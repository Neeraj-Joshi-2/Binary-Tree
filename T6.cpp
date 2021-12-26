// C++ implementation to replace each node in binary tree with the sum of its inorder
// predecessor and successor
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left, *right;
};

struct Node* getNode(int data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->left = new_node->right = NULL;

	return new_node;
}

void storeInorderTraversal(Node* root, vector<int>& arr)
{
	if (!root)
		return;

	storeInorderTraversal(root->left, arr);

	arr.push_back(root->data);

	storeInorderTraversal(root->right, arr);
}

void replaceNodeWithSum(Node* root, vector<int> arr, int* i)
{
	if (!root)
		return;

	replaceNodeWithSum(root->left, arr, i);

	root->data = arr[*i - 1] + arr[*i + 1];

	++*i;

	replaceNodeWithSum(root->right, arr, i);
}

void replaceNodeWithSumUtil(struct Node* root)
{
	if (!root)
		return;

	vector<int> arr;

	arr.push_back(0);

	storeInorderTraversal(root, arr);

	arr.push_back(0);

	int i = 1;
	replaceNodeWithSum(root, arr, &i);
}

void preorderTraversal(struct Node* root)
{
	// if root is NULL
	if (!root)
		return;

	// first print the data of node
	cout << root->data << " ";

	// then recur on left subtree
	preorderTraversal(root->left);

	// now recur on right subtree
	preorderTraversal(root->right);
}

int main()
{
	// binary tree formation
	struct Node* root = getNode(1); /*1	 */
	root->left = getNode(2);	 /*	 / \	 */
	root->right = getNode(3);	 /*	 2	 3	 */
	root->left->left = getNode(4); /* / \ / \ */
	root->left->right = getNode(5); /* 4 5 6 7 */
	root->right->left = getNode(6);
	root->right->right = getNode(7);

	cout << "Preorder Traversal before tree modification:n";
	preorderTraversal(root);

	replaceNodeWithSumUtil(root);

	cout << "\nPreorder Traversal after tree modification:n";
	preorderTraversal(root);

	return 0;
}
