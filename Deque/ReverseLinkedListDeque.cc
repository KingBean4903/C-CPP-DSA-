#include <iostream>
#include <deque>

class Node {

	public:
		int data;
		Node* next;
		Node(int data) {
			this->data = data;
		}
};

Node* reverseList(Node *head, int k) 
{
	
	if (!head || k == 1) {
		return head;
	}
	
	std::deque<Node*> dq;
	Node* curr = head;

	while(curr != nullptr) {
		int count = 0;
			
		while(curr != nullptr && count < k) {
			dq.push_back(curr);			
			curr = curr->next;
			count++;
		}

		while(!dq.empty()) {
			Node* front = dq.front();
			Node* back = dq.back();
			swap(front->data, back->data);

			if (!d.empty()) {
				dq.pop_front();
			}

			if (!d.empty()) {
				dq.pop_back();
			}
			
		}


	}


	return head;
}

