#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include "token.h"

struct stack {
    struct token data;
    struct stack* next;
    int size;
};

struct stack_double {
    double data;
    struct stack_double *next;
    int size;
};

struct stack_double *init_stack_d();
struct stack_double *push_d(struct stack_double  *root, double data);
struct stack_double *pop_d(struct stack_double  *root);
void destroy_stack_d(struct stack_double *root);

struct stack *init_stack();
struct stack *push(struct stack *root, struct token data);
struct stack *pop(struct stack *root);
void destroy_stack(struct stack *root);

#endif  //  SRC_STACK_H_
