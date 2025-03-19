// Segregate even and odd nodes in a LinkedList
// using Deque


void evenOdd(Node* head)
{

	deque<int> dq;

	Node* temp = head;

	while(temp != null) {
		
		if (temp->data % 2 == 0)
		{
			dq.push_front(temp->data);
		} else {
			dq.push_back(temp->data);
		}

		temp = temp->next;
	}

	temp = head;

	while(!d.empty()) {
		temp-->data = dq.front();
		dq.pop_front();
		temp = temp->next;
	}



}































