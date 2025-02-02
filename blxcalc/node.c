#include <stdlib.h>

#include "node.h"

struct node *new_node(const int type, const int precedence, const union elem e)
{
        struct node *new = (struct node *) malloc(sizeof(struct node));

        if (new) {
                new->type = type;
                new->precedence = precedence;
                new->e =e;
                new->next = NULL;
        }

        return new;
}

void free_node(struct node **const n)
{
        free(*n);
        *n = NULL;
}
