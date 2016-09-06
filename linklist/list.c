#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void list_init(pNode head) {
    head->prev = head;
    head->next = head;
}

void list_add_head(pNode head, pNode item) {
    item->next = head->next;
    head->next->prev = item;

    head->next = item;
    item->prev = head;
}

void list_add_tail(pNode head, pNode item) {
    item->next = head;
    head->prev->next = item;

    item->prev = head->prev;
    head->prev = item;
}

void list_del(pNode item) {
    item->prev->next = item->next;
    item->next->prev = item->prev;
}


