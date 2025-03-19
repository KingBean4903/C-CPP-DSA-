#include <iostream>

template<class T, class U> class A 
{
		T x;
		U y;

	public:
		A() {
			std::cout << "Constructor ended" << std::endl;
		}
};

int main()
{
	A<char, double> a;
	A<int, double> b;
	return 0;
}
