/* queue.c -- the Queue type implementation*/
#include <iostream>
using namespace std;
#include "queue.h"

/* local functions */
Queue::Queue() {
  front = nullptr;
  rear = nullptr;
  //cout << "Queue Constructor Called" << endl;
  items = 0;
}

bool Queue::isEmpty(){
    return items == 0;
}

int Queue::itemCount(){
    return items;
}

bool Queue::EnQueue(Item newItem){
    // Allocate memory for a new node on the heap
    shared_ptr<Node> pnew= make_shared<Node>();
    if (pnew == nullptr){
        cout <<"Unable to allocate memory!\n";
        exit(1);
    }

	// Copy the item into the queue
    CopyToNode(newItem, pnew);
    pnew->next = nullptr;
    if (isEmpty()){
        front = pnew;           /* item goes to front     */
	}
    else{
        rear->next = pnew;      /* link at end of queue   */
	}
	rear = pnew;                /* record location of end */
    items++;                    /* one more item in queue */
    
    return true;
}

bool Queue::DeQueue(Item * pitem){
    
	// check if there are items to remove
    if (isEmpty()){
        return false;
	}
	// copy the front item into pitem
    CopyToItem(front, pitem);
	// remove the front of the queue and free memory

    front = front->next;

    items = items - 1;
    if (items == 0){
        rear = nullptr;
	}
    
    return true;
}

/* empty the queue                */
void Queue::EmptyTheQueue(){
    Item temp;
    while (items > 0){
        DeQueue(&temp);
	}
	puts("Queue was freed");
}

Item* Queue::peekItem(){
   
	// check if there are items to remove
    if (isEmpty()){
        return NULL;
	}
	// copy the front item into pitem
    Item* pitem = &(front->thisItem);
    return pitem;
}