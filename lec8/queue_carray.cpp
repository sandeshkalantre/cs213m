#include<iostream>
using namespace std;

class queue
{
        int* _queue;
        int _front;
        int _end;
        int _size;
    public:
        queue(int);
        bool is_empty();
        bool is_full();
        void insert(int);
        void del();
            

};
 
queue::queue(int max_size = 256)
{
    _size = max_size;
    _queue = new int [size];
    _front = -1;
    _end = 0;
}

bool queue::is_empty()
{
    if(_front + 1 == _end)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool queue::is_full()
{
    if
