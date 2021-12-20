// C++ Program to find common nodes for given two nodes
#include <bits/stdc++.h>
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

struct Node *findLCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->key == n1 || root->key == n2)
        return root;

    Node *left_lca = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca)
        return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

bool printAncestors(Node *root, int target)
{
    if (root == NULL)
        return false;

    if (root->key == target)
    {
        cout << root->key << " ";
        return true;
    }

    if (printAncestors(root->left, target) || printAncestors(root->right, target))
    {
        cout << root->key << " ";
        return true;
    }

    return false;
}

bool findCommonNodes(Node *root, int first, int second)
{
    Node *LCA = findLCA(root, first, second);
    if (LCA == NULL)
        return false;

    printAncestors(root, LCA->key);
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
    root->left->left->left = newNode(8);
    root->right->left->left = newNode(9);
    root->right->left->right = newNode(10);

    if (findCommonNodes(root, 9, 7) == false)
        cout << "No Common nodes";

    return 0;
}