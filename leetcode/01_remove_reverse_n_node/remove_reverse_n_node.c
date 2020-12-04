#include <stdio.h>
#include <stdlib.h>

#define N 10

struct Node {
    int val;
    struct Node *next;
};

static struct Node *head = NULL;

struct Node* alloc_new_node(int val)
{
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    if (!new_node) {
        perror("malloc");
        exit(-1);
    }
    new_node->val   = val;
    new_node->next  = NULL;

    return new_node;
}

void init_list()
{
    int i;
    for (i = 0; i < N; i++) {
        struct Node *node = alloc_new_node(i);
        if (!head)
            head = node;
        else {
            struct Node *next = head->next;
            head->next = node;
            node->next = next;
        }
    }
}

void iterate_list()
{
    struct Node* node = head;

    while (node) {
        printf("node:%d\n", node->val);
        node = node->next;
    }
}

void exit_list()
{
    struct Node *node = head;
    struct Node *tmp = NULL;
    while (node) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
}

void remove_reverse_n_node(int index) {
    struct Node** array;
    int num = 8;
    struct Node *node = head;
    int count = 0;

    array = (struct Node **)calloc(num, sizeof(struct Node **));
    while (node) {
        if (count >= num) {
            array = (struct Node **)realloc(array, num+8);
        }
        array[count++] = node;
        node = node->next;
    }

    struct Node* found = array[count-index];
    struct Node* prev  = array[count-index-1];
    struct Node* next  = array[count-index+1];

    prev->next = next;

    free(array);
}

int main() {
   init_list();

   printf("show before find\n");
   iterate_list();

   remove_reverse_n_node(3);
   printf("show after remove\n");
   iterate_list();

   exit_list();
   return 0;
}
