// const     : Do not modify in this scope

/* constexpr : Evaluate at compile time
  	Is an expression that a compiler can
	evaluate.
	
	It cannot use value that are not known
	at compile time and it cannot have side
	effects.

	A constexpr must start out with an integral
	value, a floating point value, or an
	enumerator

	constexpr expresses the need for compile
	time evaluation.

	If the initializer for a constexpr
	can't be evaluated at compile time, the compiler
	will give an error.
*/

int x1 = 7;
constexpr int x2 = 7;

constexpr int x3 = x1; // error initializer is not a constant
                      // expression
constexpr int x4 = x2; // Ok

void f() {

	constexpr int y3 = x1; // error: Initializer is not a
						   // constant expression
	constexpr int y4 = x2; // Ok
}

/* NB: In a large program, determining the 
	 values of variables at compile time
	 is typically either very difficult or
	 impossible
	
	We can use an integer, floating point and
	enumeration values.

	We can use operators that don't modify
	state ( +, ? and [], but not = or ++)
*/

// Computing an integer square root value
// at compile time

constexpr int isqrt_helper(int sq, int d, int a)
{
	return sq <= a? isqrt_helper(sq+d+d+2,a) : d;
}

constexpr int isqrt(int x) {
	return isqrt_helper(1,3.x)/2 - 1;
}

constexpr int s1 = isqrt(9);
constexpr int s2 = isqrt(1235);

/*
	A const initialized with a constant
	expression can be used in a constant
	expression.

	A const differs from a constexpr
	in that it can be initialized by 
	something that is not a constant 
	expression.
*/

const int x = 7;
const string s = "absd";
const int y = sqrt(x);
:
constexpr int xx = x; // OK
constexpr string ss = s; // error s is not a constant expression
constexpr int yy = y; // error: sqrt is not a constant expression

// Literal Types
// A sufficiently simple user-defined type
// can be used in a constant expression
// Example:

struct Point {
	int x, y, z;
	constexpr Point up(int d) {return { x,y,z+d; }
	constexpr Point move(int dx, int dy) { return { x+dx, y+dy; }
	// ..
}

/*
	A class with a constexpr constructor is called 
	a literal type.

	To be simple enough to be a constexpr a
	constructor must have an empty body and
	all members must be initialized by 
	potentially contant expressions.

*/
constexpr Point origin {0 ,0};
constexpr int z = origin.x;

constexpr Point a[] = {
	origin, Point{1 ,1}, Point {2, 2}, origin.move(3, 3)
};

constexpr int x = a[1].x;  // x becomes 1
constexpr Point xy{0, sqrt(2)}; // error

// NB: we can have constexpr arrays
// We can define constexpr functions 
// to take literal types as args

constexpr int square(int x) {
	return x*x;
}

constexpr int radial_distance(Point p)
{
	return isqrt(square(p.x) + square(p.y) + square(p.z));
}

constexpr Point p1 {10, 20, 30}; // default constructor is constexpr
constexpr p2 {p1.up(20)}; // Point::up() is constexpr
constexpr int dist = radial_distance(p2);

// For a member function constexpr implies const
constexpr Point move(int dx, int dy) const { return {x+dy, y+dy };

// Reference Arguments
// constexpr is all about values.

/* Literal types allow for type-rich 
	compile-time programming 

*/
















