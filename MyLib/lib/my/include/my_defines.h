/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_DEFINES_
#define MY_DEFINES_

#define TOGGLE_BOOL(a) (a = (a == false))

#define RESET(thing) do {if (thing) free(thing); thing = NULL;} while(0)

/////* linked_list */
#define PREV(thing) thing = thing->prev
#define NEXT(thing) thing = thing->next
#define ADD_NODE(new, target) new->next = target; target = new
/////////////////////

#endif /* MY_DEFINES_ */
