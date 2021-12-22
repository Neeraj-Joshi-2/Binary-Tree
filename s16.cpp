// C++ implementation to find the sum of leaf nodes at minimum level
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

int sumOfLeafNodesAtMinLevel(Node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return root->data;

    queue<Node *> q;
    int sum = 0;
    bool f = 0;

    q.push(root);

    while (f == 0)
    {
        int nc = q.size();

        while (nc--)
        {
            Node *top = q.front();
            q.pop();

            if (!top->left && !top->right)
            {
                sum += top->data;
                f = 1;
            }
            else
            {
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
        }
    }

    return sum;
}

int main()
{
    Node *root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    root->left->right->left = getNode(8);
    root->right->left->right = getNode(9);

    cout << "Sum = "
         << sumOfLeafNodesAtMinLevel(root);

    return 0;
}
