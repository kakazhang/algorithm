#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#include "ringbuffer.h"

#define CACHELINE 32 * 1024
#define TEST_SIZE 1024 * CACHELINE
#define LOOP 50
double getdetlatimeofday(struct timeval *begin, struct timeval *end)
{
    return (end->tv_sec + end->tv_usec * 1.0 / 1000000) -
        (begin->tv_sec + begin->tv_usec * 1.0 / 1000000);
}

void do_consume(ring_buffer_t rb)
{
    char buf[CACHELINE] = {0};
    uint32_t count = CACHELINE;
    uint32_t size = 0;
    int i = 0;

    uint32_t total = 0;

    while (1) {
        size = ring_buffer_read(rb, buf, count);
        if (size > 0) {
            total += size;
            //printf("consumer read:%s\n", buf);
            if (total == rb->size) {
                i++;
                total = 0;
            }
        } else {
            i++;
            //usleep(1000);
        }
        if (i == LOOP) break;
    }

}

void do_product(ring_buffer_t rb)
{
    char msg[CACHELINE] = {"hello, ring buffer test"};
    uint32_t count = CACHELINE;
    uint32_t ret = 0;
    int i = 0;

    uint32_t total = 0;

    while (1) {
        ret = ring_buffer_write(rb, (void *)msg, count);
        if (ret > 0) {
           //printf("consumer write success\n");
           total += ret;
           if (total == rb->size) {
               i++;
               total = 0;
           }
        } else if (ret == 0) {
            //usleep(1000);
        }
        if (i == LOOP) break;
    }
}

void* consumer(void *args)
{
    ring_buffer_t rb = (ring_buffer_t)args;
    do_consume(rb);
    return NULL;
}

void *producer(void *args)
{
    struct timeval begin, end;
    ring_buffer_t rb = (ring_buffer_t )args;
    gettimeofday(&begin, NULL);
    do_product(rb);
    gettimeofday(&end, NULL);

    double tm = getdetlatimeofday(&begin, &end);

    int count = 1;
    printf("%f MB/s %fmsg/s %f\n",
            count * rb->size * 1.0 / (tm * 1024 * 1024),
            count * 1.0 / tm, tm);
    return NULL;
}

int main(int argc, char** argv)
{
#ifndef USE_SHM
    pthread_t t1, t2;

    ring_buffer_t rb = ring_buffer_create(TEST_SIZE);
    printf("head:%d, tail:%d, size:%d\n", rb->head, rb->tail, rb->size);
    pthread_create(&t1, NULL, producer, rb);
    pthread_create(&t2, NULL, consumer, rb);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
#else
    uint32_t size = atoi(argv[1]);
    int pid = fork();
    if (pid == 0) {
        ring_buffer_t rb = ring_buffer_create(50*size);
        do_consume(rb);
    } else {
        struct timeval begin, end;
        ring_buffer_t rb = ring_buffer_create(50*size);
        gettimeofday(&begin, NULL);
        do_product(rb);
        gettimeofday(&end, NULL);
        double tm = getdetlatimeofday(&begin, &end);
        printf("%f MB/s %fmsg/s %f\n",
            LOOP * rb->size * 1.0 / (tm * 1024 * 1024),
            LOOP * 1.0 / tm, tm);
    }

    while(1) sleep(1);
#endif
    return 0;
}
