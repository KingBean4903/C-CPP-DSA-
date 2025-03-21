// Singly linked list

struct Node {
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

// Traverse a LinkedList
void traversal(Node* head) {

	while (head != nullptr) {
		std::cout << head->data << " ";
		head = head->next;
	}
	std::cout << std::endl;
}
// Search in a linkedlist
bool searchKey(Node* head, int key)
{
	Node* temp = head;

	while (temp != nullptr) {
		if (temp->data == key) {
			return true;
		}
		temp = temp->next;
	}

}

// Insert beginning
Node* insertFront(Node* head, int data)
{
	
	Node* nn = new Node(data);

	nn->next = head;

	return nn;
	
}

// Insert node at a specific position
Node* insert(Node* head, int data, int position)
{
	if (pos < 1)
		return head;
	
	if (pos == 1) {
		Node* nn = new Node(data);
		nn->next= head;
		return nn;
	}

	Node* curr = head;

	for (int i = 0; i < pos-1 && curr != nullptr; i++)
	{
		curr = curr->next;
	}

	if (curr == nullptr)
		return head;

	Node* nn = new Node(data);
	nn->next = curr->next;
	curr->next = nn;

	return head;
}

// Append to end
Node* append(Node* head, int data)
{
	
	Node* nn = new Node(data);
	if (head == nullptr)
		return nn;

	Node* last = head;
	while(last != nullptr)
	{
		last = last->next;
	}

	last->next = nn;
	return head;
}

// Delete at beginning
Node *deleteHead(Node* head)
{
	if (head == nullptr) {
		return nullptr;
	}

	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

// Remove last
Node* remove(Node* head)
{
	if (head == nullptr)
		return nullptr;

	if (head->next == nullptr)
		delete head;
		return nullptr;

	Node* second_last = head;
	while (second_last->next->next != nullptr)
	{
		second_last = second_last->next;
	}
	
	delete (second_last->next);

	second_last->next = nullptr;

	return head;
}

// Pairwise swap
void pairWiseSwap(Node* head)
{
	Node* curr = head;

	while (curr != nullptr && curr->next != nullptr)
	{
		swap(curr->data, curr->next->data);
		
		curr = curr->next->next;
	}

}

// Reverse a LinkedList in groups of given
// size using Stack
Node* reverse(Node* head, int k)
{
	if (!head || k == 1)
		return head;
	
	stack<Node*> st;
	Node* curr = head;
	Node* prev = nullptr;

	while (curr != nullptr)
	{
		int count = 0;
		while (curr != nullptr && count < k)
		{
			st.push(curr);
			curr = curr->next;
			count++;
		}
		while (!st.empty) {
			if (prev == nullptr)
			{
				prev= st.top();
				head = prev;
				st.pop();
			} else {
				prev->next = st.top();
				prev = prev->next;
				st.pop();
			}

		}
	}
	prev = nullptr;
 
	return head; 

}

// Reverse a linked list using a stack
Node* reverse(Node* head)
{
	stack<Node*> s;

	Node* temp = head;

	while (temp->next != NULL)
	{
		s.push(temp);
		temp = temp->next;
	}

	head = temp;

	while (!s.empty())
	{
		temp->next = s.top();
		s.pop();
		temp = temp->next;
	}
	
	temp->next = NULL;
	return head;

}

Node* mergeSorted(Node* head1, Node* head2)
{
	if (head1 == nullptr)
		return head2;	
	if (head2 == nullptr)
		return head1;

	if (head1->data <= head2->data)
	{
		head1->next = mergeSorted(head1->next, head2);
		return head1;
	} else {
		head2->next = mergeSorted(head1, head2->next);
		return head2;
	}


}
// Get Nth node from the end of a LinkedList
int nthNodeEnd(Node* head, int N)
{
	Node* ref_ptr = head;
	Node* main_ptr = head;

	for (int i = 0; i < N; i++)
	{
		ref_ptr = ref_ptr->next;

		if (ref_ptr == NULL)
			return -1;
	}

	while (ref_ptr->next != NULL)
	{
		ref_ptr =ref_ptr->next;
		main_ptr = main_ptr->next;
	}

	return main_ptr->data;

}
// Remove duplicates in a sorted linked list
Node* duplicate(Node* head)
{
	Node* curr = head;
	while(curr != NULL && curr->next != NULL)
	{
		if (curr->data == curr->next-data)
		{
			Node* next_next = curr->next->next;
			curr->next = next_next;
		} else {
			curr = curr->next;
		}

	}
}

// Check if linked list is Circular
// use fast and slow pointers
bool isCircular(Node* head)
{
	if (!head)
		return true;
	
	Node* fast = head->next;
	Node* slow = head;

	while (fast && fast->next)
	{
		if (fast == slow)
		{
			return true;
		} 
		fast = fast->next->next;
		slow = slow->next;
	}

	return false;
}
// Merge K Sorted Linked Lists using
// Min Heap
class Compare {
	public:
		bool operator()(const Node* a, const Node* b) {
			return a->data > b->data;
		}
}
Node* merge(vector<Node*>& arr)
{
	priority_queue<Node*, vector<Node*>, Compare> pq;
	
	for (auto n : arr)
			pq.push(n);

	Node* dummy = new Node(-1);
	Node* tail = dummy;

	while (!pq.empty())
	{
		Node* top = pq.top();
		pq.pop();

		tail->next = top;
		tail = top;

		if (top->next != nullptr) {
			pq.push(top->next);
		}

	}
	return dummy->next;
}











































