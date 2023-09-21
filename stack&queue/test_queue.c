/*  ========== H03 - Personal Queue Implementation ============
 *
 *   Student: Hanru Chen
 *   Semester: Spring 2023
 *
 * A simple queue unit-tst implementation 
 *
 */

// Note: This is not an exhaustive test suite, but gives you the idea
//       of some tests you might want to create.
//       Adding more tests and slowly making them more and more complicated
//       as you develop your library is recommended.
//
// Compile this assignment with: gcc -g -Wall queue_test.c -o queue_test
//
// Run with: ./queue_test
//

#include "myqueue.h"

#include <stdio.h> // For IO operations


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.

// Tests that a new queue was created and the capacity
// was properly set.
int unitTest1(int status)
{
    int passed = 0;
    queue_t *testq = create_queue(30);
    if (30 == testq->capacity)
    {
        passed = 1;
    }
    free_queue(testq);

    return passed;
}

// Tests adding multiple items to a queue
int unitTest2(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(10);
    queue_enqueue(testq, 1);
    queue_enqueue(testq, 2);
    queue_enqueue(testq, 3);
    queue_enqueue(testq, 4);
    queue_enqueue(testq, 5);
    queue_enqueue(testq, 6);
    queue_enqueue(testq, 7);
    queue_enqueue(testq, 8);
    queue_enqueue(testq, 9);
    queue_enqueue(testq, 10);
    if (10 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

// Tests enqueing and dequeing
int unitTest3(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(32);
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }

    for (i = 0; i < 32; i++)
    {
        if (!queue_empty(testq)){
            queue_dequeue(testq);
        }
        else {
            printf("no items to dequeue!\n");
            break;
        }
    }
    if (0 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

// Tests enqueing and dequeing multiple times
int unitTest4(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(32);
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }
    for (i = 0; i < 32; i++)
    {
        queue_enqueue(testq, 1);
    }
    for (i = 0; i < 32; i++)
    {
        queue_dequeue(testq);
    }

    if (0 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}

int unitTest5(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(1);
    queue_enqueue(testq, 1);
    if (1 == queue_full(testq))
    {
        passed = 1;
    }
    else
    {
        free_queue(testq);
        return 0;
    }

    queue_dequeue(testq);
    if (0 == queue_full(testq))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }

    free_queue(testq);

    return passed;
}
// test to see if create a new list and the capacity is delivered correct. 
int unitTest6(int status)
{
    int passed = 0;
    queue_t *testq = create_queue(20);
    if (testq != NULL){
        if (20 == testq->capacity){
            passed = 1;
        }
        free_queue(testq);
    }
    return passed;
}
// test if the queue will add number and check the size if is equall to created queue.
int unitTest7(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(12);
    queue_enqueue(testq, 3);
    queue_enqueue(testq, 2);
    queue_enqueue(testq, 4);
    queue_enqueue(testq, 5);
    queue_enqueue(testq, 6);
    queue_enqueue(testq, 9);
    queue_enqueue(testq, 8);
    queue_enqueue(testq, 7);
    queue_enqueue(testq, 0);
    queue_enqueue(testq, 10);
    queue_enqueue(testq, 11);
    queue_enqueue(testq, 12);
    if (12 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}
// test to see if the queue will be created as the capacity claimed
//also to check if the dequeue works by check the size after dequeue. 
int unitTest8(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(18);
    int i = 0;
    for (i = 0; i < 18; i++)
    {
        queue_enqueue(testq, 3);
    }

    for (i = 0; i < 18; i++)
    {
        if (!queue_empty(testq)){
            queue_dequeue(testq);
        }
        else {
            printf("no items to dequeue!\n");
            break;
        }
    }
    if (0 == queue_size(testq))
    {
        passed = 1;
    }

    free_queue(testq);

    return passed;
}
//enqueue and dequeue multiple times. 
int unitTest9(int status)
{
    int passed = 0;

    queue_t *testq = create_queue(20);
    for (int i = 0; i < 20; i++)
    {
        queue_enqueue(testq, 6);
    }
    for (int i = 0; i < 20; i++){
        if (!queue_empty(testq)){
            queue_dequeue(testq);
        }
        else {
            printf("no items to dequeue!\n");
            break;
        }
    }
    for (int i = 0; i < 20; i++){
        queue_enqueue(testq, 3);
    }
    for (int i = 0; i < 20; i++){
        if (!queue_empty(testq)){
            queue_dequeue(testq);
        }
        else {
            printf("no items to dequeue!\n");
            break;
        }
    }
    if (0 == queue_size(testq)){
        passed = 1;
    }
    free_queue(testq);

    return passed;
}
// this is the test to check if the queue input is full and return the full signal according to queue_full. 
int unitTest10(int status){
    int passed = 0;
    queue_t *testq = create_queue(5);
    for (int i = 0; i < 5; i++){
        queue_enqueue(testq, i);
    }
    if (queue_full(testq)){
        passed = 1;
    }
    free_queue(testq);
    return passed;
}
// TODO: Add more tests here
// add your own, and uncomment the provided tests as 
// things are implemented
int (*unitTests[])(int) = {
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    unitTest10,
    NULL};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;
    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter);
        if (1 == unitTests[counter](1))
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;
}