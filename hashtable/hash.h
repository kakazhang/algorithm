#ifndef HASH_H
#define HASH_H
#define MAX_SIZE 128
typedef struct Node {
	char Elem[MAX_SIZE];
	struct Node* Next;
} *Position, *List;

typedef struct HashTable {
	size_t TableSize;
	Position* TheList;
} HTable, *pTable;

int hash(char* key);

pTable initialize();

Position Find(char elem[], pTable table);

void Insert(char elem[], pTable table);

void destroy(pTable table);

void dump(pTable table);
#endif