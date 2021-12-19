// C++ program to check if all leaves  are at same level
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

bool checkUtil(struct Node *root, int level, int *leafLevel)
{
	if (root == NULL) return true;

	if (root->left == NULL && root->right == NULL)
	{
		if (*leafLevel == 0)
		{
			*leafLevel = level; 
			return true;
		}

		return (level == *leafLevel);
	}

	return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
}


bool check(struct Node *root)
{
	int level = 0, leafLevel = 0;
	return checkUtil(root, level, &leafLevel);
}

int main()
{
	struct Node *root = newNode(12);
	root->left = newNode(5);
	root->left->left = newNode(3);
	root->left->right = newNode(9);
	root->left->left->left = newNode(1);
	root->left->right->left = newNode(1);
    
	if (check(root))
		cout << "Leaves are at same level\n";
	else
		cout << "Leaves are not at same level\n";
	getchar();
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int checkLevelLeafNode(Node *root)
{
    if (!root)
        return 1;

    queue<Node *> q;
    q.push(root);

    int result = INT_MAX;
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        level += 1;

        while (size > 0)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);

                if (!temp->left->right && !temp->left->left)
                {
                    if (result == INT_MAX)
                        result = level;

                    else if (result != level)
                        return 0;
                }
            }

            if (temp->right)
            {
                q.push(temp->right);

                if (!temp->right->left && !temp->right->right)

                    if (result == INT_MAX)
                        result = level;

                    else if (result != level)
                        return 0;
            }
            size -= 1;
        }
    }

    return 1;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);

    int result = checkLevelLeafNode(root);

    if (result)
        cout << "All leaf nodes are at same level\n";
    else
        cout << "Leaf nodes not at same level\n";
    return 0;
}

*/