// Compile this assignment with: clang -g -Wall main.c -o main.out
// Use this file to implement testing for your
// doubly linked list implementation

#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

#include "my_dll.h"




// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    dll_t* dll = create_dll();

    dll_push_front(dll, 1);
    dll_push_front(dll, 2);
    dll_push_front(dll, 3);
    dll_push_front(dll, 4);
    printf("dll size is: %d\n", dll_size(dll));

    dll_push_back(dll, 5);
    dll_push_back(dll, 6);
    dll_push_back(dll, 7);
    printf("dll size is: %d\n", dll_size(dll));

    printf("Item removed: %d\n", dll_remove(dll, 0));
    printf("Item removed: %d\n", dll_remove(dll, 1));
    printf("Item removed: %d\n", dll_remove(dll, 2));

    dll_insert(dll, 3, 8);
    dll_insert(dll, 4, 11);
    dll_insert(dll, 2, 15);
    printf("dll size: %d\n", dll_size(dll));

    printf("popped item is: %d\n", dll_pop_front(dll));
    printf("popped item is: %d\n", dll_pop_back(dll));

    printf("size now is: %d\n", dll_size(dll));
    free_dll(dll);

    return 0;
}