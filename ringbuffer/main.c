#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include "ringbuffer.h"

#define TEST_SIZE 24*102400

void* consumer(void *args)
{
    ring_buffer_t rb = (ring_buffer_t)args;
    char buf[128] = {0};
    uint32_t count = 24;
    uint32_t size = 0;

    while (1) {
        size = ring_buffer_read(rb, buf, count);
        if (size > 0) {
            printf("consumer read:%s\n", buf);
        } else {
            usleep(1000);
        }
    }

    return NULL;
}

void *producer(void *args)
{
    ring_buffer_t rb = (ring_buffer_t )args;
    char msg[] = {"hello, ring buffer test"};
    uint32_t count = strlen(msg)+1;

    while (1) {
        count = ring_buffer_write(rb, (void *)msg, count);
        if (count > 0) {
           //printf("consumer write success\n");
        } else if (count == 0) {
            usleep(1000);
        }
    }

    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t t1, t2;

    ring_buffer_t rb = ring_buffer_create(TEST_SIZE);
    printf("head:%d, tail:%d, size:%d\n", rb->head, rb->tail, rb->size);
    pthread_create(&t1, NULL, producer, rb);
    pthread_create(&t2, NULL, consumer, rb);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
