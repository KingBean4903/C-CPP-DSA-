#include <limits>
#include <iostream>
#include <typeinfo>
#include <memory>

int main()
{
	
	auto ac = alignof('c');

	std::cout << decltype(ac)  ;

	std::cout << "Size of long " << sizeof(1L) << '\n';
	std::cout << "Size of long long " << sizeof(1LL) << '\n';

	std::cout << "largest float== " << std::numeric_limits<float>::max() << '\n';
	std::cout << "char is signed == " << std::numeric_limits<char>::is_signed << '\n';

	return 0;

}
