// C++ implementation to count subtress that sum up to a given value x
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *getNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int countSubtreesWithSumX(Node *root, int &count, int x)
{
    if (!root)
        return 0;

    int ls = countSubtreesWithSumX(root->left, count, x);
    int rs = countSubtreesWithSumX(root->right, count, x);

    int sum = ls + rs + root->data;

    if (sum == x)
        count++;
    return sum;
}

int countSubtreesWithSumXUtil(Node *root, int x)
{
    if (!root)
        return 0;

    int count = 0;

    int ls = countSubtreesWithSumX(root->left, count, x);
    int rs = countSubtreesWithSumX(root->right, count, x);

    if ((ls + rs + root->data) == x)
        count++;

    return count;
}

int main()
{
    Node *root = getNode(5);
    root->left = getNode(-10);
    root->right = getNode(3);
    root->left->left = getNode(9);
    root->left->right = getNode(8);
    root->right->left = getNode(-4);
    root->right->right = getNode(7);

    int x = 7;

    cout << "Count = "
         << countSubtreesWithSumXUtil(root, x);

    return 0;
}
