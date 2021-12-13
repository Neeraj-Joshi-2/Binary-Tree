#include <bits/stdc++.h>
using namespace std;

// #define bool int
// #define true 1
// #define false 0

class node
{
public:
    int data;
    node *left;
    node *right;
};

void mirror(node *node);

bool isStructSame(node *a, node *b);

bool isFoldable(node *root)
{
    bool res;

    if (root == NULL)
        return true;

    mirror(root->left);

    res = isStructSame(root->left, root->right);

    mirror(root->left);

    return res;
}

bool isStructSame(node *a, node *b)
{
    if (a == NULL && b == NULL)
    {
        return true;
    }
    if (a != NULL && b != NULL && isStructSame(a->left, b->left) && isStructSame(a->right, b->right))
    {
        return true;
    }

    return false;
}

void mirror(node *Node)
{
    if (Node == NULL)
        return;
    else
    {
        node *temp;

        mirror(Node->left);
        mirror(Node->right);

        temp = Node->left;
        Node->left = Node->right;
        Node->right = temp;
    }
}

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

int main(void)
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->left->right = newNode(5);

    if (isFoldable(root) == 1)
    {
        cout << "tree is foldable";
    }
    else
    {
        cout << "\ntree is not foldable";
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

bool IsFoldableUtil(node* n1, node* n2);

bool IsFoldable(node* root)
{
	if (root == NULL) {
		return true;
	}

	return IsFoldableUtil(root->left, root->right);
}

bool IsFoldableUtil(node* n1, node* n2)
{
	if (n1 == NULL && n2 == NULL) {
		return true;
	}

	if (n1 == NULL || n2 == NULL) {
		return false;
	}

	return IsFoldableUtil(n1->left, n2->right) && IsFoldableUtil(n1->right, n2->left);
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

int main(void)
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);

	if (IsFoldable(root) == true) {
		cout << "Tree is foldable";
	}
	else {
		cout << "Tree is not foldable";
	}

	return 0;
}

*/

/*
// Java code for the above approach

import java.util.Queue;
import java.util.LinkedList;

public class FoldableTrees {
    Node root = null;

    class Node {
        int key;
        Node left;
        Node right;

        Node(int key) {
            this.key = key;
            left = right = null;
        }
    }

    boolean isFoldable() {

        Queue<Node> q = new LinkedList<>();

        if (root != null) {
            q.add(root.left);
            q.add(root.right);
        }

        while (!q.isEmpty()) {

            Node p = q.remove();
            Node r = q.remove();

            if (p == null && r == null)
                continue;

            if ((p == null && r != null) || (p != null && r == null))
                return false;

            q.add(p.left);
            q.add(r.right);
            q.add(p.right);
            q.add(r.left);
        }

        // Only if the tree is foldable
        return true;
    }

    public static void main(String args[]) {
        FoldableTrees tree = new FoldableTrees();

        tree.root = tree.new Node(1);
        tree.root.left = tree.new Node(2);
        tree.root.right = tree.new Node(3);
        tree.root.right.left = tree.new Node(4);
        tree.root.left.right = tree.new Node(5);

        if (tree.isFoldable())
            System.out.println("Tree is foldable");
        else
            System.out.println("Tree is not foldable");
    }
}

*/