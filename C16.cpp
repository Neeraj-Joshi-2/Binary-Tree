// C++ program to see if two trees are identical
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

int identicalTrees(node *a, node *b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a != NULL && b != NULL)
    {
        return (a->data == b->data && identicalTrees(a->left, b->left) && identicalTrees(a->right, b->right));
    }

    return 0;
}

int main()
{
    node *root1 = newNode(1);
    node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    if (identicalTrees(root1, root2))
        cout << "Both tree are identical.";
    else
        cout << "Trees are not identical.";

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

bool areIdentical(Node *root1, Node *root2)
{
	if (root1==NULL && root2==NULL) return true;

	if (root1 == NULL) return false;
	if (root2 == NULL) return false;
	
	queue<Node *> q1, q2;

	q1.push(root1);
	q2.push(root2);

	while (!q1.empty() && !q2.empty())
	{
		Node *n1 = q1.front();
		Node *n2 = q2.front();

		if (n1->data != n2->data)
		return false;

		q1.pop(), q2.pop();

		if (n1->left && n2->left)
		{
			q1.push(n1->left);
			q2.push(n2->left);
		}

		else if (n1->left || n2->left)
			return false;

		if (n1->right && n2->right)
		{
			q1.push(n1->right);
			q2.push(n2->right);
		}
		else if (n1->right || n2->right)
			return false;
	}

	return true;
}

Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int main()
{
	Node *root1 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);

	Node *root2 = newNode(1);
	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(4);
	root2->left->right = newNode(5);

	areIdentical(root1, root2)? cout << "Yes" : cout << "No";
	return 0;
}

*/
