// Initialization using constructors

// A constructor is used to establish
// an invariant for its class to acquire
// resources necessary to do that.

struct X {
	X(int);
};

X x0; // error no initializer
X x1 {}; // error: empty initailizer
X x2 {2}; // Ok
X x3 {"two"}; // error: wrong type
X x4 {1,2}; // error: wrong no of initializers
X x5 {x4}; // Ok

/* NB: the default constructor disappears when
    you define a constructor requiring args
	
	However the copy constructor does not disapper
	; the assumption is that an object can be copied
	(once properly constructed).
*/

struct Y : X {
	X m {0};
	Y(int a) : X{a}, m{a} {};
	Y() : X{0} {};
};

X g {1}; // initialize global variable

void f(int a)
{
	X def {}; // error no default constructor on X
	Y de2 {}; // Ok : use default constructor

	X* p {nullptr}; 
	X var {2}; // init local variable
	p = new X{4}; // init object on free store
	X a[] {1,2,3}; // init array elements
	vector<X> v {1, 2, 3, 4}; // init vector elements

}

// Default Constructors
// A constructor that cannot be invoked
// without an argument is called a default
// constructor.
class Vector {
public:
	Vector(); // default constructor no elements
	// ..
}
Vector v1;  // Ok
Vector v2 {}; //OK

// A default argument can make a constructor
// that takes arguments into a default 
// constructor
class String {
public:
	String(const char* p = ""); 
	//..
}
String s1; // Ok
String s2 {}; // Ok

/*
	The built-in types are considered to
	have default and copy constructors.

	However, for a built-in type the
	default constructor is not invoked
	for uninitialized non-static variables.

	The default for a built-in type is 0 
	for integers, 0.0 floating-point types
	and nullptr for pointers.
	
*/

void f()
{
	int a0; // uninitialized
	int a1(); // function declaration

	int a{}; // a becomes 0
	double d {}; // d becomes 0.0
	char* p {}; // p becomes nullptr

	int* p1 = new int; // uninitialized int
	int* p2 = new int{}; // the int is initialized to 0

}

// Constructor for built-in types are
// most often used for template arguments

template<class T>
strut Handle {
	T* p;
	Handle(T* pp = new T{}): p{pp} {}
	// ..
}

Handle<int> px; // will generate int{}

/* 
   References and const must be initialized.
   
   Therefore, a class containing such members
   cannot be default constructed unless
   the programmer supplies in-class member initializers
   or defines a default constructor that initailizes
   them.
*/

/* 
  An array, an STL vector and similar containes
  can be declared to allocate a number of
  default-initialized elements.
  in such cases a default constructor is 
  obviously required for a class
  used as the element type of a vector or array

*/

struct S1 {S1(); }; // has default
struct S2 {S2(string); }; // no default constructor

S1 a1[10]; // Ok: 10 default elements
S2 a2[10]; // error: cannot init elements;
S2 a3[] { "alpah", "beta"}; // Ok: two elements

vector<S1> v1(10); // Ok: 10 default elements
vector<S2> v2(10); // error
vector<S2> v3 {"alpha", "beta" }; // Ok

vector<S2> v2(10,""); // Ok: 10 elements
vector<S2> v4; // Ok: no elements









































