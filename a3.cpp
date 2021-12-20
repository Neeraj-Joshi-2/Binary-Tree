/* C++ program to find distance between n1 and n2 using one traversal */

//We first find the LCA of two nodes. Then we find the distance from LCA to two nodes. 

/*
#include <iostream>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int key;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return root;
    if (root->key == n1 || root->key == n2)
        return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;
    if (left == NULL && right == NULL)
        return NULL;
    if (left != NULL)
        return LCA(root->left, n1, n2);

    return LCA(root->right, n1, n2);
}

int findLevel(Node *root, int k, int level)
{
    if (root == NULL)
        return -1;
    if (root->key == k)
        return level;

    int left = findLevel(root->left, k, level + 1);
    if (left == -1)
        return findLevel(root->right, k, level + 1);
    return left;
}

int findDistance(Node *root, int a, int b)
{
    Node *lca = LCA(root, a, b);

    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);

    return d1 + d2;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);

    return 0;
}

*/

// Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)

#include <iostream>
using namespace std;

struct Node
{
	struct Node *left, *right;
	int key;
};

Node* newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

int findLevel(Node *root, int k, int level)
{
	if (root == NULL)
		return -1;

	if (root->key == k)
		return level;

	int l = findLevel(root->left, k, level+1);

	return (l != -1)? l : findLevel(root->right, k, level+1);
}

Node *findDistUtil(Node* root, int n1, int n2, int &d1, int &d2, int &dist, int lvl)
{
	if (root == NULL) return NULL;

	if (root->key == n1)
	{
		d1 = lvl;
		return root;
	}
	if (root->key == n2)
	{
		d2 = lvl;
		return root;
	}

	Node *left_lca = findDistUtil(root->left, n1, n2, d1, d2, dist, lvl+1);
	Node *right_lca = findDistUtil(root->right, n1, n2, d1, d2, dist, lvl+1);

	if (left_lca && right_lca)
	{
		dist = d1 + d2 - 2*lvl;
		return root;
	}

	return (left_lca != NULL)? left_lca: right_lca;
}

int findDistance(Node *root, int n1, int n2)
{
	int d1 = -1, d2 = -1, dist;

	Node *lca = findDistUtil(root, n1, n2, d1, d2, dist, 1);

	if (d1 != -1 && d2 != -1)
		return dist;

	if (d1 != -1)
	{
		dist = findLevel(lca, n2, 0);
		return dist;
	}

	if (d2 != -1)
	{
		dist = findLevel(lca, n1, 0);
		return dist;
	}

	return -1;
}

int main()
{
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	cout << "Dist(2, 1) = " << findDistance(root, 2, 1);
	cout << "nDist(4, 6) = " << findDistance(root, 4, 6);
	cout << "nDist(3, 4) = " << findDistance(root, 3, 4);
	cout << "nDist(2, 4) = " << findDistance(root, 2, 4);
	cout << "nDist(8, 5) = " << findDistance(root, 8, 5);

	return 0;
}
