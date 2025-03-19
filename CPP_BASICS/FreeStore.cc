// Free store
/*
	A named object has its lifetime
	determined by its scope.

	It is useful to create an object
	that exists independently of the
	scope it was created.

	i.e It is common to create 
	objects that can be used after
	returning fron the function in
	which they were created.

	The operator new creates such
	objects and the operator delete
	is used to destroy them.
 
    Objects allocated by new are
	said to be on the free store/heap/
	dynamic memory.

	new returns a pointer
*/

// To be sure to get default init
// we use {}

auto pc = new complex<double>{}; // init to {0,0}
auto pi = new int{}; // init to 0

/* An object created by new exits
   until it is explicitly destroyed by
   delete
   
   Then, the space it occupied is
   reused by new.

   The delete operator may be applied
   only to a pointer returned by new
   or to the nullptr.
*/

// Lists
/*
	List can appear in 2 forms
	1. Qualified by a type T{..} -
		create an object of type
		T initialized by T{...}

	2. Unqualified {..} for which the
	   type must be determined from 
	   the context of the use.

*/

struct S{ int a, b; };
struct SS {double a, b};

void f(S); // takes S
void g(S);
void g(SS);

void h() {

	f({1,2}); // Ok call f(S{1, 2})
	g({1, 2}); // error: ambiguos
	g(S{1,2}); // Ok: call g(S)
	g(SS{1, 2}); // Ok: call g(SS)

}

/* Implementation Model

   1. {} used as construtor arguments
   2. {} init elements of an aggregate
   3. {} construct an initializer_list object
   	    each list element is used to initialize
		an element of the underlying array of 
		the initializer_list.
*/

/* ------------ Qualified Lists ---------------- */
// The basic idea is that you can
// initialize a variable x using the
// notation
T x {v};

/* NB : A plain T{v} makes a temporary object 
        in the local scope
*/

struct S { int a, b; };

void v()
{
	S v {7, 8}; // direct initialization
	v = S{7, 8}; // assign using qualified list
	S* p = new S{7,8}; // construct on the free store using qualifed list

}

template<class T>
T square(T x)
{
	return x*x;
}

void f(int i)
{
	double d = square(double{i});
	complex<double> z  = square(complex<double>{i});
}

/* Unqualified Lists
   It can only be used as
   an expression only as
	
  1. A fuction argument
  2. A return value
  3. A subscript
  4. The right hand operant of an
  	 assignment operator( =, +=, *=)
*/

int f(double d, Matrix& m)
{
	int v {7}; // initializer (direct initialization)
	int v2 = {7}; // init (copy initialization)
	int v3 = m[{2, 3}]; // assume m takes value pairs

	v = {8}; // right-hand operand of assignment
	v += {88}; // right-hand operand of assignment
	f({10.0}); // function argument
	return {11}; // return value
}


// The standard library type initializer_list<T>
// is used to handle variable length {}-listsl

// Itsmost obvious use is to allow initailiser
// lists for user-defined containers,but can also
// be used directly;
int high_value(initailizer_list<int> val)
{
	int high = numeric_traits<int>lowest();
	if (val.size() == 0) return high;

	for (auto x: val)
		if (x>high) high = x;

		return high;
}

int v1 = high_value({1, 2, 3, 4, 5, 6, 7});
int v2 = high_value({ -1, 2, v1, 4, -9, 20, v1});

// The type of a {} list can only be
// deduced if all elements aer of the same
// type
auto x0 = {}; // error (no element-type}
auto x1 = {1}; // initializer_list<int>
auto x2 = {1, 2}; // initializer_list<int>
auto x3 = {1, 2, 3}; // initializer_list<int>
auto x4 = {1, 2.0}; // error: homogenous list 

// Unfortunately we do not deduce the
// type of an unqualified list for a plain
// template argument

template<typename T>
void f(T);

f({}); // error: type initializer unknown

// Similarly, we do not deduce the 
// element type of a container 
// represented as a template.

template<class T>
void f2(const vector<T>&);

f2({1, 2, 3}); // error: cannot deduce T
f2(vector<int>{1, 2, 3});
f2(vector<string>{"KOna","Sydney"});






















