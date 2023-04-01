
#include <iostream>
#include<vector>
#include<stack>

using namespace std;

struct Node {
	int data;
	struct Node* left, * right;
};

Node* newNode(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printInorder(struct Node* node) {

	if (node == NULL)
		return;
	else {
		printInorder(node->left);
		cout << node->data << " ";
		printInorder(node->right);
	}
}

Node* insert(struct Node* root, int val) {

	Node* temp = newNode(val);
	Node* parent = root;
	Node* child = NULL;
	int flag = 1;

	while (parent!=NULL)
	{
		child = parent;

		if (val >= (parent->data - 3) && val <= (parent->data + 3)) 
		{
			flag = 0;
			break;
		}

		else if (val < parent->data)
		{
			parent = parent->left;
		}
		else{
			parent = parent->right;
		}
	}

	if (flag == 1)
	{

		if (child == NULL) {
			child = temp;
		}

		else if (val < child->data){
			child->left = temp;
		}

		else {
			child->right = temp;
		}
	}
	return child;
}
int main()
{
	int n, f = 0;
	Node *root = NULL;
	while (1) {
		cin >> n;
		if (n == -1) break;
		if (f == 0) {
			root = insert(root, n);
			f++;
		}
		else {
			insert(root, n);
		}
	}
	printInorder(root);
	return 0;
}

