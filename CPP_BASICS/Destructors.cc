/* Destructor: - function to be invoked
       when an object is destroyed.

   Destructors are called implicitly
   when an automatic variable goes
   out of scope, an object on the free
   store is deleted.

	Destructors cleanup and release
	resources.
*/

class Vector {

public:
	Vector(int s) :elem{new double[s]}, sz{s} {};
	~Vector() { delete[] elem; }
	// ..
private:
	double* elem;
	int sz;
};

// Sample use case
Vector* f(int s)
{
	Vector v1(s); 
		
	return new Vector(s+s);
} // v1 is destroyed upon exit from f()

void g(int ss)
{
	Vector* p = f(ss);
	// ...
	delete p; // 
}

// Base and Member Destructors
struct S1 {
	string s;
}

S1 x;  // Ok: x.s init to ""

// 
struct X { X(int); };

struct S2{
	X x;
};

S2 x1; // error
S2 x2 {1}; // Ok x2.x is init to 1

/* Calling Constructors and Destructors

    A constuctor is called implicitly
	upon exit from a scope or by delete.
	
	Rare case for calling a destructor and
	constructor
	std::vector
*/

void C::push_back(const X& a)
{
	// ..
	new(p) X{a}; // placement new
}

void C::pop_back()
{
	p->~X(); // Destroy the X in address p
}

/*
   If declare for a class X, a destructor
   will be implicitly invoked whenever an 
   X goes out of scope.
	
   This implies we can prevent destruction
   of an X by declaring its destructor
   =delete or private.
*/
class Nonlocal {

public:
	// ..
	void destroy() { this->~Nonlocal(); }// explicit destruction
private:
	//..
	~Nonlocal(); // don't destroy implicitly
};

void user()
{
	Nonlocal x; // error cannot destroy a Nonlocal
	X* p = new Nonlocal; // Ok
	// ..
	delete p; // error: cannot destroy a Nonlocal
	p.destroy(); // Ok
}



















