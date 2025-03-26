// Member initialization and Assignmet

class X {

	const int i;
	Club cl;
	Club& rc;
	//..
	X(int ii, const string& n, Date d, Club& c): i{ii},
		cl{n,d}, rc{c} {}
};

// Delegating constructors
class X {
	
	int a;
	validata(int x) { // ..  }
public:
	X(int x) { validate(x); }
	X() { validate(42); }
	X(string s) { int x= to<int>(s); validate(x); }
	// ..
};

// implement delegating in above

class X {	
	int a;
public:
	X(int x) { validate(x); }
	X(): X{42} {}
	X(string s): X{to<int>(s) }{ }
	
};

/*
	You cannot both delegate and 
	explicitly initialize a member.

*/

// Static Member Init
// A static class member is statically 
// allocated rather than part of each
// object of the class.

// Generally, the static member declaration
// acts as a declaration for a definition
// outside the class.

class Node {
	static int node_count; // declaration
}

int Node::node_count = 0; // definition

/* It is possible to initialize a static
   member in the class declaration.

   The static member must be a const of a
   an integral or enumeration type, or a
   constexpr of a literal type and the
   initializer must be a constant-expression.

*/

class Curious {
	public:
		static const int c1 = 7; // OK
		static int c2 = 11; // error not const
		const int c3 = 22; // ok but not static
		static const int c4 = sqrt(4); // error: inclass init not constant
		static const float c5 = 7.0; // error not integral (use constexpr)
	//..
};
// The main use of member constants
// is to provide symbolic names for constants
// needed elsewhere in the class declaration.

template<class T, int N>
class Fixed {
public:
	static constexpr int max  = n;
	// ..
private:
	T a[max];
}
























