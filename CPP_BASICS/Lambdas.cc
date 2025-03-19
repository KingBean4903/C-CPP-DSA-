
// Is a simplified notation for defining
// and using an anonymous function object

// Instead of defining a named class with
// an operator(), later making an object
// of that class and later invoking it
// we can use a shorthand.

// Lambdas and this
void print_modulo(const vector<int>& v, ostream& os, int m)
{

	std::for_each(begin(v),
				  end(v),
				  [&os,m](int x) {
					if (x%m == 0) os << x << '\n';
				  });

}

class Modulo_print{
	ostream& os;
	int m;
	public:
		Modulo_print(ostream& s, int mm): os(s), m(mm) {} //capture
		void operator()(int x) const 
			{ if (x%m == 0) os << x << '\n'; }
};

// 
template<class C>
void print_modulo(const C& v, ostream& os, int m)
{
	breadth_first(begin(v),end(v),
				[&os,m](int x) {if (x%m == 0) os << x << '\n'; }
		);
}
// Lambda and this
class Request {
	std::function<map<string, string>(const map<string, string>&)> oper; // Operation
	map<string, string> values; //arguments
	map<string, string> results; // targets
	public:
		Request(const string& s);

		void execute()
		{
			[this]() { results=oper(values); }
		}
};

// mutable Lambdas
void algo(vector<int>& v)
{
	int count = v.size();
	std::generate(v.begin(), v.end(),
		[count]()mutable{ return --count; });
}

// A lambda that captures nothing can be
// assigned to a pointer to function of an
// appropriate type
double (*p1)(double) = [](double a){ return sqrt(a); };












