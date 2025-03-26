// Constructor Destructor

struct Tracer {
	string mess;
	Tracer(const string& s) :mess{s} {clog << mess; }
	~Tracer() { clog << "~" << mess; }
};

void f(const vector<int>& c)
{
	Tracer tr{"in f()\n"};

}
















