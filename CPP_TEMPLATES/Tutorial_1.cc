/*
 Templates provide direct support for generic
 programming in the form of programming using
 types as params.

 The C++ template mechanism allows a type 
 or a value to be a parameter in the definition
 of a class, function or type alias.

 The template depends only on the properties
 that it actually uses from its param types
 and does not require types used as args be 
 related.

 STL abstractions are represented as template.

 A template is a specification of how to 
 generate something.

 Members of a template class are themselves
 templates parametized by parameters
 of their template class.

 When such a member is defined outside
 its class, it must explicitly be declared
 a template.

*/

template<typename C>
String<C>::String() :sz{0}, ptr{ch}
{
	ch[0] = {};
}

template<typename C>
String& String<C>::operator+=(C c)
{
	// .....
	return this;
}



















