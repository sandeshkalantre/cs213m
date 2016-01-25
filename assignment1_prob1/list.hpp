#ifndef _LIST_HPP_
#define _LIST_HPP_
#include "node.hpp"

/**
 * Inserts a new node into the list
 * Params:
 * Node* head : Pointer to start of list
 * int val : the value to be set for the new node
 * int pos : the position to insert, 0 being the head position
 * Return value:
 * Node* : the head of the new list
 */
Node* insert(Node* head, int val, int pos);

/**
 * Deletes a node from the list
 * Params:
 * Node* head : Pointer to start of the list
 * int pos : the position to delete, 0 being the head position
 * Return value:
 * Node* : the head of the new list, NULL if new list is empty
 */
Node* remove(Node* head, int pos);

/**
 * Computes the size of the list (no cycles)
 * Params:
 * Node* head : Pointer to the start of the list
 * Return value:
 * int : the length of the list
 */
int size(Node* head);

/**
 * Reverses a list (no cycles)
 * Params:
 * Node* head : Pointer to the start of the list
 * Return value:
 * Node* : head of the reversed list
 */
Node* reverse(Node* head);

/**
 * Computes the size of the cycle in the list
 * Params:
 * Node* head : Pointer to the start of the list
 * Return value:
 * int : the size of the cycle, 0 if there is none.
 */
int cycle_size(Node* head);

#endif // _LIST_HPP_
