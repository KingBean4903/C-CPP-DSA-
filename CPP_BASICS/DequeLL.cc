#include <iostream>

struct Node
{
	
	int data;
	Node* next;
	Node* prev;
	static Node* getNode(int data)
	{
		Node* nn = (Node *) malloc(sizeof(struct Node));
		nn->data = data;
		nn->next = this->prev = NULL
		return nn;
	}
};

class Deque 
{
	Node *front, *rear;
	int size;

	public:
		Deque() {
			front = rear = NULL;
			size = 0;
		}
		void insertFront(int data);
		void insertRear(int data);
		void dltRear();
		void dltFront();
		void isEmpty();
		int getFront();
		int getRear();

};

void Deque::insertFront(int data)
{

	Node* nn = Node::getNode(data);

	if (nn == NULL)
			return;

	if (front == NULL)
				rear = null;
	else 
			nn->next = front;
			front->prev = nn;
			front = nn;
	
	size++;

}

void Deque::insertRear(int data)
{

		Node* nn = Node::getNode(data);

		if (nn == NULL)
					return;
		else 
				if (rear == NULL)
						front = NULL;
				else
					  nn->prev = rear;
						rear->next = nn;
						rear = nn;
						size++;

}

void Deque::dltRear()
{
	
	if (isEmpty())
			return;
	else
				Node* temp = rear;
				rear = rear->prev;
				
				if (rear == NULL)
							front = NULL;
				else 
						rear->next = NULL;
				
				free(temp);
				size--;

}

void Deque::dltFront()
{
	
	if (isEmpty())
			return;

	else
		Node* temp = front;
		front = front->next;
		if (front == NULL)
					rear = NULL;
		else
				front->prev = NULL;
		free(temp);
		size--;
}

int Deque::getFront()
{
	
	 if (isEmpty())
		 		return INT_MIN;
	 else
		 	return front->data;

}


int Deque::getRear()
{
	
	 if (isEmpty())
		 		return INT_MIN;
	 else
		 	return rear->data;

}

int main()
{
	Deque q;

	


}
