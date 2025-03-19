#include <iostream>
#include <vector>

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

class SinglyLinkedList
{
	Node* head;
	int size;

	public:
		SinglyLinkedList()
		{
				head = NULL;			
				size = 0;
		}

		void insertFront(int key)
		{
			Node* nn = new Node(key);

			if (isEmpty())
						return;
			else
					nn->next = head;
					head = nn;
		}

		void insertAtPosition(int pos, int key)
		{

			if (isEmpty())
			{
					return;
			}


			if (pos == 1) {
					Node* nn = new Node(key);
					nn->next = head;
					return;
			}

			Node* curr = head;

			for (int i = 1; i < pos - 1  && curr != NULL; i++) {
						curr = curr->next;
			}

			if (curr == nullptr)
						return;

			Node* nn = new Node(key);

			nn->next = curr->next;
			curr->next = nn;


		}



}


