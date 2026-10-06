// car.h 
// Modifed from CPrimer + Edition 6E Chapter 17
#ifndef _CAR_H_
#define _CAR_H_
    #include <stdbool.h>

    struct car{
        int arrivalTime;
        int exitTime;
        int waitTime;
    };
    typedef struct car Car;
    typedef struct car Item;

    struct node{
        Item thisItem;
        struct node * next;
    };
    typedef struct node Node;

    /*************************************************************
    * void CopyToNode(Item newItem, Node * pn);
    * Copies the data from newItem into pn->thisItem 
    * Input: 
    *	newItem: An initalized Item variable
    *	pn: a pointer to an initialized Node
    **************************************************************/
    void CopyToNode(Item newItem, Node * pn);

    /*************************************************************
    * void CopyToItem(Node * pn, Item * pi);
    * Copies the data from pn->thisItem into the memory pi points to
    * Input: 
    *	pi: A pointer to an Item variable
    *	pn: a pointer to an initialized Node
    **************************************************************/
    void CopyToItem(Node * pn, Item * pi);


#endif
