// Program to illustrate
// virtual functions

#include <iostream>
#include <memory>

class base 
{
	public:
		base() {
			std::cout << "Base created " << " ";
		}
		virtual void  f1() {
			std::cout << "Base function 1" << " ";
		}
		virtual void f2() {  
			std::cout << "Base funct 2" << " ";
		}

		void f3()
		{
			std::cout << "Non virtual base " << "  ";
		}

		~base() {
			std::cout << "Base Destroyed" << " ";
		}
};

class derived : public base
{
	public:

		derived() {
			std::cout << "Derived created" << " ";
		}
		void f1()
		{
			std::cout << "Base function 1 in 2" << " ";
		}

		void f2()
		{
			std::cout << "Base function 2 in 2" << " ";
		}

		void f2(int x)
		{
			std::cout << "Base function 2 with arg int" << x << " ";
		}

		~derived() {
			std::cout << "Derived Destroyed" << " ";
		}

};

int main() {

/*	base* b;
	derived d;
	
	b = &d;

	b->f1();

	b->f2();

	d.f2(55);*/

//	std::unique_ptr<base> d = std::make_unique<base>();
//	d->f3();

	derived d1;
	base* b1 =  static_cast<base*>(&d1);
	b1->f3();

	return 0;

}
