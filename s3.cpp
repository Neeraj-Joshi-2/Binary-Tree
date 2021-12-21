// A C++ program to find sum of all left leaves
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

Node *newNode(char k)
{
    Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

bool isLeaf(Node *node)
{
    if (node == NULL)
        return false;
    if (node->left == NULL && node->right == NULL)
        return true;
    return false;
}

int leftLeavesSum(Node *root)
{
    int res = 0;

    if (root != NULL)
    {
        if (isLeaf(root->left))
            res += root->left->key;
        else
            res += leftLeavesSum(root->left);

        res += leftLeavesSum(root->right);
    }

    return res;
}

int main()
{
    struct Node *root = newNode(20);
    root->left = newNode(9);
    root->right = newNode(49);
    root->right->left = newNode(23);
    root->right->right = newNode(52);
    root->right->right->left = newNode(50);
    root->left->left = newNode(5);
    root->left->right = newNode(12);
    root->left->right->right = newNode(12);
    cout << "Sum of left leaves is " << leftLeavesSum(root);
    return 0;
}
