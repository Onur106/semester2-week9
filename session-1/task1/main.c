
#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"

int main( void ) {

    // create some nodes
    Node *first = createNode(createData(1));
    Node *second = createNode(createData(2));
    Node *third = createNode(createData(3));

    // link the nodes
    first->next = second;
    second->next = third;
    
    // print the data by following links
    
    printf("TraverseI: ");
    traverseI(first);

    // BURAYA EKLE (freeNodes'dan ÖNCE)
    printf("TraverseW: ");
    traverseW(first);

    printf("TraverseR: ");
    traverseR(first);
    // free all node memory (using traversal)
    freeNodes( first );

    return 0;
}
