// Welcome to our tutorial on
// C++ lambdas

// Motivation: Back to the basics
// Why the need for lambdas ?
// the need of having local 
// functional expressions.

// Lambdas in C++03
#include <iostream>
#include <algorithm>
#include <vector>

// functor 
// because it overrides ()
struct PrintFunctor {
	void operator() (int x) const {
		std::cout << x << std::endl;
	}
};

int main(){
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	std::for_each(v.begin(), v.end(), PrintFunctor());
	std::for_each(v.begin(), v.end, [](int a){ std::cout<< a << std::endl;   }
}

// The type of a lambda
// Since the compiler generates some
// unique name for each lambda there is 
// no way to know the type upfront

// That is why you have to auto (or decltype) to
// deduce th type
auto coolLambda = [](int a) -> double { return 2.0 * a;  }

// By default the operator() is const.
// You can change by specifying mutable after
// the parameter declaration claus.
auto coolLambda = [](int a) mutable { std::cout <<a ;}

// Captures [] : capture clause
// By capturing a variable, you create
// a member copy of that variable 
// in the closure type. Then inside
// the lambda body you can access it.
/*
	[&] - capture by reference, all automatic
		 storage duration variable declared
		 in the reaching scope
	[=] - capture by value, a value is
		  copied.
	[x, &y] - capture x by value and y by ref
*/

auto calc = [&x, &y]() mutable { ++x; ++y;  }

// Capturing globals [=]
// only variables with automatic storage
// duration are captured

// Preserving const
int const y = 10;
auto bar = [x] () mutable {
	std::cout << std::is_const<decltype(x)>::value << std::endl;
	x = 11;
};
bar();

// Return type
// in C++11 you could skip the trailing
// return type of the lambda and then
// the compiler would deduce the types 
// for you.

// Immediately Invoked Function Expression
[&]() { ++x; ++y; }(); // <- call ()

// Conversion to function pointer
// you can convert a lambda without
// captures to a function pointer

// Captures with an  initializer
/*
	We can create a new member variable
	of the closure type and then use
	it inside the lambda.
*/
int main() {
	int x = 10;
	int y = 11;
	auto foo = [z = x+y] () {std::cout << z << '\n'; }
	foo();
}
// This can solve a few problems,
// for example movable only types

// Move
// Now we can move an object into
// a member of the closure type
#include <memory>

int main() {
	
	std::unique_ptr<int> p(new int{10});
	auto foo = [ptr=std::move(p)]{};
	auto baz = [p=std::move(p)]{};

}
// Optimisation
/*
	Rather than computing some value
	every time we invoke a lambda
	we can compute it once in the initialiser
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>
#include <string>

int main()
{
	std::vector<std::string> vs;
	std::find_if(vs.begin(), vs.end(),
		[p="foo"s + "bar"s](std::string const& s)
		{ return s == p; });


}

// Capturing a member variable
struct Baz
{
	auto foo()
	{
		return [s=s] {std::cout << s << std::endl; };
	}
	std::string s;
}

int main() 
{
	auto f1 = Baz{"Hello"}.foo();
	auto f2 = Baz{"Buddy"}.foo();
	f1();
	f2();

}
// Generic Lambda
auto foo = [](auto x) { std::cout << x << '\n'; };
foo(10);
foo(3.12458);
foo("Hello");
// this is equivalent to
struct {
	template<typename T>
	void operator() (T x) const {
		std::cout << x << '\n';
	}
} someInstance;



















