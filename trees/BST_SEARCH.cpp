#include <iostream>

using namespace std;

class Node {
	public:
		int data;
		Node *left;
		Node *right;
		Node(int x) {
			data = x;
			left = nullptr;
			right = nullptr;
		}
};

bool search(struct Node *root, int x) {
	
	Node* curr = root;
	while (curr != nullptr) {
		
		if (curr->data = x) 
				return true;
		else if (curr->data < x)
				curr = curr->right;
		else 
				curr = curr->left;
	}
	return false;
}

int main() {
	
	Node* root  = new Node(20);
	root->left = new  Node(8);


	int x = 12;

	if (search(root, x))
			cout << "True";
	else 
			cout << "False";
	
	return 0;
}	
