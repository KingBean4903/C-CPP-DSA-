#include <bits/stdc++.h>
using namespace std;

class Node 
{
	public:
		int data;
		Node *next;
		
		Node(int x) {
			data = x;
			next = nullptr;
		}
};

void printArray(Node *head)
{
	Node *p = head;
	
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}

	cout << endl;
}

Node *getIntersection(Node *head1, Node *head2)
{
	Node *p = head1;
	Node *result = nullptr;
	unordered_set<int> intsct;

	while (p != nullptr)
	{
			intsct.insert(p->data);
			p = p->next;
	}

	p = head2;

	while (p != nullptr) 
	{
		if (intsct.find(p->data) != intsct.end()) {
			Node *new_node = new Node(p->data);
			new_node->next = result;
			result = new_node;
		}
		p = p->next;
	}

	return result;
}

Node *getUnion(Node *head1, Node *head2)
{

	Node *p = nullptr;
	unordered_set<int> unique_set;
	
	p = head1;
	while (p != nullptr) {
		unique_set.insert(p->data);
		p = p->next;
	}

	p = head2;
	while (p != nullptr) {
		unique_set.insert(p->data);
		p = p->next;
	}


	Node *result = nullptr;
	Node *tail = nullptr;

	for (int i : unique_set)
	{
			Node *new_node = new Node(i);
			if (result == nullptr) {
				result = new_node;
				tail = new_node;
			} else {
				tail->next = new_node;
				tail = tail->next;
			}
	}
	return result;
}


void printUnionIntersection(Node *head1, Node *head2) 
{
	
	Node *intersectionList = getIntersection(head1, head2);
	Node *unionList = getUnion(head1, head2);

	cout << "Intersectin List" << endl;
	printArray(intersectionList);

	cout << "Union List" << endl;
	printArray(unionList);
	
}


int main() {

	Node *head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(3);
	head1->next->next->next->next = new Node(4);
	head1->next->next->next->next->next = new Node(5);

	Node *head2 = new Node(1);
	head2->next = new Node(5);
	head2->next->next = new Node(6);

	printUnionIntersection(head1, head2);

	return 0;
}




