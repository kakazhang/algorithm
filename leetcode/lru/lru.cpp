#include <iostream>
#include <map>

#include "lru.h"
#include "list.h"

using namespace std;

LruCache::LruCache(int capacity)
{
    mCapacity = capacity;
    mIndex = 0;

    list_init(&mHead);
}

LruCache::~LruCache()
{
    struct listnode *node = &mHead;

    for (auto item = node->next; item != node;) {
        auto data = containof(item, struct lrudata, item);
        auto selected = item;
        item = item->next;
        list_remove_item(selected);
        cout << "delete val:" << data->val << endl;
        delete data;
    }
}

int LruCache::get(int key)
{
    LruData* data;

    if (mLruData.count(key) <= 0)
        return -1;

    auto it = mLruData.find(key);
    data = it->second;

    list_remove_item(&data->item);
    list_add_head(&mHead, &data->item);

    return data->val;
}

void LruCache::put(int key, int val)
{
    LruData *data = NULL;
    LruData *least = NULL;
    struct listnode *pHead = &mHead;

    if (mLruData.count(key) <= 0) {
        data = new LruData();
        data->val = val;

        cout << "new cache key:" << key << " val:" << val << endl;

        mIndex++;
        if (mIndex > mCapacity) {
             cout << "index=" << mIndex << endl;
             struct listnode *tail = pHead->prev;
             least = containof(tail, LruData, item);
             list_remove_item(tail);
             mLruData.erase(least->val);
        }

        list_add_head(pHead, &data->item);
        mLruData[key] = data;
    } else {
        data = mLruData.find(key)->second;
        list_remove_item(&data->item);
        list_add_head(&mHead, &data->item);
    }
}
