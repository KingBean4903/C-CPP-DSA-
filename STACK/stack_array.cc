#include <stdio.h>

class Stack {
	int top;

	public:
		int a[MAX];

		Stack() { top = -1;  }
		bool isEmpty();
		bool push(x);
		int peek();
		void pop()
};


bool Stack::push(int x) {
		
	if (top < 0) {
		cout << "Stack is empty"
		return 0; 
	} else {
		a[++top] = x;
		cout << x << "pushed into stack\n";
		return true;
	}
}

bool Stack::pop() {
	
	if (top < -1) {
		cout << "Stack is empty";
		return 0;
	} else  {
		int x = a[top--];
		return x;
	}
}

int Stack::peek() {
	
	if (top < 0) {
			cout << "Stack is empty";
			return 0
	} else {
			int x = a[top];
			return x;
	}
}

bool isEmpty() 
{
	return (top < 0);
}

int main()
{
	
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);

	cout << s.pop() << "Popped from stack\n";

	cout << "Top element is : " << s.peek() << endl;

	cout << "Elements present in stack: ";

	while(!s.isEmpty()) 
	{
			cout << s.peek() << "";
			s.pop();
	}
	
	return 0;

}
