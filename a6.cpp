// C++ implementation to print the path common to the two paths from the root to the two given nodes
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

struct Node* getNode(int data)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2)
{
	if (root == NULL) return NULL;

	if (root->data == n1)
	{
		v1 = true;
		return root;
	}
	if (root->data == n2)
	{
		v2 = true;
		return root;
	}

	Node *left_lca = findLCAUtil(root->left, n1, n2, v1, v2);
	Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

	if (left_lca && right_lca) return root;

	return (left_lca != NULL)? left_lca: right_lca;
}

bool find(Node *root, int k)
{
	if (root == NULL)
		return false;

	if (root->data == k || find(root->left, k) || find(root->right, k))
		return true;

	return false;
}

Node *findLCA(Node *root, int n1, int n2)
{
	bool v1 = false, v2 = false;

	Node *lca = findLCAUtil(root, n1, n2, v1, v2);

	if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
		return lca;

	return NULL;
}

bool hasPath(Node *root, vector<int>& arr, int x)
{
	if (!root)
		return false;
	
	arr.push_back(root->data);
	
	if (root->data == x)
		return true;
	
	if (hasPath(root->left, arr, x) || hasPath(root->right, arr, x))
		return true;
	
	arr.pop_back();
	return false;		
}

void printCommonPath(Node *root, int n1, int n2)
{
	vector<int> arr;
	
	Node *lca = findLCA(root, n1, n2);

	if (lca)
	{
		if (hasPath(root, arr, lca->data))
		{
			for (int i=0; i<arr.size()-1; i++)
				cout << arr[i] << "->";
			cout << arr[arr.size() - 1];
		}
	}
	
	else
		cout << "No Common Path";
}

int main()
{
	struct Node *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	root->right->left = getNode(6);
	root->right->right = getNode(7);
	root->left->right->left = getNode(8);
	root->right->left->right = getNode(9);
		
	int n1 = 4, n2 = 8;
	printCommonPath(root, n1, n2);
	return 0;
}
