#include <iostream>

template <typename A, typename B> class Geek 
{
	public:
		void print()
		{
			std::cout << "Primary template" << std::endl;
		}
};

template <typename T> class Geek<T, int> 
{
	public:
		void print() {
			std::cout << "Partial specialization" << std::endl;
		}
};

int main()
{
	Geek<bool, double> obj1;
	Geek<bool, int> obj2;
	obj1.print();
	obj2.print();
}
