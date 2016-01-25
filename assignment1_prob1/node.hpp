#ifndef _NODE_HPP_
#define _NODE_HPP_
#include <cstdlib>

/**
 * A linked list node.
 * Node can be constructed using only a value or using a value and a pointer to
 * the next node.
 * Value cannot be changed once the node is created.
 * A NULL value for the head of a list is an empty list.
 */
class Node {

private:
	int m_val;
	Node* m_next;

public:
	Node(int val, Node* next = NULL);

	int getVal();
    
    Node* getNext();

    void setNext(Node* next);
};

#endif // _NODE_HPP_
