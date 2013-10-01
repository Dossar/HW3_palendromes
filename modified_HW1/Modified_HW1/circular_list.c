
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "circular_list.h"

/**
 * creates a list of size num
 * @param num the integer size of the list to be created.
 * @return 
 */
create_list(int num) {
   struct node *q, *temp;
   temp = malloc(sizeof (struct node));
   temp->info = num;
   if (last == NULL) {
	  last = temp;
	  temp->link = last; // link head to tail for one node.
   } else {
	  temp->link = last->link;
	  /*added at the end of list*/
	  last->link = temp;
	  last = temp;
   }
}/*End of create_list()*/

/**
 * add a node at the beginning of the list
 * @param num the number to be added at the beginning of the list
 * @return 
 */
addatbeg(int num) {
   struct node *temp;
   temp = malloc(sizeof (struct node));
   temp->info = num;
   temp->link = last->link;
   last->link = temp;
}/*End of addatbeg()*/

/**
 * add after the given position iin the list
 * @param num the number to be used as the data to be stored
 * @param pos the element to find and to add afterwards.
 * @return 
 */
addafter(int num, int pos) {
   struct node *temp, *q;
   int i;
   q = last->link;
   for (i = 0;
		   i < pos - 1;
		   i++) {
	  q = q->link;
	  if (q == last->link) {
		 printf("There are less than %d elements\n", pos);
		 return;
	  }
   }/*End of for*/
   temp = malloc(sizeof (struct node));
   temp->link = q->link;
   temp->info = num;
   q->link = temp;
   if (q == last) /*Element inserted at the end*/
	  last = temp;
}/*End of addafter()*/

/**
 * remove the element with info corresponding to the function argument
 * @param num
 * @return 
 */
del(int num) {
   struct node *temp, *q;
   if (last->link == last && last->info == num) /*Only one element*/ {
	  temp = last;
	  last = NULL;
	  free(temp);
	  return;
   }
   q = last->link;
   if (q->info == num) {
	  temp = q;
	  last->link = q->link;
	  free(temp);
	  return;
   }
   while (q->link != last) {
	  if (q->link->info == num) /*Element deleted in between*/ {
		 temp = q->link;
		 q->link = temp->link;
		 free(temp);
		 printf("%d deleted\n", num);
		 return;
	  }
	  q = q->link;
   }/*End of while*/
   if (q->link->info == num) /*Last element deleted q->link=last*/ {
	  temp = q->link;
	  q->link = last->link;
	  free(temp);
	  last = q;
	  return;
   }
   printf("Element %d not found\n", num);
}/*End of del()*/

/**
 * display the entire list.
 * @return 
 */
display() {
   struct node *q;
   if (last == NULL) {
	  printf("List is empty\n");
	  return;
   }
   q = last->link;
   while (q != last) {
	  printf("%d ", q->info);
	  q = q->link;
   }
   printf("%d\n", last->info);
}/*End of display()*/