// Initializer list constructor

// A constructor that takes in 
// a single argument of type std::initializer_list
// is called an initializer-list constructor.

// An initializer list constructor is used
// to construct objects using {}.

vector<double> v = {1, 2, 3.45, 112.22};

// mechanism for accepting {}-list is a
// function /constructor taking an arg
// of type std::initializer_list<T>

void f(std::initializer_list<int>);

f({1, 2});
f({});

// The initializer list can be arbitrary
// length or homogenous.
// That is all elements must be of template
// argumetn type T.

void f(initializer_list<int> args)
{
	for (auto x : args)
		cout << x << '\n';
}

// A container might implement an intializer_list
// constructor like this.

template<class E>
class Vector {
	
	public:
		Vector(std::initilizer_list<E> s);
		// ..
	private:
		int sz;
		E* elem;
};

template<class E>
Vector::Vector(std::initializer_list<E> s)
	:sz {s.size()}
	{
		reserve(sz);
		uninitialized_copy(s.begin(), s.end(), elem);
	}




























