// Explicit Type Conversion

/*
	1. Construction usig {}, providing
		type-safe construction of new 
		values.
	2. Named conversions
		i. const_cast: for getting write access
				to something declared const;
	   ii. static_cast: for implicit conversion
	  iii. reinterpret_cast: changing the meaning
	  			of bit patterns.
	   iv. dynamic_cast: dynamically checked class
	   		hierachy navigation.

	3. C-style casts
	4. Functional notation
*/

// Construction
// The construction of a value of type T from
// a value e can be expressed as T{e}
auto d1= double{2}; // d1 == 2.0
auto d2 {double{2}/4}; // d1 == 0.5
































