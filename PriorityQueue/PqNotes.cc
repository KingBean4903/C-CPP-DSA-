// Notes on the basics/implementation
// of a priority queue in C++ STL

#include <queue>
#include <functional>

// Syntax of a priority queue
// priority_queue<T, c, Cmp>
// T - type (int, string )
// c - Underlying container
// Cmp - comparator function
 priority_queue<int, vector<int>, greater<int>> pq;

// Create priority queue from a different container
vector<int> arr = { 5, 8, 7, 2, 3 };
priority_queue<int> p3(arr.begin(), arr.end());

// Basic operations
priority_queue<int> pq;

// NB elements are added to
// the queue based on their values
// i.e in a MaxHeap the higher the
// highest value occupies the top
// position

// Adding elements
pq.push(10);
pq.push(12);
pq.push(11);
pq.push(9);

// Accessing element
// top() - Since access for elements
// is from the top.
// pop() - remove an element from the top
//      internally the heap wil adjust 
while(!pq.empty()) {
	std::cout << pq.top() << " ";
	pq.pop();
}
// empty() - check if the pq is empty
// size() - returns the number of elements
//          in a priority queue
// swap() - used to swap elements of pqs
//          of the same type
priority_queue<int> pq1;
priority_queue<int> pq2;
pq1.swap(pq2);

