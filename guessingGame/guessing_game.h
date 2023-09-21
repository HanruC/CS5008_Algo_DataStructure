/*  ========== H02 - Guessing Game ============
 *
 *   Student: Hanru Chen 
 *   Semester: Spring 2023 
 *
 * A simple guessing game program. 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H

#define MAX_RANDOM 10
#define MIN_RANDOM 1

/** add as many functions as you need 
 * remember good design practices 
*/

/**
 * construct the guess_dice as dice. 
*/
typedef struct guess_dice { 
    int dicenumber;
    int guesstime;
} dice; 

/**
 * This is a method for making a dice.
 * It includes to get a random dice number.
 * It returns random number of dice. 
*/
dice makeDice() {
    dice randice;
    randice.dicenumber = rand() % MAX_RANDOM + MIN_RANDOM;
    randice.guesstime = 0;
    return randice;
}

/**
 * This is a method to get a guess number from user. 
*/
int get_guess_from_user() {
    int guess;
    scanf("%d", &guess);
    return guess;
}
/**
 * This is a method to get hint. 
*/
int give_feedback(int guessnumber, int randice) {
    if (randice == guessnumber) {
        printf("Congrats! You found it!\n");
        return 1;
    } else if (guessnumber > randice) {
        printf("Lower please.\n"); 
        return 2;
    } else {
        printf("Higher please.\n");
        return 3;
    }
}
// In order to deliver a flexible unit test 
// pass get_guess as a pointer, also take guess_array as a parameter 
// In order to store guess times in each round.
// In this function, we input the guessnumber and randice from method above. 
// For loop five times to get five rounds of guessing game and store 
// each round's guessing time into guess array. 
int guess_game_logic(int *guess_array, int (*get_guess)()){ 
    dice randice;
    int guessnumber;
    for (int i=0; i<5; i++){
        randice = makeDice();
        printf("--------Round %d------\n", i+1);
        while (1){
            printf("What is your guess (1-10): \n");
            guessnumber = get_guess(); // get guess from user. 
            int feedback = give_feedback(guessnumber, randice.dicenumber);
            if (feedback == 1) { // 1 for same. 
                guess_array[i] = randice.guesstime + 1;
                randice.guesstime = 0;
                break;
            } else {
                randice.guesstime++;
            }
        }   
    }
    return 0;
}

/** Start location for the guessing game - this must
 * remain the starting point. DO NOT reset the random seed.
 */
int start_game (){
    int guess_array[5]; // make the array size 5. 
    int (*get_guess)() = get_guess_from_user; // passing the method to get guess number 
    guess_game_logic(guess_array, get_guess); // call logic method to start the game.
    // print each round's guessing time. 
    printf("Round %d took you %d guesses.\n", 1, guess_array[0]);
    printf("Round %d took you %d guesses.\n", 2, guess_array[1]);
    printf("Round %d took you %d guesses.\n", 3, guess_array[2]);
    printf("Round %d took you %d guesses.\n", 4, guess_array[3]);
    printf("Round %d took you %d guesses.\n", 5, guess_array[4]);
    return 0; // returns 0 if game ran validly
}

#endif