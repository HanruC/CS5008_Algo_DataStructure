// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions.
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

#include <stdlib.h>

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
} node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL
{
    int count;    // count keeps track of how many items are in the DLL.
    node_t *head; // head points to the first node in our DLL.
    node_t *tail; // tail points to the last node in our DLL.
} dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t *create_dll()
{
    // Modify the body of this function as needed.
    dll_t *myDLL = (dll_t*)malloc(sizeof(dll_t));
    if (myDLL == NULL) {
        return NULL;
    }
    myDLL->count = 0;
    myDLL->head = NULL;
    myDLL->tail = NULL;
    return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns -1 if the dll is NULL.
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t *l)
{
    if (l == NULL) {
        return -1;
    }
    if (l->count == 0 && l->head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t *l, int item)
{
    if (l == NULL) {
        return -1;
    }
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = item;
    new_node->next = l->head;
    new_node->previous = NULL;

    if (l->head != NULL) { //set new prev for the previous head before pushing. 
        l->head->previous = new_node;
    } else { 
        l->tail = new_node;
    }
    l->head = new_node; // reset the new head for l.
    l->count++;
    return 1;
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t *l, int item)
{
    if (l == NULL) {
        return -1;
    }
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }
    new_node->data = item;
    new_node->previous = l->tail;
    new_node->next = NULL;
    
    if(l->tail != NULL) {
        l->tail->next = new_node;
    } else {
        l->head = new_node;
    }
    l->tail = new_node;
    l->count++;
    return 1;
}

// Returns the first item in the DLL and also removes it from the list.
// Returns -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t *t)
{
    if (t == NULL || t->head == NULL) {
        return -1;
    }

    node_t* pop_pointer = t->head; 
    int pop_item = pop_pointer->data; 
    t->head = pop_pointer->next; // set new head. 
    if (t->head != NULL) {
        t->head->previous = NULL;
    } else { // t->head = NULL cuz only one item and after popping, the t->head is null. 
        t->tail = NULL; // else if t->head = NULL, then t->tail also should be NULL.
    }
    t->count--;
    free(pop_pointer);
    return pop_item;
}

// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t *t)
{
    if (t == NULL || t->head == NULL) {
        return -1;
    }
    node_t* pop_pointer = t->tail;
    int pop_item = pop_pointer->data; 
    t->tail = pop_pointer->previous; 
    if (t->tail != NULL) {
        t->tail->next = NULL;
    } else {
        t->head = NULL;
    }
    t->count--;
    free(pop_pointer);
    return pop_item;
}

// Inserts a new node before the node at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
int dll_insert(dll_t *l, int pos, int item)
{
    if (l == NULL) {
        return -1;
    }
    if (pos > l->count || pos < 0) {
        return 0;
    }
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return 0;
    }
    new_node->data = item;
    if(pos == 0) {
        return dll_push_front(l, item);
    }
    if(pos == l->count) {
        return dll_push_back(l,item);
    }

    node_t* pointer = l->head;
    for (int i = 0; i < pos - 1; i++) {
        pointer = pointer->next; 
    }
    //ex: pos = 1, no for loop, pointer still head. 
    new_node->previous = pointer; // new->prev will be the head which is pointer. 
    new_node->next = pointer->next; // new->next will be the previous head->next. 
    pointer->next->previous = new_node; //previous head->next->prev will be the new. 
    pointer->next = new_node; // previous head next now be the new. 
    l->count++;
    return 1;
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
//  (does not remove the item)
// Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t *l, int pos)
{
   if (l == NULL) {
    return -1;
   } 
   if (pos < 0 || pos >= l->count) {
    return 0;
   }
   node_t* pointer = l->head;
   for (int i = 0; i < pos; i++) {
    pointer = pointer->next;
   }
   return pointer->data;
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
// Returns 0 on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
// Otherwise returns the value of the node removed.
int dll_remove(dll_t *l, int pos)
{
    if (l == NULL) {
        return -1;
    }
    if (pos < 0 || pos >= l->count) {
        return 0;
    }
    node_t* pointer = l->head;
    node_t* prev = NULL; // first node prev is null. 
    for (int i = 0; i < pos; i++) {
        prev = pointer;
        pointer = pointer->next;
    }
    if (prev == NULL) { // first item.
        l->head = pointer->next;
    } else {
        prev->next = pointer->next;
    }
    if (pointer->next != NULL) {
        pointer->next->previous = prev;
    }
    // if we are removing the tail node
    if (pointer == l->tail) {
        l->tail = prev;
    }
    int removed_value = pointer->data;
    free(pointer);
    l->count--;
    return removed_value;
}

// DLL Size
// Returns -1 if the DLL is NULL.
// Queries the current size of a DLL
int dll_size(dll_t *t) {   
    if (t == NULL) {
        return -1;
    }
    return t->count;
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the program terminates.
void free_dll(dll_t *t)
{
    if (t == NULL) {
        return;
    }
    node_t* pointer = t->head;
    while(pointer != NULL) {
        node_t* pointer2 = pointer; 
        pointer = pointer->next;
        free(pointer2); 
    }
    free(t);
}

#endif