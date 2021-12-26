// C++ program to populate inorder traversal of all nodes

/*
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;
	node *next;
};

void populateNext(node* p)
{
	static node *next = NULL;

	if (p)
	{
		populateNext(p->right);

		p->next = next;

		next = p;

		populateNext(p->left);
	}
}

node* newnode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	Node->next = NULL;

	return(Node);
}

int main()
{
	node *root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(12);
	root->right->left = newnode(4);
	root->right->right = newnode(5);
	root->left->left = newnode(3);

	populateNext(root);

	node *ptr = root->left->left;
	while(ptr)
	{
		cout << "Next of " << ptr->data << " is " << (ptr->next ? ptr->next->data: -1) << endl;
		ptr = ptr->next;
	}

	return 0;
}
*/

/*
void populateNext(node *root)
{
	node *next = NULL;

	populateNextRecur(root, &next);
}

void populateNextRecur(node* p, node **next_ref)
{
	if (p)
	{
		populateNextRecur(p->right, next_ref);
		p->next = *next_ref;
		*next_ref = p;
		populateNextRecur(p->left, next_ref);
	}
}
*/

/*
import java.util.ArrayList;


class Node{
	int data;
	Node left,right,next;
	
	Node(int data){
		this.data = data;
		left = right = next = null;
	}
}

public class Solution {
	Node root = null;
	

	ArrayList<Node> list = new ArrayList<>();
	
	void populateNext() {
		
		for(int i=0;i<list.size();i++) {

			if(i != list.size()-1) {
				list.get(i).next = list.get(i+1);
			}
			else {
				list.get(i).next = null;
			}
		}
		
		Node ptr = root.left.left;
		while (ptr != null)
		{
			int print = ptr.next != null ? ptr.next.data : -1;
			System.out.println("Next of " + ptr.data + " is: " + print);
			ptr = ptr.next;
		}
	}

	void inorder(Node root) {
		if(root!=null) {
			inorder(root.left);
			list.add(root);
			inorder(root.right);
		}
	}
	
	public static void main(String args[]) {
		Solution tree = new Solution();
	
		tree.root = new Node(10);
		tree.root.left = new Node(8);
		tree.root.right = new Node(12);
		tree.root.left.left = new Node(3);
		
		tree.inorder(tree.root);
		tree.populateNext();
	}
}


*/
