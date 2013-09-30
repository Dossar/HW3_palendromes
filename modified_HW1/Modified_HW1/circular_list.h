/* 
 * File:   circular_list.h
 * Author: mike
 *
 * Created on September 28, 2013, 2:59 PM
 */

#ifndef CIRCULAR_LIST_H
#define	CIRCULAR_LIST_H

#ifdef	__cplusplus
extern "C" {
#endif

   struct node {
	  int info;
	  struct node *link;
   } *last;

   void addafter(int, int);
   void addatbeg(int);
   void create_list(int);
   void del(int);
   void display(void);




#ifdef	__cplusplus
}
#endif

#endif	/* CIRCULAR_LIST_H */

