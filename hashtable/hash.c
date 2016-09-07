#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "hash.h"

#define TABLESIZE 11

#define die(...) {\
	printf(__VA_ARGS__); \
	exit(-1); \
}

pthread_mutex_t gMutex[TABLESIZE];

int hash(char* key) {
	unsigned int hashVal = 0;

	while (*key != '\0') {
		hashVal = (hashVal << 5) + *key++;
	}

	return hashVal % TABLESIZE;
}

pTable initialize() {
	pTable table = (pTable)malloc(sizeof(HTable));
	if (!table) {
		perror("malloc");
		die("no memory");
	}

	table->TableSize = TABLESIZE;
	table->TheList = (Position *)malloc(sizeof(Position) * TABLESIZE);

	int i;
	for (i = 0; i < TABLESIZE; i++) {
		table->TheList[i] = NULL;
		//gMutex[i] = PTHREAD_MUTEX_INITIALIZER;
		pthread_mutex_init(&gMutex[i], NULL);
	}
	return table;
}

Position Find(char elem[], pTable table) {
	Position found = NULL;
	int hashval = hash(elem);
	
	pthread_mutex_lock(&gMutex[hashval]);
	Position p = table->TheList[hashval];

	while (p) {
		if (!strcmp(p->Elem, elem)) {
			found = p;
			break;
		}

		p = p->Next;
	}
	pthread_mutex_unlock(&gMutex[hashval]);
	
	return found;
}

void Insert(char elem[], pTable table) {
	Position p = Find(elem, table);

	if (!p) {
		Position newPos = (Position)malloc(sizeof(struct Node));
		if (!newPos)
			die("No space for new postion");
		
		memset(newPos->Elem, 0, MAX_SIZE);
		strncpy(newPos->Elem, elem, strlen(elem) + 1);

		int hVal = hash(elem);
		
		pthread_mutex_lock(&gMutex[hVal]);
		List list = table->TheList[hVal];

		newPos->Next = list;
		table->TheList[hVal] = newPos;
		pthread_mutex_unlock(&gMutex[hVal]);
	}
}

void destroy(pTable table) {
	if (table) {
		int i;
		for (i = 0; i < TABLESIZE; i++) {
			List list = table->TheList[i];
			while (list) {
				Position p = list;
				list = list->Next;

				free(p);
			}
			pthread_mutex_destroy(&gMutex[i]);
		}
		free(table->TheList);
		free(table);
	}

}

void dump(pTable table) {
	if (table) {
		int i;
		for (i = 0; i < TABLESIZE; i++) {
			List list = table->TheList[i];
			while (list) {
				printf("node:%s\n", list->Elem);
				list = list->Next;
			}
		}
	}

}

