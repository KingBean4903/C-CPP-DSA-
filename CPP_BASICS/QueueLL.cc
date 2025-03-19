#include <iostream>
#include <climits>

struct Node 
{
	int data;
	Node* next;
	Node(int data)
	{
			this->data = data;
			this->next = nullptr;
	}

};

class Queue
{
	
	Node *front, *rear;

	public:
		Queue() { front = rear = nullptr; }

		void enqueue(int x)
		{
				
			Node* nn =  new Node(x);
			
			if (isEmpty())
			{
					front = rear = nn;
					return;
			}


			rear->next = nn;
			rear = nn;

		}


		void dequeue()
		{
				if (isEmpty())
					return;

				Node* temp = front;
				front = front->next;

				if (front == nullptr)
						rear = nullptr;

				delete temp;
		}


		bool isEmpty()
		{
			
			if (front == nullptr)
						return true;

			return false;
		}

		int getFront()
		{
			
			if (isEmpty())
					return 	INT_MIN;

			return front->data;

		}
	

		int getRear()
		{
			
			if (isEmpty())
					return 	INT_MIN;

			return rear->data;

		}

};

int main()
{
	
	Queue q;

	q.enqueue(50);
	q.enqueue(51);
	q.enqueue(52);
	q.dequeue();
	q.enqueue(53);
	q.enqueue(54);

	std::cout << q.getFront() << " ";
	
	std::cout << q.getRear() << " ";
	
	while (!q.isEmpty()) {
		std::cout << q.getFront() << " \n";
		q.dequeue();
	}

	return 0;

}
