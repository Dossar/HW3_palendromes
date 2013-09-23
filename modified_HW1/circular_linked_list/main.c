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

    char text[100];
    int begin, middle, end, length = 0;

    gets(text);

    while (text[length] != '\0')
        length++;

    end = length - 1;
    middle = length / 2;

    for (begin = 0; begin < middle; begin++) {
        if (text[begin] != text[end]) {
            printf("Not a palendrome.\n");
            break;
        }
        end--;
    }
    if (begin == middle) {
        printf("Palendrome.\n");
    }


    return (EXIT_SUCCESS);
}

