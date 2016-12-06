#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 24
#define DEFAULT_SIZE 8

typedef enum type {
    TYPE_INT = 0,
	TYPE_PAIR,
} Type;

typedef struct object {
   Type type;

   union {
       struct {
            struct object* lchild;
			struct object* rchild;
       };
       int val;
   }ele;

   int marked;
   struct object* next;
}Object, *pObject;

typedef struct vm {
   int capacity;
   int count;

   pObject* objects;
   pObject root;
} VM, *pVM;

static void assert(int cond, const char* msg) {
    if (!cond) {
        printf("%s\n", msg);
		exit(-1);
	}
}

static pObject alloc(Type type) {
    pObject obj = (pObject)malloc(sizeof(Object));
	assert((obj != NULL), "no space for object");

	obj->marked = 0;
	obj->type = type;
	obj->next = NULL;
	
	return obj;
}

static void destroy(pObject obj) {
    if (obj)
		free(obj);
}

pObject pop(pVM vm) {
    if (vm->count == 0)
		return NULL;

	return vm->objects[--vm->count];
}

void push(pVM vm, int val) {
    if (vm->count >= vm->capacity) {
		printf("full\n");
		return;
	}

	pObject obj = alloc(TYPE_INT);
	obj->ele.val = val;
	if (vm->root == NULL) {
		vm->root = obj;
	} else {
		obj->next = vm->root->next;
		vm->root->next = obj;
	}

	vm->objects[vm->count++] = obj;
}

void push_pair(pVM vm) {
    pObject obj = alloc(TYPE_PAIR);
	obj->ele.lchild = pop(vm);
	obj->ele.rchild = pop(vm);

    vm->objects[vm->count++] = obj;
}

pVM init(int maxsize) {
    if (maxsize > MAX_SIZE)
		maxsize = MAX_SIZE;

	pVM vm = (pVM)malloc(sizeof(VM));
	assert((vm != NULL), "no space for VM");

	vm->capacity = maxsize;
	vm->count = 0;

	vm->objects = (pObject)malloc(sizeof(pObject) * vm->capacity);
	assert((vm->objects != NULL), "no space for objects");

    vm->root = NULL;
	
	return vm;
}

void freeAll(pVM vm) {
    if (vm) {
        pObject obj = vm->root;
        pObject tmp = NULL;
		while (obj) {
            tmp = obj;
			obj = obj->next;

			free(tmp);
		}

		free(vm);
	}
}

void mark(pObject obj) {
    if (obj && !obj->marked) {
        if (obj->type == TYPE_INT) {
           obj->marked = 1;
        } else {
           if (obj->ele.lchild)
              mark(obj->ele.lchild);
           if (obj->ele.rchild)
              mark(obj->ele.rchild);
        }
	}
}

void markAll(pVM vm) {
    int i;
	for (i = 0; i < vm->count; i++) {
        mark(vm->objects[i]);
	}
}

void sweep(pVM vm) {
    pObject* obj = &(vm->root);
    pObject tmp = NULL;
	while (*obj) {
        if ((*obj)->marked) {
             tmp = *obj;
			 *obj = (*obj)->next;

			 free(tmp);
			 vm->count--;
		} else {
           (*obj)->marked = 0;
		   (*obj) = (*obj)->next;
		}
	}
}

void markAndSweep(pVM vm) {
    markAll(vm);
	sweep(vm);
}

void show(pVM vm) {
    if (vm) {
        pObject obj = vm->root;
        pObject tmp = NULL;
		while (obj) {
            tmp = obj;
			obj = obj->next;
			
            if (tmp ->type == TYPE_INT)
				printf("val:%d\n", tmp->ele.val);
			else
				printf("obj:%d\n", (int)tmp->type);
		}
	}
}

int main() {
   pVM vm = init(DEFAULT_SIZE);
   
   push(vm, 3);
   push(vm, 2);
   push(vm, 21);
   push_pair(vm);
   push(vm, 7);

   printf("before sweep\n");
   show(vm);
   markAndSweep(vm);

   printf("after sweep\n");
   show(vm);

   freeAll(vm);

   return 0;
}
