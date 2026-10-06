/* queue.c -- the Queue type implementation*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void InitializeQueue(Queue * pq){
    pq->front = NULL;
	pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsEmpty(const Queue * PQ){
    return PQ->items == 0;
}

int QueueItemCount(const Queue * PQ){
    return PQ->items;
}

bool EnQueue(Item newItem, Queue * pq){
   // Allocate memory for a new node on the heap
	Node* pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr,"Unable to allocate memory!\n");
        return false;
    }

	// Copy the item into the queue
    CopyToNode(newItem, pnew);
    pnew->next = NULL;

	// if empty, put the item at the front of the queue
    if (QueueIsEmpty(pq)){
        pq->front = pnew;          
	}
    else{
		// add to the end of the queue
        pq->rear->next = pnew;      
	}
	// update the location of the end of the queue
	pq->rear = pnew;                
    pq->items++;                   
    
    return true;
}

bool DeQueue(Item * pitem, Queue * pq){
    // check if there are items to remove
    
	if (QueueIsEmpty(pq)){
        return false;
	}
	Node* pt;
    // copy the front item into pitem
    CopyToItem(pq->front, pitem);
	// remove the front of the queue and free memory
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0){
        pq->rear = NULL;
	}
    
    return true;
}

/* empty the queue                */
void EmptyTheQueue(Queue * pq){
    Item temp;
    while (!QueueIsEmpty(pq)){
        DeQueue(&temp, pq);
	}
	puts("Queue was freed");
}



Item* peekItem(const Queue * const PQ){
	// check if there are items to remove
    if (QueueIsEmpty(PQ)){
        return NULL;
	}
	// copy the front item into pitem
    Item* pitem = &(PQ->front->thisItem);
    return pitem;
}