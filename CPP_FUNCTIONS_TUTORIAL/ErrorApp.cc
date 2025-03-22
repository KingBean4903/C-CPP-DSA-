// Sample error app to build on
#include <cstdarg>

extern void error(int ...);
extern char* itoa(int, char[]);

int main(int argc, char* argv[])
{
	switch(argc)
	{
		case 1:
			error(0, argv[0],nullptr);
			break;
		case 2:
			error(0,argv[0],argv[1],nullptr)
			break;
		default:
			char buffer[8];
			error(1,argv[0],"with",itoa(argc-1,buffer),"arguments",nullptr);
	}
	// ..
}

void error(int severity ...)
{
	va_list ap;
	va_start(ap, severity);

	for (;;)
	{
		char* p = va_arg(ap,char*);
		if (p == nullptr)break;
	    cerr << p << ' ';
	}
	va_end(ap);
	cerr << '\n';
	if (severity) exit(severity);
}

// Alternate
void error(int severity, initializer_list<string>err)
{
	for (auto& s: err)
		cerr << s << '';
	cerr << '\n';
	if (severity) exit(severity);
}
// Or
void error(int severity, const vector<string>& err)
{
	for (auto &s : err)
		cerr << s << '';
	cerr << '\n';
	if (severity) exit(severity);
}













