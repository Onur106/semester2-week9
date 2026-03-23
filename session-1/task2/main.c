#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"
#include "stack_structures.h"
#include "stack.h"

int main( void ) {

    printf("=== STACK TESTS START ===\n");

    
    Stack *stack = createStack();

   
    printf("\n--- Testing PUSH ---\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    
    printf("Stack content after pushing 10, 20, 30:\n");
    traverseI(stack->top);  
    
    printf("\n--- Testing POP ---\n");
    Node *poppedNode = pop(stack);

    if (poppedNode != NULL) {
        printf("Popped value: %d\n", poppedNode->data->value);
        
        
        freeNode(poppedNode); 
    } else {
        printf("Stack was empty!\n");
    }

   
    printf("Stack content after pop:\n");
    traverseI(stack->top);
   

    
    freeNodes( stack->top );
    
    free(stack);

    printf("\n=== TESTS FINISHED (Memory Freed) ===\n");

    return 0;
}