#ifndef _LRU_H_
#define _LRU_H_
#include <map>
#include "list.h"

using namespace std;

typedef struct lrudata {
    struct listnode item;
    int val;
} LruData, *pLruData;

class LruCache {
    public:
        LruCache(int capacity);
        virtual ~LruCache();

        int get(int key);
        void put(int key, int val);
    private:
        int mCapacity;
        int mIndex;
        struct listnode mHead;
        map<int, LruData*> mLruData;
};

#endif
