#ifndef _QUEUE_VECTOR_HPP_
#define _QUEUE_VECTOR_HPP_

#include <vector>

using namespace std;

template<class T>
class queue_vector {
private:
  vector<T> v;
  // Add more member variables if needed. Do not use STL queues.

public:
	/**
	 * Default constructor for the queue_vector class
	 */
	queue_vector();

	/**
	 * Copy constructor for the queue_vector class.
	 * Params:
	 * const queue_vector &to_copy_to : A reference to the queue_vector object to be copied
	 * into.
	 */
	queue_vector(const queue_vector &to_copy_to);

	/**
	 * Default destructor for the queue_vector class
	 */
	~queue_vector();

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

#endif //_QUEUE_VECTOR_HPP_
