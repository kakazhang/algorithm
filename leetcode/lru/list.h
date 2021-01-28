#ifndef LIST_H
#define LIST_H
#include <stddef.h>

#define containof(item, container, member) \
    (container *)(((char*)(item)) - offsetof(container, member))

struct listnode {
    struct listnode *prev;
    struct listnode *next;
};

void list_init(struct listnode* node)
{
    node->prev = node;
    node->next = node;
}

void list_add_head(struct listnode* head, struct listnode* item)
{
    item->prev = head;
    item->next = head->next;
    head->next->prev = item;
    head->next = item;
}

void list_add_tail(struct listnode* head, struct listnode* item)
{
    item->next = head;
    item->prev = head->prev;
    head->prev->next = item;
    head->prev = item;
}

void list_remove_item(struct listnode* item)
{
    item->prev->next = item->next;
    item->next->prev = item->prev;
}
#endif
