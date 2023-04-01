
#include <iostream>
#include<vector>


using namespace std;

struct Node {
	int data;
	Node* next;
};

class Singly_linked_list {

public:
	Node* head, * tail;

	Singly_linked_list() {
		head = NULL;
		tail = NULL;
	}

	void PushFront(int key) {
		Node* temp = new Node();

		
		temp->data = key;
		temp->next = head;
		if (head == NULL) {
			tail = temp;
		}
		head = temp;
		
	}

	void PushBack(int key) {
		Node* temp = new Node();

		temp->data = key;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			return;
		}
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = temp;
	}

	void Display() {
		Node* temp = head;

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void Reverse() {
		Node* current, * prev, * next;
		current = head;
		prev = NULL;

		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

};


int GetLength(Node* head) {
	Node* current = head;
	int count = 0;

	while (current != 0) {
		count++;
		current = current->next;
	}
	return count;
}


Singly_linked_list divideList(Singly_linked_list z) {

	Singly_linked_list y;
	Node* current = z.head;

	int len = GetLength(z.head);
	int s = len / 2;
	int i = 0;
	while (i < len) {
		i++;
		if (i <= s) {
			current = current->next;
			continue;
		}
		else {
			int x = current->data;
			y.PushFront(x);
		}
		current = current->next;

	}
	return y;
}


Singly_linked_list Divide(Singly_linked_list x) {
	Singly_linked_list y;
	Node* slow = x.head, * fast = x.head;

	while (fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
		if (fast->next == NULL) {
			break;
		}
		fast = fast->next;
	}
	y.head = slow;
	return y;
}

int main()
{
	Singly_linked_list a;

	int n, x;
	cin >> n;
	while (n) {
		cin >> x;
		a.PushFront(x);
		n--;
	}
	a.Display();
	//a.Reverse();
	//a.Display();

	//Singly_linked_list b= divideList(a);
	//b.Display();
	Singly_linked_list c = Divide(a);
	c.Display();
	return 0;
}

