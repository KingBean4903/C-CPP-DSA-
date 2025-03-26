
// Initialization without constructors

// We cannot define a constructor for
// a built-in type, yet we can initialize
// it with a vlaue of suitable type

int a {1};
char* p {nullptr};

struct Work { 
	string author;
	string name;
	int year;
}

// Memberwise initailization
Work w1 {
	"Kiriamiti",
	"My life in crime",
	404,
}; 

Work w2 { w1  }; // copy initialization

Work none {}; // default initialization

Work alpa; // no constructor requiring args
		   // {"", "", 0} applies for statically
		   // allocated

		   
void f()
{
	Work beta; // {"", "", unknown}
}
// In above for local and free store objects
// the default initialization is done
// for members of class type and 
// members of built-int type are left
// uninitialized.

struct Buf {
	int count;
	char buf[16*1024];
};

Buf buf0; // Statically allocated, so initialized 	
	     // by default

void f()
{
	Buf buf1; // leave elements uninitialized
	Buf buf2; // zero out elements

	int* p1 = new int; // Unintialized;
	int* p2 = new int{}; // *p2 == 0
	int* p3 = new int{7}; // *p3 = 7
	// ..
}



























