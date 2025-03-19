#include <iostream>

class Stack {
		int top, cap;
		int *a;

	public:
		Stack(int cap)
		{
			this->cap = cap;
			top = -1;

			a = new int[cap];
		}

		~ Stack() {
				delete[] a;
			}

		bool push(int x) {
			if (top >= cap - 1) {
					std::cout << "Stack overflow \n";
					return false;
			} else {
					a[++top] = x;
					return true;
			}
		}
		

		int pop() {
			
			if (top < 0) {
						std::cout <<"Stack underflow \n";
						return 0;
			} else {
					  return a[top--];
			}
		}

		int peek() {
			
			if (top < 0) {
					std::cout << "Stack underflow \n";
					return 0;
			} else {
					
				return a[top];
			}
		}

		bool isEmpty()
		{
				return top < 0;
		}
};

	
int main() {
	
	Stack s(5);

	s.push(1);
	s.push(9);
	s.push(8);

	std::cout << "Top of stack " << s.peek() << std::endl;

	while (!s.isEmpty()) {
		std::cout << s.peek() << " ";
	  s.pop();
	}

	return 0;
}
