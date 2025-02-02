#include <stdlib.h>

#include "queue.h"

int enqueue(queue_t *const q, const int type, const int precedence, const union elem e)
{
        struct node *new = new_node(type, precedence, e);

        if (new == NULL)
                return 0;

        q->tail->next = new;
        q->tail = new;

        if (q->head == NULL)
                q->head = new;

        return 1;
}

union elem dequeue(queue_t *const q)
{
        struct node n = *(q->head);

        free_node(&(q->head));
        q->head = n.next;

        if (q->head == NULL)
                q->tail = NULL;

        return n.e;
}

int empty_queue(const queue_t q)
{
        return q.head == NULL;
}
