#ifndef RING_BUFFER_H
#define RING_BUFFER_H

typedef unsigned int uint32_t;
typedef unsigned char bool;

typedef struct ring_buffer {
    void *base;
    uint32_t size;
    volatile uint32_t head;
    volatile uint32_t tail;
} ring_buffer, *ring_buffer_t;

ring_buffer_t ring_buffer_create(uint32_t size);

void ring_buffer_free(ring_buffer_t rb);

uint32_t ring_buffer_read(ring_buffer_t rb, void* buf, uint32_t count);

uint32_t ring_buffer_write(ring_buffer_t rb, void* buf, uint32_t count);

bool ring_buffer_full(ring_buffer_t rb);

bool ring_buffer_empty(ring_buffer_t rb);
#endif
