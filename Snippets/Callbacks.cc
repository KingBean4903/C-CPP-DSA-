// Using std::function
#include <iostream>
#include <functional>

int f(int a, int b)
{
	return (a * b);
}

int main() {
	
	std::function<int(int, int)> calc = f;

	std::cout << "Sum: " << calc(8, 3) << std::endl;


	return 0;


}



















