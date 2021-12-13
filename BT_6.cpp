#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left, * right;
};

struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

bool treeContinuous(struct Node *ptr)
{
	if (ptr == NULL)
		return true;

	if (ptr->left == NULL && ptr->right == NULL)
		return true;

	if (ptr->left == NULL)
	return (abs(ptr->data - ptr->right->data) == 1) && treeContinuous(ptr->right);

	if (ptr->right == NULL)
	return (abs(ptr->data - ptr->left->data) == 1) && treeContinuous(ptr->left);

	return abs(ptr->data - ptr->left->data)==1 && abs(ptr->data - ptr->right->data)==1 && 
    treeContinuous(ptr->left) && treeContinuous(ptr->right);
}

int main()
{
	struct Node *root = newNode(3);
	root->left	 = newNode(2);
	root->right	 = newNode(4);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(5);
	treeContinuous(root)? cout << "Yes" : cout << "No";
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    node() : val(0), left(nullptr), right(nullptr)
    {
    }
    node(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    node(int x, node *left, node *right) : val(x), left(left), right(right)
    {
    }
};

bool continuous(node *root)
{
    if (root == NULL)
        return false;

    int flag = 1;
    queue<node *> Q;
    Q.push(root);
    node *temp;

    while (!Q.empty())
    {
        temp = Q.front();
        Q.pop();

        if (temp->left)
        {
            if (abs(temp->left->val - temp->val) == 1)
                Q.push(temp->left);
            else
            {
                flag = 0;
                break;
            }
        }

        if (temp->right)
        {
            if (abs(temp->right->val - temp->val) == 1)
                Q.push(temp->right);
            else
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag)
        return true;
    else
        return false;
}

int main()
{
    node *root = new node(3);
    root->left = new node(2);
    root->right = new node(4);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(5);

    if (continuous(root))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}

*/