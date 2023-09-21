/*  ========== H02 - Guessing Game ============
 *
 *   Student: Hanru Chen
 *   Semester: Spring 23
 *
 *   This file builds the foundation for a 'testing' framework for the game
 *   You will want to build unit tests in this file, and run them. 
 *   You have freedom to use this file as you need. It also provides
 *   an example of how to control the random seed.
 * 
 *   For reference, we are using a file similar to this for auto-grading. 
 */ 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "guessing_game.h"  

/** 
 * This is a test function to test if the makeDice method would make correct dice
 * number in the given range from 1 - 10. 
 * Return 1 if failed. 
 **/
int test_makeDice() {
    dice randice = makeDice();
    if (randice.dicenumber < MIN_RANDOM || randice.dicenumber > MAX_RANDOM){
        printf("Error occur: outside the range 1-10");
        return 1; 
    }
    return 0; // if there weren't errors
}
/**
 * This is a test method to test if get_guess_number method would
 * help user to get correct guess number.
 * Test fails if return 1.
*/
int test_get_guess_number() { 
    int passed = 0;
    printf("Enter a number: 5\n");
    int guess = get_guess_from_user();
    if (guess != 5) {
        printf("Test case 1 failed: expected 5, got %d\n", guess);
        passed = 1;
    }

    printf("Enter a number: 7\n");
    guess = get_guess_from_user();
    if (guess != 7) {
        printf("Test case 2 failed: expected 7, got %d\n", guess);
        passed = 1;
    }

    printf("Enter a number: 10\n");
    guess = get_guess_from_user();
    if (guess != 10) {
        printf("Test case 3 failed: expected 10, got %d\n", guess);
        passed = 1;
    }
    return passed;
}

/**
 * Test to see if feedback is right.
*/
int test_give_feedback() {
    int errors = 0;
    dice randice;
    randice.dicenumber = 5;
    int actual = give_feedback(5, randice.dicenumber);
    int expected = 1; // as the guess number and random number are the same.
    if (actual != expected) {
        printf("give_feedback test failed: expected %d but got %d\n", expected, actual);
        errors++;
    }
    return errors;
}
/**
 * This is a test method to test guess_game_logic method.
 * Given the logic, the guess times each round would not be over 10 which is 
 * the Max random number 10. 
 * Thus, in this test method, we are here to check if the guess_array number is 
 * larger than 10. If it is larger, then wrong and return 1. 
*/
int test_guess_game_logic() {
    int guess_array[5];
    guess_game_logic(guess_array, get_guess_from_user);

    // check that the guess times are within a reasonable range
    for (int i = 0; i < 5; i++) {
        if (guess_array[i] < 1 || guess_array[i] > MAX_RANDOM) {
            printf("Error: unexpected guess time for round %d: %d\n", i + 1, guess_array[i]);
            return 1;
        }
    }

    // if all guess times are within range, return 0
    return 0;
}


/** saves the random number seed out to a file,
 * so it can be regenerated for testing purposes.
 *
 * The way to save out the values would be
 * tester.out random 20 > rand_sequence.txt
 *
 * assuming tester is what you setup for your compile command of
 *  clang -Wall tests/game_tests_main.c -o tester.out
 */
void save_random(char *count_c) {
    char *end;
    long count = strtol(count_c, &end, 10);

    for(int i = 0; i < count; i++) {
       printf("%d\n", rand() % MAX_RANDOM + MIN_RANDOM);
    }

}

/* Program entry point*/
/* Options for running 

Run the unit tests: > game_tester.out  
Run the game with a set random seed: > game_tester.out play
Generate random numbers: > game_tester.out random ## 
(were ## is a number)

*/
int main(int argc, char *argv[]) {

    /**rand() generates psuedo random numbers
     * based on a seed. In production it is common
     * to use the system clock time as the seed as that
     * is always changing. however, for tests, you want
     * to fix the random numbers so you want to set the seed.
     * 
     * The problem is that different OS version + Hardware
     * still generate different random numbers even if the
     * seed is the same. A 'hacky' (but works) way to do it
     * is write a quick program that generates a series of random
     * numbers based on a specific seed. Then call your
     * other program using that specific seed. 
     * 
     * In order to conserve files, kept this as one program using
     * the program arguments to generate the random numbers. If no
     * 
    */
    srand(1); // to force the tests to have a set random number group
    if(argc > 1) {
        if(argc > 2) {
            save_random(argv[2]);
            return 1;
        }else { 
            return start_game(); 
        }
    }else {
        int errors = 0;
        errors += test_makeDice(); // check return number 0/1. 
        errors += test_guess_game_logic();
        errors += test_get_guess_number();
        errors += test_give_feedback();
        if (errors == 0) {
            printf("Test pass!\n");
        } else {
            printf("\n**Fail %d unit tests.**\n", errors);
        }
    }
    return 0;
}