#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

#define EMPTY_QUEUE {NULL, NULL}

typedef struct queue {
        struct node *head;
        struct node *tail;
} queue_t;

int enqueue(queue_t *q, int type, int precedence, union elem e);

union elem dequeue(queue_t *q);

int empty_queue(queue_t q);

#endif /* queue.h */
