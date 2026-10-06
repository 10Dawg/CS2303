#include "car.h"

void CopyToNode(Item newItem, Node * pn){
    pn->thisItem = newItem;
}

void CopyToItem(Node * pn, Item * pi){
    *pi = pn->thisItem;
}
