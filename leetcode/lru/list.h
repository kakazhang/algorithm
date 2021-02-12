#ifndef _LIST_H_
#define _LIST_H_
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define containof(item, container, member) \
    (container *)(((char*)(item)) - offsetof(container, member))

struct listnode {
    struct listnode *prev;
    struct listnode *next;
};

void list_init(struct listnode* node);

void list_add_head(struct listnode* head, struct listnode* item);

void list_add_tail(struct listnode* head, struct listnode* item);

void list_remove_item(struct listnode* item);

#ifdef __cplusplus
}
#endif
#endif
