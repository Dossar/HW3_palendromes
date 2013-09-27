/* 
 * File:   palindrome.c
 * Author: Mike Meding and Roy Van Liew
 *
 * Created on September 23, 2013, 2:28 PM
 */

/*
 * The program has now been split up into functions to prevent main from being bulky.
 * All the functions work. However, the original array gets changed entirely.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* GLOBAL VARIABLES AND ARRAYS */
char text[100]; /* For original palindrome */
char userchar[100]; /* For three other palindrome examples */
int begin, middle, end, length = 0; /* Variables involved with the original palindrome check. */
int i, length2 = 0; /* For generating 3 more palindrome examples */
int palcheck = 1; /* For determining which example functions to execute. */
int midremainder = 0; /* For changing palindrome in the case it is odd */

/* FUNCTION DECLARATIONS */
void checkpalindrome(void); /* User inputs original string for palindrome test. */
void notpalindrome(void); /* In the case of not being a palindrome, the first example will need to fix the string */
void palexample(void); /* Make examples of other palindromes from modifying the original text array */

int main(int argc, char** argv){
   
   /* Start the program off by having the user input a string and then check if it is a palindrome or not. */
   checkpalindrome();

   /* For the case where the input was a palindrome */
   if( begin == middle && palcheck == 1 ){
	  printf("\"%s\"\nWhat you entered above is a palindrome.\nYou will be shown three other examples of palindromes now.\n", text);
                 printf("Please enter a string no longer than 100 characters for the examples:\n");
                 gets(userchar); /* Save user's input for generating 3 other palindromes */
                 while( userchar[length2] != '\0' )
                    length2++;

                 /* Call palexample 3 times to generate 3 more examples of palindromes */
                 palexample();
                 palexample();
                 palexample();

   } /* End if statement for the case where it is a palindrome */

   /* For the case where the input was not a palindrome. */
   if( begin != middle && palcheck == 2 ){

                 printf("Please enter a string no longer than 100 characters for the examples:\n");
                 gets(userchar); /* Save user's input for generating 3 other palindromes */
                 while( userchar[length2] != '\0' )
                    length2++;

                 /* Generate 3 more examples of palindromes, but original needs to be fixed first */
                 notpalindrome();
                 palexample();
                 palexample();

   } /* End if statement for the case where it is NOT a palindrome */

   return (EXIT_SUCCESS); /* End of program */

}


/* This function has the user input the original string and then check if it is a palindrome or not. */
void checkpalindrome(void){

   /* Save user's input into text, the original palindrome array. */
   printf("Please enter a string no longer than 100 characters: ");
   gets(text);

   /* Iterate through until the null terminator is reached. This will give the exact string length. */
   while ( text[length] != '\0' )
      length++;

   /* This is for the array position in the for loop to check for the palindrome. The array positions go from 0 to (length-1). */
   end = length - 1;

   /* If palindrome is odd length, decimal gets truncated. The "decimal" is just the one letter in the very middle.
      In palindromes, the second half is a mirror of the first half.
      For odd-length palindromes, the very middle letter does not matter.
      For even-length palindromes, the two middle letters need to be the same. */
   if( length % 2 == 1 )
      midremainder = 5;
   middle = length / 2;

   /* Iterate though all of the letters from the beginning to the middle of the string.
      begin is for first half positions, end is for second half positions. */
   for( begin = 0 ; begin < middle ; begin++ ) {

	  /* If the text at the current mirrored positions does not match, it is not a palindrome */
	  if( text[begin] != text[end] ){
		 printf("\"%s\"\nWhat you entered above is not a palindrome.\nYou will be shown three other examples of palindromes now.\n", text);
                 palcheck = 2;
		 break; /* If the "mirrored" parts do not match, get out of this for statement. It is not a palindrome. */
	  }

	  end--; /* Move the second half position to match the mirrored portion in the first half. */
   }

   return;

}


/* This is for making the original inputted text a palindrome. */
void notpalindrome(void){

   end = length - 1;
   begin = 0;

   /* This for loop will manually create the palindrome since the original was not a palindrome. */
   for( begin = 0 ; begin < middle ; begin++ ){
                    
      /* Test whether the corresponding mirrored positions are the same. If not, replace with a character inputted from the user. */
      if( text[begin] != text[end] ){
         text[begin] = userchar[i];
         text[end] = userchar[i];
      }
      end--;
      if( ++i > length2 - 1 )
         i = 0;

   }
   /* If the palindrome is of odd length, this code changes the middle letter. */
   if( midremainder == 5 ){
      text[middle] = userchar[i];
      i++;
   }
   printf("\"%s\" is a possible palindrome.\n", text);

   return;
}


/* If the original palindrome array "text" is already a palindrome, no check is needed. */
void palexample(void){

   end = length - 1;
   begin = 0;

   /* Since a palindrome exists already, we only need to modify it now, don't need to check */
   for( begin = 0 ; begin < middle ; begin++ ){

      text[begin] = userchar[i];
      text[end] = userchar[i];
      end--;
      if( ++i > length2 - 1 )
         i = 0;      
                
   }
   /* If the palindrome is of odd length, this code changes the middle letter. */
   if( midremainder == 5 ){
      text[middle] = userchar[i];
      i++;
   }
   printf("\"%s\" is a possible palindrome.\n", text);

   return;

}
