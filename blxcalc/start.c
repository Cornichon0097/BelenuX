#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>

#include <blx/blx.h>

#include "node.h"
#include "stack.h"
#include "queue.h"

int precedence(const char *const op)
{
        switch (*op) {
        case '+':
                return 1;
        case '-':
                return 1;
        case '*':
                return 2;
        case '/':
                return 2;
        default:
                break;
        }

        return 0;
}

queue_t parse(char *buf)
{
        queue_t q = EMPTY_QUEUE;
        stack_t s = EMPTY_STACK;
        char *token = buf;
        union elem e;

        while (*token != '\0') {
                e.num = strtol(buf, &token, 10);

                if (token != buf)
                        enqueue(&q, NUM_TYPE, 0, e);
                else if (strchr("+-*/", *token)) {
                        while (!empty_stack(s) && (top(s).op[0] != '(')) {
                                if (s->precedence > precedence(token))
                                        enqueue(&q, OP_TYPE, s->precedence, pop(&s));
                        }

                        e.op[0] = *token;
                        e.op[1] = '\0';
                        push(&s, OP_TYPE, precedence(token), e);
                }

                buf = token;
        }

        while (!empty_stack(s))
                enqueue(&q, OP_TYPE, s->precedence, pop(&s));

        return q;
}

int main(void)
{
        char buf[BUFSIZ];
        queue_t q;

        while (fgets(buf, BUFSIZ, stdin)) {
                q = parse(buf);

                while (!empty_queue(q)) {
                        if (q.head->type == NUM_TYPE)
                                printf("%ld ", q.head->e.num);
                        else
                                printf("%s ", q.head->e.op);

                        dequeue(&q);
                }
        }

        return EXIT_SUCCESS;
}
