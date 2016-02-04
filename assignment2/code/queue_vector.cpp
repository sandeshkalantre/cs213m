#include "queue_vector.hpp"

template<class T>
queue_list<T>::queue_list()
{

}

template<class T>
queue_list<T>::queue_list(const queue_list &to_copy_to)
{
    T* it;
    if(to_copy_to.front(it) > 0)
    {
        for(int i = 0;i < to_copy_to.size(); i++)
        {
            q.push_back(*(it + i));
        }
    }
}

template<class T>
queue_list<T>::~queue_list()
{
    //call the vector destructor
    v.~vector();
}

template<class T>
void queue_list<T>::push_back(T n)
{
    v.push_back(n);
}

template<class T>
int queue_list<T>::front(T *top_element)
{
    if(v.size() == 0)
    {
        return -1;
    }
    else
    {
        top_element =  &v.front();
        return 1;
    }
}

template<class T>
void queue_list<T>::pop_front()
{
    if(v.size() == 0)
    {
        return;
    }
    else
    {
        v.pop_front();
        return;
    }
}

template<class T>
int queue_list<T>::size()
{
    return v.size;
}

