#include "list.hpp"


/**
 * Inserts a new node into the list
 * Params:
 * Node* head : Pointer to start of list
 * int val : the value to be set for the new node
 * int pos : the position to insert, 0 being the head position
 * Return value:
 * Node* : the head of the new list
 */
Node* insert(Node* head, int val, int pos)
{
    if(pos == 0)
    {
        Node *new_node = new Node(val,head); 
        return new_node;
    }
    else
    {           
        //node which iteratres through the list
        Node* itr_node = head;

        for(int i = 0;i < pos-1;i++)
        {
            itr_node = itr_node->getNext();
        }   
        
        Node *new_node = new Node(val,itr_node->getNext()); 
        itr_node->setNext(new_node);
        return head;
    } 
}
/**
 * Deletes a node from the list
 * Params:
 * Node* head : Pointer to start of the list
 * int pos : the position to delete, 0 being the head position
 * Return value:
 * Node* : the head of the new list, NULL if new list is empty
 */
Node* remove(Node* head, int pos)
{
    if(pos == 0)
    {
        return head->getNext();
    }
    else
    {
        //node which iteratres through the list
        Node* itr_node = head;

        for(int i = 0;i < pos-1;i++)
        {
            itr_node = itr_node->getNext();
        }   
        itr_node->setNext(itr_node->getNext());
        return head;
    } 
} 
/**
 * Computes the size of the list (no cycles)
 * Return value:
 * int : the length of the list
 */
int size(Node* head)
{
    int length = 0;
    
    //node which iteratres through the list
    Node* itr_node = head;
    while(itr_node)
    {
        length++; 
        itr_node = itr_node->getNext();
    }
    return length;
}

/**
 * Reverses a list (no cycles)
 * Params:
 * Node* head : Pointer to the start of the list
 * Return value:
 * Node* : head of the reversed list
 */
Node* reverse(Node* head)
{
    Node* next_node = NULL;
    Node* last_node = NULL;
    Node* itr_node = head;
    while(itr_node)
    {   
        next_node = itr_node->getNext();
        itr_node->setNext(last_node);
        last_node = itr_node;
        itr_node = next_node;
    }
    return last_node; 
}


/**
 * Computes the size of the cycle in the list
 * Params:
 * Node* head : Pointer to the start of the list
 * Return value:
 * int : the size of the cycle, 0 if there is none.
 */
int cycle_size(Node* head)
{
    //empty list
    if (head == NULL)
    {
        return 0;
    }
    //based on Flyod's algorithm
    Node* tort = head;
    Node* hare = head->getNext();
    
    while(hare != tort)
    {
       if(!(tort = tort->getNext())){return 0;}
       if(!(hare = hare->getNext())){return 0;}
       if(!(hare = hare->getNext())){return 0;}
    }
    //hare and tort are at the same position
    //incrmenting one while keeping the other constant will give the length
    int cyc_len = 0;
    do
    {
        hare = hare->getNext();
        cyc_len++;
    }
    while(hare != tort);
    return cyc_len; 

}
