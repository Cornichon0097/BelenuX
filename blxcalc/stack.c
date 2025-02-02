#include <stdlib.h>

#include "stack.h"

int push(stack_t *const s, const int type, const int precedence, const union elem e)
{
        struct node *new = new_node(type, precedence, e);

        if (new == NULL)
                return 0;

        new->next = *s;
        *s = new;

        return 1;
}

union elem pop(stack_t *const s)
{
        struct node n = **s;

        free_node(s);
        *s = n.next;

        return n.e;
}

int empty_stack(const stack_t s)
{
        return s == EMPTY_STACK;
}

union elem top(const stack_t s)
{
        return s->e;
}
