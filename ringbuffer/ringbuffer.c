#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "ringbuffer.h"

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define IS_POT(x) ((x) && !((x) & ((x)-1)))

#define DEFAULT_BUF_SIZE 0x1000
#define RB_HEADER sizeof(ring_buffer);

static uint32_t roundup_pow_of_two(uint32_t size) {
    size |= size >> 1;
    size |= size >> 2;
    size |= size >> 4;
    size |= size >> 8;
    size |= size >> 16;
    return size+1;
}

ring_buffer_t ring_buffer_create(uint32_t size)
{
    void* addr = calloc(1, size+sizeof(ring_buffer));
    ring_buffer_t rb = (ring_buffer_t)addr;
    rb->base = (void *)((char *)addr + sizeof(struct ring_buffer));
    rb->size = size;
    rb->head = 0;
    rb->tail = 0;

    return rb;
}

void ring_buffer_free(ring_buffer_t rb)
{
    if (rb) {
        free(rb);
    }
}

uint32_t ring_buffer_used(ring_buffer_t rb)
{
    uint32_t head = rb->head;
    uint32_t tail = rb->tail;

    if (tail >= head)
        return tail - head;
    else
        return rb->size - (head - tail);
}

uint32_t ring_buffer_read(ring_buffer_t rb, void* buf, uint32_t count)
{
    uint32_t size = rb->size;
    uint32_t head = rb->head;
    uint32_t tail = rb->tail;
    uint32_t used = ring_buffer_used(rb);

    if (used < count) {
        printf("no enough data(%d) for read, head(%u), tail(%u), size(%u)\n", used, head, tail, size);
        return 0;
    }

    uint32_t len = MIN(count, size - head);
    memcpy(buf, rb->base + head, len);
    if (count > len)
        memcpy(buf+len, rb->base, count-len);

    rb->head = (rb->head + count) % size;
    if (rb->head == size)
        rb->head = 0;
    return count;
}

uint32_t ring_buffer_write(ring_buffer_t rb, void* buf, uint32_t count)
{
    uint32_t size = rb->size;
    uint32_t head = rb->head;
    uint32_t tail = rb->tail;
    uint32_t used = ring_buffer_used(rb);

    if (count > (size-used)) {
        printf("No enough space to write, current size:%d\n", (size-used));
        return 0;
    }

    uint32_t len = MIN(count, size-tail);
    memcpy(rb->base+tail, buf, len);
    if (count > len)
        memcpy(rb->base, buf+len, count-len);

    rb->tail = ((rb->tail + count) % size);
    if (rb->tail == size)
        rb->tail = 0;
    return count;
}

bool ring_buffer_full(ring_buffer_t rb)
{
    return (rb->tail - rb->head) == rb->size;
}

bool ring_buffer_empty(ring_buffer_t rb)
{
    return rb->tail == rb->head;
}
