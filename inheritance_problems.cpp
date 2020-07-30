#include <iostream>

using std::cout;
using std::endl;


class Base
{
public:
        Base () { cout << "Base default constructor called." << endl; }
        virtual ~Base () { cout << "Base destructor called." << endl; }

        virtual void func () { cout << "Base function called." << endl; }
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

	// calling a function
	b_ptr->func(); // works fine
	d_ptr->func(); // in order to call the function of the Derived class we need to have
		       // properly working run time virtual polymorphism 
		       // or in other words we need to mark the Base function as virtual

	// destruction
	delete b_ptr; // works fine
	b_ptr = nullptr;

	delete d_ptr; // doesn't actually calls for the Derived destructor
       		      // that's why we need virtual keyword in front of the base destructor
	d_ptr = nullptr;
	        
        return 0;
}     
