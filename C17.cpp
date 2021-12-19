// C++ program to see if there is a root to leaf path with given sequence.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newnode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

bool existPathUtil(struct Node *root, int arr[], int n, int index)
{
    if (root == NULL or index == n)
        return false;

    if (root->left == NULL && root->right == NULL)
    {
        if ((root->data == arr[index]) && (index == n - 1))
            return true;

        return false;
    }

    return ((index < n) && (root->data == arr[index]) &&
            (existPathUtil(root->left, arr, n, index + 1) ||
             existPathUtil(root->right, arr, n, index + 1)));
}

bool existPath(struct Node *root, int arr[], int n, int index)
{
    if (!root)
        return (n == 0);

    return existPathUtil(root, arr, n, 0);
}

int main()
{
    int arr[] = {5, 8, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node *root = newnode(5);
    root->left = newnode(3);
    root->right = newnode(8);
    root->left->left = newnode(2);
    root->left->right = newnode(4);
    root->left->left->left = newnode(1);
    root->right->left = newnode(6);
    root->right->left->right = newnode(7);

    existPath(root, arr, n, 0) ? cout << "Path Exists" : cout << "Path does not Exist";
    return 0;
}
