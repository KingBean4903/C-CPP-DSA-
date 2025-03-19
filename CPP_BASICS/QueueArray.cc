#include <iostream>
#include <vector>

class Queue 
{
	
	int size;
	int front;
	int capacity;
	std::vector<int> arr;

	public:
		Queue(int cap) {
			size = 0;
			front = 0;
			capacity = cap;
			arr.resize(cap);
		}

		void enqueue(int x) {
		
				if (size == capacity)
						return;
				else 
					arr[size] = x;

				size++;
		}


		void dequeue()
		{
				if (size <= 0)
					return;
				else
					for (int i = 1; i < size; i++)
								arr[i - 1] = arr[i];

				size--;
		}

		int peek()
		{
				
				if (size == 0)
						return -1;
				else 
					return arr[front];
		}

		void printQueue()
		{

			for (int i = front; i < size; i++)
					std::cout << arr[i] << " ";
			std::cout << std::endl;
		}

};

int main()
{
	
	Queue* q = new Queue(5);

	q->enqueue(3);
	q->enqueue(4);
	q->enqueue(5);
	q->dequeue();
	q->enqueue(6);
	q->enqueue(7);


	q->printQueue();

	return 0;
}


