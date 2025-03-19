#include <iostream>
#include <climits>

class Node 
{
	
	public:

		int data;
		Node* next;
		
		Node(int data) {
				this->data = data;
				this->next = nullptr;
			}

};

class Stack 
{
	Node* head;

	public:
		Stack() { this->head = nullptr; } 

	bool isEmpty() 
	{
			return head == nullptr;
	}

	void push(int key) {

		Node* nn = new Node(key);
		nn->next = head;
		head = nn;
	}

	 void pop() {
		
		if (this->isEmpty())
		{
				std::cout << "Stack underflow \n " << std::endl;
		} else {
				
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}


	 int peek() {
			
		if (this->isEmpty())
		{
				std::cout << "Stack underflow \n " << std::endl;
				return INT_MIN;
		} else {
		
			return head->data;
		}
	 } 
};

int main()
{
	Stack s;

	s.push(11);
	s.push(12);
	s.push(13);

	while (!s.isEmpty()) {
		std::cout << s.peek() << " \n";
		s.pop();
	}

	return 0;


}
