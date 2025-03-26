// Stack implementation using array

#include <iostream>
class Stack {
	int cap;
	int top;
	int* a;
	public:
		Stack(int cap) {
			this->cap = cap;
			top = -1;
			a = new int[cap];
		}

		bool push(int x)
		{
			if (top >= cap)
			std::cout << "Stack Overflow" << "" ;
				return false;
			a[top++] = x;
			return true;
		}

		bool pop() 
		{
			if (top < 0)
				std::cout << "Stack underflow" << " ";
				return false;
		   return	a[top--];
		}


		int top() { 
			if (top < 0)
			{
				return 0;
			}
			return a[top];
		}	

		bool isEmpty()
		{
			return top < 0;
		}
	

};




















