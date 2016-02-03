#include "stack.hpp"

template <class T>
stack<T>::stack()
{
    _MAX_SIZE = 100000;
    _stack = new T [_MAX_SIZE];
    _top_pos = -1;
}

template <class T>
stack<T>::stack(const stack &to_copy_to)
{
    _MAX_SIZE = 100000;
    _stack = new T [_MAX_SIZE];
    _top_pos = -1;

    T *top_ele;
    //if stack non-empty
    if(to_copy_to.top(top_ele) > 0)
    {
        //use a loop to copy elements one by one
        for(int i = to_copy_to.size(); i > 0 ; i--)
        {
            *(_stack + i - 1) = *top_ele; 
            top_ele -= 1;
        }
        _top_pos = to_copy_to.size() - 1;
    }
}

template <class T>
stack<T>::~stack()
{
    delete [] _stack;
}

template <class T>
void stack<T>::push(T n)
{
    _top_pos = 0;
    *(_stack + _top_pos) = n;
    return;
}

template <class T>
int stack<T>::top(T *top_element)
{
    //stack empty
    if(_top_pos == -1)
    {
        return -1;
    }
    else
    {
        top_element = (_stack + _top_pos);
        return 1;
    } 
}

template <class T>
void stack<T>::pop()
{
    if(_top_pos == -1)
    {
        return;
    }
    else
    {
        _top_pos -= 1;
        return;
    }
}

template <class T>
int stack<T>::size()
{
    return (_top_pos + 1);
}
