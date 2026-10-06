/* queue.h -- interface for a queue */
/* Modifed from CPrimer + Edition 6E Chapter 17 */
#ifndef QUEUE_H
#define QUEUE_H
#include <memory>

#include "node.h"
using namespace std;
 
class Queue{
    

    private: 
        shared_ptr<Node> front;  /* pointer to front of queue  */
        shared_ptr<Node> rear;   /* pointer to rear of queue   */
        int items;     /* number of items in queue   */


    public:
        /*************************************************************
        * Queue()
        * Default Constructor
        * Sets front and back to nullptr
	    * Sets length to 0
        **************************************************************/
        Queue();

        /*************************************************************
        * bool isFull()
        * check if queue is full 
        * Output: returns True if queue is full, else False
        **************************************************************/
        bool isFull();

        /*************************************************************
        * bool isEmpty();
        * check if queue is empty 
        * Output: returns True if queue is empty, else False 
        **************************************************************/
        bool isEmpty();

        /*************************************************************
        * int itemCount();
        * Determine number of items in queue  
        * Output: returns number of items in queue 
        **************************************************************/
        int itemCount();

        /*************************************************************
        * bool EnQueue(Item newItem);
        * Adds item to the end of the queue
        * Input: 
        *	newItem: initalized Item to place at the end of the queue
        * Output: Returns True if the item was added to the queue.
        *		  Otherwise returns False
        **************************************************************/
        bool EnQueue(Item newItem);

        /*************************************************************
        * bool DeQueue(Item *pitem);
        * Removes item from the front of the queue
        * Input: 
        *	*pitem: pointer to memory allocated to store an item
        * Output: If the queue is not empty, copies the head item
        *		into pitem and deletes it from the queue and returns True
        *	    Otherwise returns False.
        **************************************************************/
        bool DeQueue(Item *pitem);

        /*************************************************************
        * void EmptyTheQueue();
        * Removes all items from the queue
        **************************************************************/
        void EmptyTheQueue();

        /*************************************************************
        * Item* peekItem();
        * Returns a pointer to the first item in the queue
        * Output: If the queue is not empty, returns a pointer to the first item
        **************************************************************/
        Item* peekItem();

};
#endif
