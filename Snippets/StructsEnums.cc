/* User Defined types in  C++
   Primitive types of UDTs
	
  1. Struct - A sequence of elements of
  			  arbitrary types.
  2. Union  - Struct that holds the value
  			  of just one of its elements
			  at any one time.
  3. enum   - Is a type with a set of named
  			  constants (enumerators)
  4. enum clas - scoped enumeration, is an 
  			enum where the enumerators
			are within the scope of the
			enumeration and no implicit type
			conversions to other types
			is provided.
*/


// Structures - an aggregate of elements
//       of elements of arbitrary types
struct Address {
   const char* name; // Muriuki
   int age; // 23
   const char* street; // "Dubois" pointer to const char
   const char* town; // "Nairobi" pointer to const char
   char country[2]; // 'k' 'e' char array
   const char* phone; // "07123456789100"
};

// Accessing individual members
// with the dot operator
void f()
{
	Address mw;
	mw.name = "Muriuki";
	mw.age  = 25;
}

// Initialization using {}
Address mw = {
	"Mwangi",
	44, "Dubois",
	"Nairobi", {'k', 'e'},
	"078912345678"
};

// Access through pointers using ->
void print_addr(Address* p)
{
	std::cout << p->name << '\n'
		<< p->number << '' << p->street << '\n'
		<< p->town << '\n'
		<< p->state[0] << p->state[1] << ''
		<< p->zip << '\n';
}

/* Structures and Classes
   A struct is simply a class where 
   the members are public by default.

   A struct can have member functions and
   constructors.
*/

struct Points {
	vector<Point> elem;
	Points(Point p0) { elem.push_back(pO); }
	Points(Point p0, Point p1) {
		elem.push_back(p0);
		elem.push_back(p1);
	} 
	// ..
};

Points x0;  // error: no default constructor
Points x1 {{ 100, 200}}; // one point
Points x1 { {100, 200}, {300, 400} }; // two points

// You do not need to define a constructor
// simply to initialize members in order
struct Point {
	int x, y
};

Point p0; // uninitialized in local scope
Point p1 {}; // default construction: {{}, {}}; that is {0, 0}
Point p2 {1}; // second member is default constructed {1,{}}; {1, 0}
Point p3 {1, 2}; // {1,2}

// Structures and Arrays
struct Point {
	int x, y
};

Point points[3] { {1,3}, {3,4}, {5,6} };
int x2 = points[2].x;

struct Array {
	Point elem[3];
};

Array points2 {{1,2},{3,4},{5.6}};
int y2 = points2.elem[2].y;

// The standard lib provides std::array
// as a more complete and elegant dev of the
// idea of a fixed-size array as a struct

template<typename T, size_t N>
struct Array {
	T elem[N];
	
	// Iterator begin() return pointer to first element
	T* begin() noexcept {return elem; }
	// Const iterator cbegin() return pointer to const
	// to first element
	const T* begin() const noexcept { return elem; }
	
	T* end() noexcept { return elem+N; }
	const T* end const except { return elem+N; }

	constexpr size_t size() noexcept;

	// Indexing or access operator
	T& operator[](size_t n) { return elem[n]; }
	const T& operator[](size_t n) const {return elem[n]; }

	T* data() noexcept { return elem; }
	const T* data() const noexcept { return elem; }
	// ..
};

using Array = std::array<Point, 3>;
Array points { {1,2}, {3,4}, {5,6} };
int x2 = points[2].x;
int y3 = points[]2].y;

template<typename T, int N>
void print(array<T,N>& a)
{
	for (int i = 0; i != a.size(); ++i)
		std::cout << a[i] << '\n';
}

// is_pod to check if T is a POD
// is defined in <type_traits>
template<typename T>
void mycopy(T* to, const T* from, int count)
{
	if (std::is_pod<T>::value)
		std::memcpy(to,from,count*sizeof(T));
	else
		for (int i = 0; i!=count; ++i)
			to[i]=from[i];
}

// Enumerations
// Is a type that can hold a set 
// of integer values specified

/* There are 2 kinds of enumerations
  
   1. enum class - their values do not
   			implicitly convert to other
			types
   2. Plain enum - enumerator names are
   		in same scope as the enum and
		their values implicitly convert
		to integers
*/

enum class Color { red, green, blue };

Color c7 = 7;          // error: no int->Color conversion
int c3 = blue;         // error; blue not in scope
int c5 = Color::blue;  // error: no Color->int conversion
Color c2 = Color::red; // Ok


















