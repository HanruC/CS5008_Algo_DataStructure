# Homework 02 - Guessing Game Instructions

Your goal for this assignment is to write a guessing game program in C. You will use everything you learned in CS 5001, but instead of python, you will be learning the fundamentals of C. This project will take a lot of research and figuring out the syntax.  It is important to start early, and submit often.

## Specifications

* Your player will play the guessing game a total of 5 times in a row. (5 rounds)
* Each round a new number must be randomly generated generate a number from 1 to 10.
* The player will guess a number.
  * If the number is correct, then the round ends.
  * If the number is wrong, then a hint should be provided whether the correct number is higher or lower.
* After the five rounds have completed, it will report how many guesses it took for each round. 
  * The final output should look similar to the following (as we will be using it for grading):
   ```text
   Round 1 took you 1 guesses.
   Round 2 took you 3 guesses.
   Round 3 took you 2 guesses.
   Round 4 took you 5 guesses.
   Round 5 took you 1 guesses.
   ```
* You do not have to worry about invalid input. A player will always enter a number, and you can ignore if
the number is higher or lower than 10 (is still counts as a guess, even if out of the 10 range)
* You *must* use the template provided
  * DO NOT reset the random seed! We are setting the random seed in the main, so we can test the program with a different main.
* You should provide your own unit tests for the program where you checked for program validity. 

👉🏽 **Task**: Turn in a completed program along with unit tests. 

For reference, here is some sample game output. You are free to modify it slightly, as long as the last 5 lines follow the same format. 

### Sample Game Output
```console
> clang -Wall game_main.c -o game.out
> ./game.out 
====================================================
| Welcome to the Guessing Game. Let's get started. |
====================================================
====================================================
|                     Round 1                      |
====================================================
Guess a number (1 to 10): 4
Congratulations, you found it!
====================================================
|                     Round 2                      |
====================================================
Guess a number (1 to 10): 10
Your guess is too high.
Guess a number (1 to 10): 5
Your guess is too low.
Guess a number (1 to 10): 7
Congratulations, you found it!
====================================================
|                     Round 3                      |
====================================================
Guess a number (1 to 10): 5
Your guess is too low.
Guess a number (1 to 10): 8
Congratulations, you found it!
====================================================
|                     Round 4                      |
====================================================
Guess a number (1 to 10): 55
Your guess is too high.
Guess a number (1 to 10): 5
Your guess is too low.
Guess a number (1 to 10): 8
Your guess is too high.
Guess a number (1 to 10): 7
Your guess is too high.
Guess a number (1 to 10): 6
Congratulations, you found it!
====================================================
|                     Round 5                      |
====================================================
Guess a number (1 to 10): 4
Congratulations, you found it!
====================================================
|              Results of the Rounds!              |
====================================================
Round 1 took you 1 guesses.
Round 2 took you 3 guesses.
Round 3 took you 2 guesses.
Round 4 took you 5 guesses.
Round 5 took you 1 guesses.
```

### Provided File Details:

* [guess_game.h](../guessing_game.h) - this is the primary file that will contain your code. Please use `start()` as the entry point for your program
* [game_main.c](../game_main.c) - the launch / entry point for your program. These are often system specific things, such as setting the random seed. 
* [game_tests_main.c](../game_tests_main.c) - the file to place your unit tests. We have also provided some sample code on how
to set the random to not be as random. 

### Hints
* You will want to use `rand()` to generate a random number (see example line in game_tests_main.c)
* Make sure to break up the code into smaller functions. 
  * In our implementation one function was only one line. Don't be afraid of making them short, C compilers are really good at optimizing your code if the functions are small.
* Make sure to document, that includes [README.md](../README.md) 
  * Make sure to cite your sources
* Make sure to do a lot of commits after each change (see below for example work flow)

## 📝 Grading Rubric


1. Learning (AG)
   * Code compiles **without** any warnings.
2. Approaching  (AG)
   * Code runs the basic game (some output shows up)
3. Meets  (AG)
   * Program runs with a variety of input, showing proper output based on everything submitted. 
4. Exceeds  (MG)
   * README.md updated (including sources cited)
     * Answers questions correctly.
   * Student followed single(ish) task per function design principle 
   * Student made and documented unit tests
   * Code fully documented and easy to follow (including header portion with student names)
   * Student has at least 3 commits with informative messages


AG - Auto-graded  
MG - Manually graded

TAs will look at manually graded portions *after* you have met full points on the autograded (you may resubmit). You may also resubmit MG components, but there will be a time delay for TAs to grade (usually a week).

### Submission
You will submit to gradescope via it pulling from your Github repository generated by Github classroom. As a reminder,
gradescope doesn't auto pull. If you make an update, and already submitted to gradescope you will need to go into gradescope and resubmit. 


### Instruction Home
Please note, if you are viewing these instructions in your repository copy, it is possible for your local copy to be out of sync with the official instructions. 
Double check instructions by going to: [HW 2 - Instructions](https://github.com/Spring23-CS5008-BOS-Lionelle/hw2-guessing-game/tree/main/instructions)

## 📚 Resources
* [clang compiler](https://clang.llvm.org/)
* [gcc compiler](https://www.gnu.org/software/gcc/)
* [Tutorials Point: C rand()](https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm)
* [Tutorials Point: C printf()](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm)
* [Learn C Interactive Tutorial](http://www.learn-c.org/)

### Github Commit Guide
Assignment work flow tends to be similar to the following:

* Open up your .c / .h file in a text editor
* Write or change a very small number of lines of code (sometimes just one change!)
* Save the text file
* Recompile your program `gcc -Wall main.c -o main.out` (or something similar)
* Run your program ./main and see if it does what you think it should be doing at this stage
  * This doesn't have to be a working program, but maybe a test you setup or print out!
* git add and git commit -m "your changes here" with the information about what you've added or changed
* Repeat!

This is the full "edit, save, compile, run, commit" cycle. It's very important that you follow this pattern for this assignment and throughout the semester! Write just a few lines of code, compile and check for warnings, and run your program. In fact, every time your program has a change in it, you should git commit the change and document it. 

Practice this pattern for this assignment and all assignments going forward! It's a crucial part of professional coding to get used to checking and committing small changes to your code base. 

Sometimes it may seem overkill, but it will make a difference as code bases get larger. 


## Compiling and Running Your Assignment
For this assignment, you may use the clang or gcc compiler. Both are industry standard compilers for compiling C programs (in addition to many other programming languages). Sometimes trying different compilers will given you more informative or helpful error messages--either one is perfectly fine for this course! 


Here is a way you will compile your code on the terminal.

```console
clang -Wall game_main.c -o game.out
```

or

```console
gcc -Wall game_main.c -o game.out
```
Both achieve the same thing.

1. First the compiler is specified.
2. Then a 'space' follows, and then the '.c' file we want to compile.
3. `-o` is a flag abbreviated for output. Items that begin with dash marks in general are compiler flags.
   * In this case the 'output' file we will generate(if there are no errors) will be called 'main'
   * Note: This 'game.out' file is a binary file that we can execute. This is different than 'main.c' which has the .c extension, and is a text file.
4. Finally, to execute your program, you will type in: ./game.out

While the extension is optional, anything with `.out` is ignored when syncing with Github (see [.gitignore](../.gitignore)). This saves from storing unneeded binary finals in your git history.

**Tip:** Sometimes compiling on both gcc and clang can give you different sets of warnings or errors that the other compiler could not catch.