#include <iostream>

using std::cout;
using std::endl;


class Base
{
public:
        Base () { cout << "Base default constructor called." << endl; }
        ~Base () { cout << "Base destructor called." << endl; }

        void func () { cout << "Base function called." << endl; }
};


class Derived : public Base
{
public: 
        Derived () { cout << "Derived default constructor called" << endl; }
        ~Derived () { cout << "Derived destructor called." << endl; }

        void func () { cout << "Derived function called." << endl; }

};

int main ()
{       
	// creation
	Base * b_ptr = new Base();
	Base * d_ptr = new Derived();

	// destruction
	delete b_ptr; // works fine
	b_ptr = nullptr;

	delete d_ptr; // doesn't actually calles for the Derived destructor
       		      // that's why we need virtual keyword infront of the destructor
	d_ptr = nullptr;
	        
        return 0;
}     
