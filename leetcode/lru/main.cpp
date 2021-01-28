#include <iostream>

#include "list.h"

using namespace std;

typedef struct lrudata {
    int val;
    struct listnode item;
} LruData, *pLruData;

static struct listnode head;

void iterate(struct listnode *list)
{
    pLruData data = NULL;
    struct listnode *node = &head;
    struct listnode *item;
    for (item = node->next; item != node; item=item->next) {
        data = containof(item, struct lrudata, item);
        cout << "val:" <<data->val << endl;
    }
}

void list_delete(int val)
{
    struct listnode *node = &head;

    for (auto item = node->next; item != node; item=item->next) {
       auto data = containof(item, struct lrudata, item);
       if (data->val == val) {
           list_remove_item(item);
           delete data;
       }
    }
}

void list_remove_all()
{
    struct listnode *node = &head;

    for (auto item = node->next; item != node;) {
        auto data = containof(item, struct lrudata, item);
        auto selected = item;
        item = item->next;
        list_remove_item(selected);
        cout << "delete val:" << data->val << endl;
        delete data;
    }
}
void listusage(int count)
{
    pLruData data = NULL;
    list_init(&head);

    for (auto i = 0; i < count; i++) {
        data = new LruData();
        data->val = i;
        list_add_head(&head, &data->item);
    }

    iterate(&head);

    list_delete(3);

    cout << "iterate after delete" << endl;
    iterate(&head);

    list_remove_all();
}

int main(int argc, char** argv)
{
    listusage(10);

    return 0;
}
