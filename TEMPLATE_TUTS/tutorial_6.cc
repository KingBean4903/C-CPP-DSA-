#include <iostream>

template<class T> class info 
{
	
	public:
		info(T a) {

			std::cout << "\n"
				<< "A = " << a
				<< " sizeof data in bytes: "
				<< sizeof(a);
		} 
};

int main()
{
	info<char> p('r');
	info<long> q(2.3343343423523);
	info<int> r(1);

	return 0;
}
