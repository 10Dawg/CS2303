/* queue.h -- interface for a queue */
/* Modifed from CPrimer + Edition 6E Chapter 17 */
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>
#include "car.h"

struct queue{
    Node * front;  /* pointer to front of queue  */
    Node * rear;   /* pointer to rear of queue   */
    int items;     /* number of items in queue   */
};
typedef struct queue Queue;

/*************************************************************
* void InitializeQueue(Queue * pq)
* Initializes the queue
* Input: pq pointing to memory allocated for a Queue
* Output: None
* The queue is initialized to empty
**************************************************************/
void InitializeQueue(Queue * pq);

/*************************************************************
* bool QueueIsFull(const Queue * PQ)
* check if queue is full 
* Input: PQ points to an initialized queue
* Output: returns True if queue is full, else False
**************************************************************/
bool QueueIsFull(const Queue * PQ);

/*************************************************************
* bool QueueIsEmpty(const Queue *PQ);
* check if queue is empty 
* Input: PQ points to an initialized queue
* Output: returns True if queue is empty, else False 
**************************************************************/
bool QueueIsEmpty(const Queue *PQ);

/*************************************************************
* int QueueItemCount(const Queue * PQ);
* Determine number of items in queue  
* Input: PQ points to an initialized queue
* Output: returns number of items in queue PQ 
**************************************************************/
int QueueItemCount(const Queue * PQ);

/*************************************************************
* bool EnQueue(Item newItem, Queue * pq);
* Adds item to the end of the queue
* Input: 
*	pq: points to an initialized queue
*	newItem: initalized Item to place at the end of the queue
* Output: Returns True if the item was added to the queue.
*		  Otherwise returns False
**************************************************************/
bool EnQueue(Item newItem, Queue * pq);

/*************************************************************
* bool DeQueue(Item *pitem, Queue * pq);
* Removes item from the front of the queue
* Input: 
*	pq: points to an initialized queue
*	*pitem: pointer to memory allocated to store an item
* Output: If the queue is not empty, copies the head item
*		into pitem and deletes it from the queue and returns True
*	    Otherwise returns False.
**************************************************************/
bool DeQueue(Item *pitem, Queue * pq);

/*************************************************************
* void EmptyTheQueue(Queue * pq);
* Removes all items from the queue
* Input: 
*	pq: points to an initialized queue
**************************************************************/
void EmptyTheQueue(Queue * pq);




/*************************************************************
* bool peekItem(Item *pitem, const Queue const * PQ);
* Returns a pointer to the first item in the queue
* Input: 
*	PQ: points to an initialized queue
* Output: If the queue is not empty, returns a pointer to the first item
**************************************************************/
Item* peekItem(const Queue * const PQ);

#endif
