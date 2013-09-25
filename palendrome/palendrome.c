/* 
 * File:   main.c
 * Author: mike
 *
 * Created on September 23, 2013, 2:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

   // Variables
   char text[100];
   int begin, middle, end, length = 0;

   // Input text into array
   gets(text);

   // get the current length of the array by iterating until the null terminating character
   while (text[length] != '\0')
	  length++;

   // set end to be one less than the length because it goes from 0 - (length -1)
   end = length - 1;
   // middle is obviously half of the length
   middle = length / 2;

   // iterate though all of the letters from the beginning to the middle of the string
   for (begin = 0; begin < middle; begin++) {
	  // if the text at the current position and the the (end - the current position) it is not a palendrome
	  if (text[begin] != text[end]) {
		 printf("Not a palendrome.\n");
		 break; // in which case break out of the loop
	  }
	  end--;
   }

   // checks to see if the loop ended sucessfully finding a palendrome.
   // if a palendrome is found then that means that the loop sucessfully iterated to the center of the word
   if (begin == middle) {
	  printf("Palendrome.\n");
   }


   return (EXIT_SUCCESS); // end of program
}

