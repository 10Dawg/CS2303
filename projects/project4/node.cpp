#include "node.h"

void CopyToNode(Item newItem, shared_ptr<Node> pn){
    pn->thisItem = newItem;
}

void CopyToItem(shared_ptr<Node> pn, Item * pi){
    *pi = pn->thisItem;
}
