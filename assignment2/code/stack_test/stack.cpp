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

    _stack = to_copy_to._stack;
}

template <class T>
stack<T>::~stack()
{
    delete [] _stack;
}

template <class T>
void stack<T>::push(T n)
{
    _top_pos += 1;
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
        *top_element = *(_stack + _top_pos);
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
