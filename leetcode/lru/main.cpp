#include <iostream>

#include "list.h"
#include "lru.h"

using namespace std;
#if 1
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

void lrucache()
{
    LruCache cache(4);

    cache.put(1, 1);
    int val = cache.get(1);
    cout << "val(1)=" << val << endl;

    cache.put(2, 2);
    val = cache.get(2);
    cout << "val(2)=" << val << endl;

    cache.put(3, 3);
    val = cache.get(3);
    cout << "val(3)=" << val << endl;

    cache.put(4, 4);
    val = cache.get(4);
    cout << "val(4)=" << val << endl;

    cache.put(5, 5);
    val = cache.get(5);
    cout << "val(5)=" << val << endl;

    cache.put(6, 6);
    val = cache.get(6);
    cout << "val(6)=" << val << endl;

    cout << "val(1)=" << cache.get(1) << endl;
    cout << "val(2)=" << cache.get(2) << endl;
}

int main(int argc, char** argv)
{
    //listusage(10);
    lrucache();

    return 0;
}

#else

int main(int argc, char** argv)
{
    return 0;
}

#endif
