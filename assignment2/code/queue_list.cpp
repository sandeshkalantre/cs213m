#include "queue_list.hpp"

template<class T>
queue_list<T>::queue_list()
{
    //queue empty
    _size = 0;
}

template<class T>
queue_list<T>::queue_list(const queue_list &to_copy_to)
{
    T* it;
    //queue empty
    _size = 0;
    if(to_copy_to.front(it) > 0)
    {
        for(int i = 0;i < to_copy_to.size(); i++)
        {
            q.push_back(*(it + i));
            _size++;
        }
    }
}

template<class T>
queue_list<T>::~queue_list()
{
    //call the list destructor
    q.~list();
}

template<class T>
void queue_list<T>::push_back(T n)
{
    q.push_back(n);
    _size += 1;
}

template<class T>
int queue_list<T>::front(T *top_element)
{
    if(_size == 0)
    {
        return -1;
    }
    else
    {
        top_element =  &q.front();
        return 1;
    }
}

template<class T>
void queue_list<T>::pop_front()
{
    if(_size == 0)
    {
        return;
    }
    else
    {
        q.pop_front();
        return;
    }
}

template<class T>
int queue_list<T>::size()
{
    return _size;
}

