/* 
 * File:   palindrome.c
 * Author: Mike Meding and Roy Van Liew
 *
 * Created on September 23, 2013, 2:28 PM
 */

/* PROGRESS

- Current code is bulky and all in the main function. The code for creating the new palindrome examples can be put into functions, but for now this code is just a working build.
- For the new palindrome examples, not a few characters are changed, but the entire original palindrome is changed. This might be a problem when grading comes.
- Program works on both palindromes and not palindromes, both of even and odd length. I'm concerned about bulky code that can be reduced with function calls and global variables, along with not changing the entire original palindrome.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

   /* text is for storing the string. begin, middle, and, and length are involved with the palindrome check. */
   char text[100];
   int begin, middle, end, length = 0;
   int palcheck = 1; /* This is to determine the 3 different palindrome functions to be executed. */
   
   printf("Please enter a string no longer than 100 characters: "); /* Prompt the user to input text into array */
   gets(text); /* Save user's input string into text array */

   /* For calculating the length of the string, iterate through until the null terminator is reached. This will give the exact string length. */
   while ( text[length] != '\0' )
      length++;

   /* This is for the array position in the for loop to check for the palindrome. The array positions go from 0 to (length-1). */
   end = length - 1;

   /* If palindrome is odd length, decimal gets truncated. The "decimal" is just the one letter in the very middle.
      Palindrome is a mirror of the first half. For example, 1110111, the 111 part is mirrored.
      For odd-length palindromes, the very middle letter does not matter.
      For even-length palindromes, the two middle letters need to be the same. */
   middle = length / 2;

   /* Iterate though all of the letters from the beginning to the middle of the string.
      begin (array position) is for the first half of the string, end (array position) is for the second half of the string. */
   for( begin = 0 ; begin < middle ; begin++ ) {

	  /* if the text at the current position and the the (end - the current position) it is not a palindrome */
	  if( text[begin] != text[end] ){
		 printf("\"%s\"\nWhat you entered above is not a palindrome.\nYou will be shown three other examples of palindromes now.\n", text);
                 palcheck = 2;
		 break; /* If the "mirrored" parts do not match, get out of this for statement. It is not a palindrome. */
	  }

	  end--; /* Move the second half position to match the mirrored portion in the first half. */
   }

   /* Checks to see if the loop ended sucessfully finding a palindrome.
      if a palindrome is found then that means that the loop sucessfully iterated to the center of the word */
   if( begin == middle && palcheck == 1 ){
	  printf("\"%s\"\nWhat you entered above is a palindrome.\nYou will be shown three other examples of palindromes now.\n", text);
                 printf("Please enter a string no longer than 100 characters for the examples:\n");
                 char userchar[100];
                 int length2 = 0;
                 gets(userchar); /* Save user's input for generating 3 other palindromes */
                 while( userchar[length2] != '\0' ){
                    length2++;
                 }
                 end = length - 1;
                 int i = 0;
                 begin = 0;
                 /* Since a palindrome has been created, we only need to modify it now, don't need to check */
                 for( begin = 0 ; begin < middle ; begin++ ){
                    text[begin] = userchar[i];
                    text[end] = userchar[i];
                    end--;
                    if( ++i > length2 - 1 )
                      i = 0;                      
                 }
                 printf("\"%s\" is a possible palindrome.\n", text);
                 end = length - 1;
                 begin = 0;
                 /* Since a palindrome has been created, we only need to modify it now, don't need to check */
                 for( begin = 0 ; begin < middle ; begin++ ){
                    text[begin] = userchar[i];
                    text[end] = userchar[i];
                    end--;
                    if( ++i > length2 - 1 )
                      i = 0;                      
                 }
                 printf("\"%s\" is a second possible palindrome.\n", text);
                 end = length - 1;
                 begin = 0;
                 /* Since a palindrome has been created, we only need to modify it now, don't need to check */
                 for( begin = 0 ; begin < middle ; begin++ ){
                    text[begin] = userchar[i];
                    text[end] = userchar[i];
                    end--;
                    if( ++i > length2 - 1 )
                      i = 0;
                 }
                 printf("\"%s\" is a third possible palindrome.\n", text);
   } /* End if statement for the case where it is a palindrome */

   /* For the case where the input was not a palindrome. */
   if( begin != middle && palcheck == 2 ){

                 printf("Please enter a string no longer than 100 characters for the examples:\n");
                 char userchar[100];
                 int length2 = 0;
                 gets(userchar); /* Save user's input for generating 3 other palindromes */
                 while( userchar[length2] != '\0' ){
                    length2++;
                 }
                 end = length - 1;
                 int i = 0;
                 begin = 0;
                 /* This for loop will manually create the palindrome. */
                 for( begin = 0 ; begin < middle ; begin++ ){
                    if( text[begin] != text[end] ){
                       text[begin] = userchar[i];
                       text[end] = userchar[i];
                    }
                    end--;
                    if( ++i > length2 - 1 )
                      i = 0;
                 }
                 printf("\"%s\" is a possible palindrome.\n", text);
                 end = length - 1;
                 begin = 0;
                 /* Since a palindrome has been created, we only need to modify it now, don't need to check */
                 for( begin = 0 ; begin < middle ; begin++ ){
                    text[begin] = userchar[i];
                    text[end] = userchar[i];
                    end--;
                    if( ++i > length2 - 1 )
                      i = 0;                      
                 }
                 printf("\"%s\" is a second possible palindrome.\n", text);
                 end = length - 1;
                 begin = 0;
                 /* Since a palindrome has been created, we only need to modify it now, don't need to check */
                 for( begin = 0 ; begin < middle ; begin++ ){
                    text[begin] = userchar[i];
                    text[end] = userchar[i];
                    end--;
                    if( ++i > length2 - 1 )
                      i = 0;
                 }
                 printf("\"%s\" is a third possible palindrome.\n", text);

   } /* End if statement for the case where it is NOT a palindrome */

   return (EXIT_SUCCESS); // end of program
}

