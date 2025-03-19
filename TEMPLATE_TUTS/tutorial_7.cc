#include <iostream>

template<class T> void func(T a)
{
		std::cout << "General template" << a << std::endl;
}

template<> void func(int a)
{

		std::cout << "Specialized template" << a << std::endl;
}

int main() 
{
	
	func<double>(3.55);
	func<int>(2);
	func<char>('h');

	return 0;

}
