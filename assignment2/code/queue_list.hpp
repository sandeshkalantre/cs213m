#ifndef _QUEUE_LIST_HPP_
#define _QUEUE_LIST_HPP_

#include <list>

using namespace std;

template<class T>
class queue_list {
private:
  list<T> q;
  // Add more member variables if needed. Do not use STL queues.

public:
	/**
	 * Default constructor for the queue_list class
	 */
	queue_list();

	/**
	 * Copy constructor for the queue_list class.
	 * Params:
	 * const queue_list &to_copy_to : A reference to the queue_list object to be copied
	 * into.
	 */
	queue_list(const queue_list &to_copy_to);

	/**
	 * Default destructor for the queue_list class
	 */
	~queue_list();

	/**
	 * Pushes an object of type T at the back of the queue
	 * Params:
	 * T n : The object to be pushed at the back of the queue
	 */
	void push_back(T n);

	/**
	 * Gives the element at the front of the queue, if any
	 * Params:
	 * T *top_element : Pointer to the location where the front element is to be
	 *                  stored before returning
	 * Return value:
	 * int : Positive if queue is non empty, negative if it is empty
	 */
	int front(T *top_element);

	/**
	 * Removes the element at the front of the queue, if any
	 */
	void pop_front();

	/**
	 * Returns the number of elements in the queue
	 * Return value:
	 * int : Number of elements in the queue
	 */
	int size();
};

#endif //_QUEUE_LIST_HPP_
