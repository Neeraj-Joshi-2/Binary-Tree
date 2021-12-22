// Code to find the sum of the nodes which are present at the maximum depth.
#include <bits/stdc++.h>

using namespace std;

int sum = 0, max_level = INT_MIN;

struct Node
{
    int d;
    Node *l;
    Node *r;
};

Node *createNode(int d)
{
    Node *node;
    node = new Node;
    node->d = d;
    node->l = NULL;
    node->r = NULL;
    return node;
}

void sumOfNodesAtMaxDepth(Node *ro, int level)
{
    if (ro == NULL)
        return;

    if (level > max_level)
    {
        sum = ro->d;
        max_level = level;
    }

    else if (level == max_level)
    {
        sum = sum + ro->d;
    }

    sumOfNodesAtMaxDepth(ro->l, level + 1);
    sumOfNodesAtMaxDepth(ro->r, level + 1);
}

int main()
{
    Node *root;
    root = createNode(1);
    root->l = createNode(2);
    root->r = createNode(3);
    root->l->l = createNode(4);
    root->l->r = createNode(5);
    root->r->l = createNode(6);
    root->r->r = createNode(7);

    sumOfNodesAtMaxDepth(root, 0);

    cout << sum;
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

	// Constructor
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int sumMaxLevelRec(Node *node, int max)
{
	if (node == NULL)
		return 0;

	if (max == 1)
		return node->data;

	return sumMaxLevelRec(node->left, max - 1) + sumMaxLevelRec(node->right, max - 1);
}

int maxDepth(Node *node)
{
	if (node == NULL)
		return 0;

	return 1 + max(maxDepth(node->left), maxDepth(node->right));
}

int sumMaxLevel(Node *root)
{
	int MaxDepth = maxDepth(root);

	return sumMaxLevelRec(root, MaxDepth);
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout << (sumMaxLevel(root)) << endl;
}

*/