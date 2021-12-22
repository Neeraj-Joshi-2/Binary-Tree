// Difference between sums of odd level and even level nodes of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int evenOddLevelDifference(Node* root)
{
	if (!root)
		return 0;

	queue<Node*> q;
	q.push(root);

	int level = 0;
	int evenSum = 0, oddSum = 0;

	while (!q.empty())
	{
		int size = q.size();
		level += 1;

		while(size > 0)
		{
			Node* temp = q.front();
			q.pop();

			if(level % 2 == 0)
				evenSum += temp->data;
			else
				oddSum += temp->data;

			if (temp->left)
			{
				q.push(temp->left);
			}

			if (temp->right)
			{
				q.push(temp->right);
			}
			size -= 1;
		}
	}
	
	return (oddSum - evenSum);
}

int main()
{
	Node* root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->left->right->left = newNode(3);
	root->right->right = newNode(8);
	root->right->right->right = newNode(9);
	root->right->right->left = newNode(7);

	int result = evenOddLevelDifference(root);
	cout << "diffence between sums is :: ";
	cout << result << endl;
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return (Node);
}

int getLevelDiff(node *root)
{
    if (root == NULL)
        return 0;

    return root->data - getLevelDiff(root->left) - getLevelDiff(root->right);
}

int main()
{
    node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);
    cout << getLevelDiff(root) << " is the required difference\n";
    return 0;
}

*/