#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

#include "ringbuffer.h"

//#define TEST_SIZE 1024 * CACHELINE
#define LOOP 100
double getdetlatimeofday(struct timeval *begin, struct timeval *end)
{
    return (end->tv_sec + end->tv_usec * 1.0 / 1000000) -
        (begin->tv_sec + begin->tv_usec * 1.0 / 1000000);
}

#ifdef TRANSFER_FILE
uint32_t get_file_size(const char* path)
{
    struct stat st;
    if (!stat(path, &st))
        return st.st_size;
    return 0;
}

void* get_file_map_addr(const char* path, uint32_t size)
{
    void *addr = NULL;
    int fd = open(path, O_RDWR);
    if (fd > 0) {
        addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
        if (addr == MAP_FAILED)
            addr = NULL;
        close(fd);
    }

    return addr;
}

void do_consume(ring_buffer_t rb)
{
    char buf[CACHELINE] = {0};
    uint32_t size = get_file_size("./ddr.mp4");
    int fd = open("./dst/a.mp4", O_CREAT|O_RDWR);

    uint32_t ret, i, count;
    i = 0;

    printf("consume get file size:%d\n", size);
    while (i < size) {
        count = MIN(CACHELINE, size-i);
        ret = ring_buffer_read(rb, buf, count);
        if (ret > 0) {
            i += count;
            //ret = write(fd, buf, ret);
            //if (ret < 0)
            //    perror("write");
        }
    }
    printf("read finish, i=%d\n", i);
    sync();
    close(fd);
}

void do_product(ring_buffer_t rb)
{
    uint32_t size = get_file_size("./ddr.mp4");
    void* addr = get_file_map_addr("./ddr.mp4", size);
    uint32_t i, count;
    uint32_t ret = 0;
    i = 0;

    printf("ddr.mp4 size:%d\n", size);
    while (i < size) {
        count = MIN(CACHELINE, size-i);
        ret = ring_buffer_write(rb, addr+i, count);
        if (ret > 0) i += ret;
    }
    printf("write finished,i=%d\n", i);
    munmap(addr, size);
}
#else
void do_consume(ring_buffer_t rb)
{
    char buf[CACHELINE] = {0};
    uint32_t count = CACHELINE;
    uint32_t size = 0;
#ifdef CALC_SPEED
    int i = 0;
    uint32_t total = 0;
#endif

    while (1) {
        size = ring_buffer_read(rb, buf, count);
        if (size > 0) {
#ifdef CALC_SPEED
#endif
        } else {
            //usleep(1000);
        }
#ifdef CALC_SPEED
        if (i == LOOP)
            break;
#endif
    }

}

void do_product(ring_buffer_t rb)
{
    char msg[CACHELINE] = {"hello, ring buffer test"};
    uint32_t count = CACHELINE;
    uint32_t ret = 0;
#ifdef CALC_SPEED
    int i = 0;
    uint32_t total = 0;
#endif

    while (1) {
        ret = ring_buffer_write(rb, (void *)msg, count);
        if (ret > 0) {
           //printf("consumer write success\n");
#ifdef CALC_SPEED
           total += ret;
           if (total == rb->size) {
               i++;
               total = 0;
           }
#endif
        } else if (ret == 0) {
            //usleep(1000);
        }
#ifdef CALC_SPEED
        if (i == LOOP)
            break;
#endif
    }
}
#endif

void* consumer(void *args)
{
    ring_buffer_t rb = (ring_buffer_t)args;
    do_consume(rb);
    return NULL;
}

void *producer(void *args)
{
    ring_buffer_t rb = (ring_buffer_t )args;
#ifdef CALC_SPEED
    struct timeval begin, end;
    gettimeofday(&begin, NULL);
#endif

    do_product(rb);

#ifdef CALC_SPEED
    gettimeofday(&end, NULL);
    double tm = getdetlatimeofday(&begin, &end);

    int count = 1;
    printf("%f MB/s %fmsg/s %f\n",
            count * rb->size * 1.0 / (tm * 1024 * 1024),
            count * 1.0 / tm, tm);
#endif
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
        ring_buffer_t rb = ring_buffer_create(50*size);
#ifdef CALC_SPEED
        struct timeval begin, end;

        gettimeofday(&begin, NULL);
#endif
        do_product(rb);
#ifdef CALC_SPEED
        gettimeofday(&end, NULL);
        double tm = getdetlatimeofday(&begin, &end);
        printf("%f MB/s %fmsg/s %f\n",
            LOOP * rb->size * 1.0 / (tm * 1024 * 1024),
            LOOP * 1.0 / tm, tm);
#endif
    }

    while(1) sleep(1);
#endif
    return 0;
}
