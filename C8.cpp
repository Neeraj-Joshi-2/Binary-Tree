// C program to check if two Nodes in a binary tree are cousins
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

int isSibling(struct Node *root, struct Node *a, struct Node *b)
{
    if (root == NULL)
        return 0;

    return ((root->left == a && root->right == b) || (root->left == b && root->right == a) ||
            isSibling(root->left, a, b) || isSibling(root->right, a, b));
}

int level(struct Node *root, struct Node *ptr, int lev)
{
    if (root == NULL)
        return 0;
    if (root == ptr)
        return lev;

    int l = level(root->left, ptr, lev + 1);

    if (l != 0)
        return l;

    return level(root->right, ptr, lev + 1);
}

int isCousin(struct Node *root, struct Node *a, struct Node *b)
{
    if ((level(root, a, 1) == level(root, b, 1)) && !(isSibling(root, a, b)))
        return 1;
    else
        return 0;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    Node *Node1, *Node2;
    Node1 = root->left->left;
    Node2 = root->right->right;

    isCousin(root, Node1, Node2) ? puts("Yes") : puts("No");

    return 0;
}
