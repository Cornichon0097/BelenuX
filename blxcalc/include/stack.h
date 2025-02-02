#ifndef STACK_H
#define STACK_H

#include "node.h"

#define EMPTY_STACK NULL;

typedef struct node *stack_t;

int push(stack_t *s, int type, int precedence, union elem e);

union elem pop(stack_t *s);

int empty_stack(stack_t s);

union elem top(stack_t s);

#endif /* stack.h */
