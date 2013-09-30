/* 
 * File:   main.c
 * Author: mike
 *
 * Created on September 28, 2013, 11:00 AM
 */

/*Assignment 1*/
/*Rubric for HW1 in Comp II.
1. The program does not have all the functions listed, output is not submitted. 5 pt. 
2. listOfPlayers could be array of integers, chars, or strings; listOfWords could be array of chars or strings. Players or words aren’t stored in arrays. 7 pt. 
3. The program seems complete, but output is missing. 7 pt.
4. The program has only one run of the rhyme. 8 pt.
5. The program has no intermediate output, only outputs the winner. 9 pt.
6. Each time the rhyme is started from the first player. 9 pt.
7. The program has all the functions, outputs “player - word” and which player is removed after each run, and the last remaining player – the winner. 10 pt*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "circular_list.h"

/* GLOBAL VARIABLE DECLARATIONS */
#define MAXWORDS 1000
#define MAXWORDLENGTH 80

/*SETUP ARRAYS*/
//int listOfPlayers[MAXPLAYERS] = {}; /* sets up all values to be 0 because there is no 0 player*/
char listOfWords[MAXWORDS][MAXWORDLENGTH] = {
    {0}
};

/*GLOBAL VARIABLES*/
int numbPlayers = 0;
int numbWords = 0;

/* FUNCTION DECLORATIONS  (prototypes)*/
void inputPlayers(void); /*inputPlayers function asks the user to input the number of players (or their names) and creates the list of Players */
void inputRhyme(void); /*inputRhyme function asks the user to input the rhyme and creates the list of words in a rhyme */
int doRhyme(); /*doRhyme function simulates one round of the game: */

/*my helper functions*/
int getInt(void);
void clearbuf(void);

int main(int argc, char** argv) {


    /*populate the players array*/
    inputPlayers();
    display();
    inputRhyme();

    int x = 1;
    while (last->link != last) {
        printf("\n*** ROUND #%d ***\n", x);
        doRhyme();
        x++;
    }
    
    printf("\n*** GAME WINNER === %d ***",last->info);




    return (EXIT_SUCCESS);
}

doRhyme() {
    struct node *temp;
    temp = last;

    // find out how many words there are
    int x = 0;
    while (strcmp(listOfWords[x], "") != 0) { // when a null or empty string is encountered the rhyme is complete
        x++;
    }
    printf("Length of rhyme = %d words\n", x);

    int y = 0;
    for (y = 0; y < x; y++) { // loop for the number of words or for the size of x
        last = last->link; // move to next player in circular list
        printf("player %d = %s\n", last->info, listOfWords[y]);
    }

    printf("removing player %d\n", last->info);
    del(last->info); // remove the corresponding player from the list
    printf("remaining players: ");
    display(); // display current list


}

/**
 * populate array of ints with size that is user specified and with numbers for their names
 */
void inputPlayers(void) {
    /* COLLECT USER INPUT   */
    int numb = getInt();
    /*will loop until a valid value is given*/
    while (numb == 0) {
        numb = getInt();
    }

    numbPlayers = numb; // set the current number of players globally

    create_list(numbPlayers); //create a linked list starting with the last value
    // populate list with values
    int x = 1;
    while (numbPlayers - x > 0) {
        addatbeg(numbPlayers - x);
        x++;
    }
}

/**
 * populate a two dimentional array with an inputted rhyme tokenized by whitespace
 */
void inputRhyme(void) {
    char input[10000] = {};
    printf("Please input a rhyme: ");
    gets(input);

    // tokenize the string into an array of strings.
    char* token;
    token = strtok(input, " ");
    // loop until last space is encountered.
    int x = 0;
    numbWords = 0;
    while (token != NULL) {
        printf("setting value -> %s\n", token); // to see what we are getting	  

        // set array value
        //listOfWords[MAXWORDS] = malloc(MAXWORDLENGTH);
        memcpy(&listOfWords[x], token, MAXWORDLENGTH);
        x++;
        numbWords++;

        // get next token
        token = strtok(NULL, " ");
    }

    printf("\n");
}

/**********************/
/**HELPER FUNCTIONS*/
/**********************/

/*Function to get valid user input
 Will return 0 if numbers are invalid otherwise it will return the number*/
int getInt(void) {
    /*local variables*/
    int numb;
    char term;

    printf("please enter the number of players: ");
    if (scanf("%d%c", &numb, &term) != 2 || term != '\n') {
        clearbuf(); // needed for halting the processor. for some reason it doesnt want to stop here without it.
        /*failure on number input*/
        printf("Invalid number value.\n");
        return 0;
    } else {
        /*valid integer entered*/
        return numb;
    }
}

/* for some reason using fflush does not work here but this seems to solve the issue.*/
void clearbuf(void) {
    while (getchar() != '\n');
}

