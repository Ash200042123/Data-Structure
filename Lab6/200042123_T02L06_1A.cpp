
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

 int height(Node *node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int left_height = height(node->left);
            int right_height = height(node->right);

            if (left_height > right_height)
                return (left_height + 1);
            else
                return (right_height + 1);
        }
    }

void printCurrentLevel(Node *node, int level)
    {
        if (node == NULL)
            return;
        if (level == 1)
            cout<< node->data <<  " ";
        else if (level > 1) {
            printCurrentLevel(node->left, level - 1);
            printCurrentLevel(node->right, level - 1);
        }
    }


void printLevelOrder(Node *node)
    {
        int h = height(node);
        int i;
        for (i = 1; i <= h; i++)
        {
            printCurrentLevel(node, i);
            cout<<"\n";
        }

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

    printLevelOrder(root);
	return 0;
}

