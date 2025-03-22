/* ------------ List Arguments ----------------
	A {} delimited list can b used an an argument
	to a parameter of

	1. Type std::initializer<T>, where the values
		of the list can be implicitly converted to
		T.
	2. A type that can b initialized with values
	   provided in the list.
	3. A reference to an array of T, where the
	   values can be implicitly converted to
	   T.
*/

template<class T>
void f1(initiailizer_list<T>);

struct S {
 int a;
 string s;
};
void f2(S);

template<class T, int N>
void f3(T(&r)[N]);

void f4(int);

void g()
{
	f1({1, 2,3, 4}); // T is int and the initializer list has size() 4
	f2({1, "MKS"}); // f2(S{1, "MKS"})
	f3({1,2,3,4}); // T is int and N is 4
	f4({1});      // f4(int{1})
}

// If there is ambiguity, an initializer_list
// parameter takes priority.

/* ------------ UNSPECIFIED NO OF ARGUMENTS ------------
	For some functions it is not possible
	to specify the number of arguments expected
	in a call.
	
	3 choices to implement above.

	1. Use a variadic template
	2. Use an initializer_list as argument type
	3. Terminate argument list with an ellipsis (...)

*/

int printf(const char* ...);

// This specifies that a call of the STL printf()
// must have at least one argument, a C-style string
// but may or may not have others.
printf("Hello buddy");
printf("My name is %s %s\n", first_name, second_name);
printf("%d + %d = %d\n", 2,3,5);

// ----------- DEFAULT ARGUMENTS ---------------
complex(double r={}, double i={}) :re{r}, im{i}, {} 

// A default argument is checked at time of the
// function declaration and evaluated at time
// of function call

class X {
	public:
		static int def_arg;
		void f(int =def_arg);
};

int X::def_arg = 7;

void g(X&a)
{
	a.f(); // maybe 7
	a.def_arg = 9;
	a.f(); // f(9)
}

// Default arguments may be provided
// for trailing arguments only
int f(int, int =0, char* =nullptr); //Ok

//------------- Pointer to function
/*
	There are only two things one can
	do to a function: call it and
	take its address.

	The pointer obtained by taking the
	addressof a function can then be
	used to call the function.

*/

void error(string s) {/* .. */ }
void (*efct)(string); // pointer to function taking a string
					  // argument and returning nothing

void f()
{
	efct = &error; // efct points to error
	efct("error"); // call error through efct
}

// -------------- Function return types
/*
	The essential use for a suffix return
	type comes in function template declarations
	in which the return type depends on the 
	arguments.
*/
template<class T, class U>
auto product(const vector<T>& x, const vector<U>& y) -> decltype(x*y);

/*
	Each time a function is called a new copy of its
	arguments and local variables is
	created.
	The store is reused after the function
	returns, so a pointer to a local non-static
	varialbe should never be returned.
*/

int* fp()
{
	int local = 1;

	return &local; // bad
}

// ------------ constexpr Functions -----------
/*
	By specifying a function constexpr, we indicate
	that we want it to be usable in constant
	expressions if given constant expression
	arguments.
*/

constexpr int fac(int n)
{
	return (n>1) ? n*fac(n-1) : 1;
}

constexpr int f9 = fac(9);

/* A constexpr function must
   consist of a single return statement.

   No loops and no local variables allowed.

   May not have side effects.

   constexpr function is a pure function.
   
   constexpr function can refer to nonlocal
   objects as long as it does not write to
   them.

*/
constexpr int ftbl[] {1, 2, 3, 4, 5,90};

















