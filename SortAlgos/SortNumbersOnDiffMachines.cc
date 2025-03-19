struct ListNode {
	int data;
	ListNode* next;
	ListNode(int val) data(val), next(nullptr) {}
};

struct CompareNode {
	
	bool operator() (const ListNode* a, const ListNode* b) {
		return a->data > b->data;
	}
};

ListNode* mergeLists(vector<ListNode*> lists) 
{
	priority_queue<ListNode*, std::vectory<ListNode*>, CompareNode> 
	minHeap;

	for (auto list: lists)
		if (list)
			minHeap.push(list);
	
	ListNode dummy(0), *tail = &dummy;

	while (!minHeap.empty()) 
	{
		ListNode* node = minHeap.top();
		minHeap.pop();
		tail->next = node;
		tail = tail->next;

		if (node->next) minHeap.push(node->next);
	}

	return dummy.next;

}




ListNode* externalSort(vector<ListNode*>& lists) {
	
	ListNode* sortedList = mergeLists(lists);
	return sortedList;

}
