#include <stdio.h>
#include <stdlib.h>



#include "stack_structures.h"
#include "stack.h"

int main(void) {
    // 1. Initialize: createStack(void) olduğu için parametre gönderme
    Stack *myStack = createStack(); 

    // 2. Push operations: push(Stack*, Data*) beklediği için createData() kullan
    push(myStack, createData(10));
    push(myStack, createData(20));
    push(myStack, createData(30));

    // 3. Traverse: myStack->top, dizideki eleman sayısını temsil ediyor
    printf("Stack content:\n");
    for(int i = 0; i < myStack->top; i++) {
        printf("%d\n", myStack->data[i]->value);
    }

    // 4. Pop operations: pop() bir Data* döndürür, onu free etmeliyiz
    Data *popped = pop(myStack);
    if(popped != NULL) {
        printf("Popped: %d\n", popped->value);
        free(popped);
    }

    // 5. Cleanup: freeNodes stack için değil linked list için olabilir, 
    // stack için özel bir freeStack fonksiyonun olmalı (yoksa belleği elle free et)
    // Eğer freeStack fonksiyonun yoksa, stack içindeki data array'ini ve stack'i free et:
    free(myStack);
    
    printf("Stack cleaned.\n");

    return 0;
}