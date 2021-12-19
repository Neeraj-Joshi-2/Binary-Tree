// A C++ program for in-place conversion of Binary Tree to DLL
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void BinaryTree2DoubleLinkedList(node *root, node **head)
{
	if (root == NULL) return;

	static node* prev = NULL;

	BinaryTree2DoubleLinkedList(root->left, head);

	if (prev == NULL)
		*head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	BinaryTree2DoubleLinkedList(root->right, head);
}

node* newNode(int data)
{
	node* new_node = new node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

void printList(node *node)
{
	while (node!=NULL)
	{
		cout << node->data << " ";
		node = node->right;
	}
}

int main()
{
	node *root	 = newNode(10);
	root->left	 = newNode(12);
	root->right	 = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);


	node *head = NULL;
	BinaryTree2DoubleLinkedList(root, &head);


	printList(head);

	return 0;
}
/*
#include <bits/stdc++.h>

struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void BToDLL(Node* root, Node*& head)
{
	if (root == NULL)
		return;

	BToDLL(root->right, head);

	root->right = head;

	if (head != NULL)
		head->left = root;

	head = root;

	BToDLL(root->left, head);
}

void printList(Node* head)
{
	printf("Extracted Double Linked list is:\n");
	while (head) {
		printf("%d ", head->data);
		head = head->right;
	}
}

int main()
{
	Node* root = newNode(5);
	root->left = newNode(3);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->right->right = newNode(8);
	root->left->left->left = newNode(0);
	root->left->left->right = newNode(2);
	root->right->right->left = newNode(7);
	root->right->right->right = newNode(9);

	Node* head = NULL;
	BToDLL(root, head);

	printList(head);

	return 0;
}

*/