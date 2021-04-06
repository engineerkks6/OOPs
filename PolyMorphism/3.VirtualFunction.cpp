#include <iostream>
using namespace std;

class Base
{

public:
    virtual void FuncA()
    {
        cout << "This is Base Class Function A" << endl;
    }

    void FuncB()
    {
        cout << "This is Base Class Finction B" << endl;
    }
};

class Derived : public Base
{
public:
    void FuncA()
    {
        cout << "This Is Derived Class Function A" << endl;
    }
    void FuncB()
    {
        cout << "This Is Derived Class Function B" << endl;
    }
};
int main()
{
    Base *basePtr;
    Derived dObj;

    basePtr = &dObj;

    basePtr->FuncA();
    basePtr->FuncB();

    return 0;
}