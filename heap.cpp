#include <iostream>
using namespace std;

int main()
{
    long heap_size = 0;
    while(1)
    {
        long *p =  new long [heap_size];
        heap_size += sizeof(long);
        if (heap_size % 1000000 == 0)
        {
            cout<<"Heap size(MB) = "<<heap_size/1000000<<endl;
        }
    }
    return 0;
}

