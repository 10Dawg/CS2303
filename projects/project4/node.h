// node.h 
// Modifed from CPrimer + Edition 6E Chapter 17
#ifndef NODE_H
#define NODE_H
#include <memory>
using namespace std;

struct Car{
    int arrivalTime;
    int exitTime;
    int waitTime;
};

typedef Car Item;

struct Node{
    Item thisItem;
    shared_ptr<Node> next;
};

/*************************************************************
* void CopyToNode(Item newItem, share_ptr<Node> pn);
* Copies the data from newItem into pn->thisItem 
* Input: 
*	newItem: An initalized Item variable
*	pn: a pointer to an initialized Node
**************************************************************/
void CopyToNode(Item newItem, shared_ptr<Node> pn);

/*************************************************************
* void CopyToItem(share_ptr<Node> pn, Item * pi);
* Copies the data from pn->thisItem into the memory pi points to
* Input: 
*	pi: A pointer to an Item variable
*	pn: a pointer to an initialized Node
**************************************************************/
void CopyToItem(shared_ptr<Node> pn, Item * pi);


#endif
