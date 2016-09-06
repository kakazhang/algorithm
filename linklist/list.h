#ifndef LIST_H
#define LIST_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Node {
    struct Node *prev;
    struct Node *next;
} Position, *pNode;

#define contains(p, container, item) \
    (container *)((char *)(p) - offsetof(container, item))

#define list_for_each(head, item) \
    for ( (item) = (head)->next; (item) != (head); (item) = (item)->next ) \

#define list_for_each_safe(head, item, n) \
    for (item=(head)->next, n=(item)->next; item!=(head); item=(n),n=(n)->next)
    
void list_init(pNode head);

void list_add_head(pNode head, pNode item);

void list_add_tail(pNode head, pNode item);

void list_del(pNode item);

#ifdef __cplusplus 
}
#endif

#endif
