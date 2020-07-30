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

        
        return 0;
}     
