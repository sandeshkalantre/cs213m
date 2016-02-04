#include <iostream>
using namespace std;

int main()
{
    int j;
    int* p;
    p = &j;
    cout<<"j = "<<j<<endl;
    cout<<"p = "<<p<<endl;
    cout<<"&j = "<<&j<<endl;
    cout<<"&p = "<<&p<<endl;

    //evil shit
    //Compiler error
    //p = &p
    return 0;
}

