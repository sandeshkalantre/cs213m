#include "queue_vector.hpp"

template <class T>
queue_vector<T>::queue_vector()
{
    v = vector<T>();
}

template <class T>
queue_vector<T>::queue_vector(const queue_vector &to_copy_to)
{
    v = to_copy_to.v;
    //T* it;
    //vector empty
    //if(to_copy_to.front(it) > 0)
    //{
    //    for(int i = 0;i < to_copy_to.size(); i++)
    //    {
    //        v.push_back(*(it + i));
    //    }
    //}
}

template <class T>
queue_vector<T>::~queue_vector()
{
    v.~vector();
}

template <class T>
void queue_vector<T>::push_back(T n)
{
    v.push_back(n);
}

template <class T>
int queue_vector<T>::front(T *top_element)
{
    if(v.size() == 0)
    {
        return -1;
    }
    else
    {
        *top_element =  *(v.begin());
        return 1;
    }
}

template <class T>
void queue_vector<T>::pop_front()
{
    if(v.size() != 0)
    {
        v.erase(v.begin());
        return;
    }
    else
    {
        return;
    }
}

template <class T>
int queue_vector<T>::size()
{
    return v.size();
} 
