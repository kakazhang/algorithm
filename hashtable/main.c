#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

#include "hash.h"
#define COUNT 1024

typedef struct action {
	pTable table;
	char name[64];
} Action, *pAction;

long getime() {
	struct timeval tv;

	gettimeofday(&tv, NULL);

	return tv.tv_sec * 1000000 + tv.tv_usec;
}

void* insert_routine(void *args) {
	int i;
	char buf[64];
	pAction action = (pAction)args;
	pTable table = action->table;

	long s = getime();
	for (i = 0; i < COUNT; i++) {
		sprintf(buf, "%s%d", action->name, i);
		Insert(buf, table);
	}
	printf("thread %s cost:%ld us\n", action->name, getime()-s);
	
	free(action);

	return NULL;
}

#define THREADS 4
int main() {
	pTable table = initialize();
	pthread_t threads[THREADS];
	char *names[THREADS] = {"Kaka", "Messi", "CRonaldo", "Rooney"};
	int i;
	
	for (i = 0; i < THREADS; i++) {
		pAction action = (pAction)malloc(sizeof(Action));
		memset(action->name, 0, 64);
		strcpy(action->name, names[i]);
		action->table = table;
		pthread_create(&threads[i], NULL, insert_routine, action);
	}

	for (i = 0; i < THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	
	//dump(table);
	destroy(table);
	return 0;
}
