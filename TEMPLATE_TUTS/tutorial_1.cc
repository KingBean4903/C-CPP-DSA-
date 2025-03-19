#include <iostream>

template<typename T> T myMax(T a, T b) 
{
	return (a>b) ? a : b;
}

int main() 
{
	
	std::cout << myMax<int>(3, 5) << std::endl;
	std::cout << myMax<float>(8.09, 7.6) << std::endl;

	return 0;

}
