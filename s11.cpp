// C++ program to find if there is a subtree with given sum
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

struct Node* newnode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

bool sumSubtreeUtil(Node *ptr, int *cur_sum, int sum)
{
	if (ptr == NULL)
	{
		*cur_sum = 0;
		return false;
	}

	int sum_left = 0, sum_right = 0;

	return ( sumSubtreeUtil(ptr->left, &sum_left, sum) || sumSubtreeUtil(ptr->right, &sum_right, sum) ||
		((*cur_sum = sum_left + sum_right + ptr->data) == sum));
}

bool sumSubtree(struct Node *root, int sum)
{
	int cur_sum = 0;

	return sumSubtreeUtil(root, &cur_sum, sum);

}

int main()
{
	struct Node *root = newnode(8);
	root->left = newnode(5);
	root->right = newnode(4);
	root->left->left = newnode(9);
	root->left->right = newnode(7);
	root->left->right->left = newnode(1);
	root->left->right->right = newnode(12);
	root->left->right->right->right = newnode(2);
	root->right->right = newnode(11);
	root->right->right->left = newnode(3);
	int sum = 22;

	if (sumSubtree(root, sum))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
