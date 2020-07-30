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


// we need to inherit virtually Base class so we don't have a diamond problem
class Derived : virtual public Base
{
public: 
        Derived () { cout << "Derived default constructor called" << endl; }
        ~Derived () { cout << "Derived destructor called." << endl; }

	// override keyword checks if we really have such function signature
	// in the base class that we want to override
	// in the case of int func() we will have a compile error because 
	// the right function signature in the base class is void func()
        void func () override { cout << "Derived function called." << endl; }

};

// we need to inherit virtually Base class so we don't have a diamond problem
class Derived_Two : virtual public Base
{
public:
	Derived_Two () {cout << "Derived_Two default constructor called." << endl; }
	~Derived_Two () { cout << "Derived_Two destructor called." << endl; }

	void func () override { cout << "Derived_Two function called." << endl; }
};


// one use of keyword final is prevention of any deriving from this class
class SecondLineDerived final : public Derived 
{
public:
	SecondLineDerived () 
		{ cout << "SecondLineDerived default constructor called." << endl; }
	~SecondLineDerived ()
		{ cout << "SecondLineDerived destructor called." << endl; }

	// second use of final keyword: we mark the final derived class that can override 
	// the specific function which is represented in compile error
	// if some other derived class of this one tries to override
	void func() override final { cout << "SecondLineDerived function called." << endl; }
};


// compile error: we can't derive from a class marked as final
/*
class ThirdLineDerived : public SecondLineDerived
{
public:
	ThirdLineDerived () 
		{ cout << "ThirdLineDerived default constructor called." << endl; }
	~ThirdLineDerived ()
		{ cout << "ThirdLineDerived destructor called." << endl; }

	// this will cause an compile error as well because the function 
	// was marked as final 
	void func() override { cout << "ThirdLineDerived function called." << endl; }
};
*/


// the diamond problem comes from not using virtual keyword and occurs when a class
// derives from two other classes with a common base class
// the actual problem in this case without the virtual keyword class Diamond will 
// have two copies of the Base class which will cause ambiguities
// NOTE: when we use virtual keyword the default constructor of the Base class 
// is called by default even if the parent classes explicitly call the parameterized
// constructor
class Diamond : public Derived, Derived_Two
{
public: 
        Diamond () { cout << "Diamond default constructor called" << endl; }
        ~Diamond () { cout << "Diamond destructor called." << endl; }

	// override keyword checks if we really have such function signature
	// in the base class that we want to override
	// in the case of int func() we will have a compile error because 
	// the right function signature in the base class is void func()
        void func () override { cout << "Diamond function called." << endl; }
};

int main ()
{       
	// creation
	Base * b_ptr = new Base();
	Base * d_ptr = new Derived();
	Base * s_ptr = new SecondLineDerived();
	Base * d2_ptr = new Derived_Two();
	Diamond * dmnd_ptr = new Diamond();
	cout << endl;

	// calling a function
	b_ptr->func(); // works fine
	d_ptr->func(); // in order to call the function of the Derived class we need to have
		       // properly working run time virtual polymorphism 
		       // or in other words we need to mark the Base function as virtual
	s_ptr->func();
	d2_ptr->func();
	dmnd_ptr->func();

	cout << endl;

	// destruction
	delete b_ptr; // works fine
	b_ptr = nullptr;

	delete d_ptr; // this needs to call the Derived destructor
       		      // that's why we need virtual keyword in front of the base destructor
	d_ptr = nullptr;

	delete s_ptr;
	s_ptr = nullptr;

	delete d2_ptr;
	d2_ptr = nullptr;
	        
	delete dmnd_ptr;
	dmnd_ptr = nullptr;

	// end of program
        return 0;
}     
