#include<iostream>
using namespace std;
class Base
{   
    public:
    // Base()
    // {
    //         cout<<"In Base Class Constructor"<<endl;
    // }
    Base(int n)
        {
            cout<<"In Base Class Constructor"<<n<<endl;
        }
    
};

class Derived : public Base 
{
    public:
        Derived(int n):Base(n)
        {
            cout<<"Derived "<<n<<endl;
        }
};

int main()
{
    Derived d1(10);
}