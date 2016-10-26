#ifndef BITMAP_H
#define BITMAP_H

#define BITSPERLONG sizeof(long) * 8

#define BITMAPMASK (BITSPERLONG - 1)

void set(int i);

void clear(int i);

int test(int i);

int getzeroleft(unsigned int a);

int getzeroright(unsigned int a);
#endif
