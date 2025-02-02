#ifndef NODE_H
#define NODE_H

#define NUM_TYPE 0
#define OP_TYPE  1
#define FUN_TYPE  1

union elem {
        long num;
        char op[8];
};

struct node {
        int type;
        int precedence;
        union elem e;
        struct node *next;
};

struct node *new_node(int type, int precedence, union elem e);

void free_node(struct node **n);

#endif /* node.h */
