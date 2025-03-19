#include <iostream>

template<typename A, typename B>
void func(A var, B let)
{
		std::cout << "General version" << std::endl;
}

template<typename A, typename B>
void func(A* var, B let)
{
	std::cout << "Specialized version " << std::endl;
}

int main()
{
	
	int var = 8;
	int *ptr = &var;

	func(var, "foo");
	func(ptr, 39);

	return 0;

}
