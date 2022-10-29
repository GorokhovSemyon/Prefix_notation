#include <stdlib.h>

#include "stack.h"
#include "token.h"

struct stack *init_stack() {
    struct stack *head = malloc(sizeof(struct stack));
    head->size = 0;
    head->next = NULL;

    return head;
}

struct stack *push(struct stack *root, struct token data) {
    struct stack *new_stack = malloc(sizeof(struct stack));
    new_stack->data = data;
    new_stack->next = root;
    new_stack->size = root->size + 1;

    return new_stack;
}

struct stack *pop(struct stack *root) {
    struct stack *tmp = root->next;
    tmp->size = root->size - 1;
    free(root);

    return tmp;
}

void destroy_stack(struct stack *root) {
    struct stack* tmp;

    while (root != NULL) {
        tmp = root->next;
        free(root);
        root = tmp;
    }
}

struct stack_double *init_stack_d() {
    struct stack_double *head = malloc(sizeof(struct stack_double));
    head->size = 0;
    head->next = NULL;

    return head;
}

struct stack_double *push_d(struct stack_double *root, double data) {
    struct stack_double *new_stack = malloc(sizeof(struct stack_double));
    new_stack->data = data;
    new_stack->next = root;
    new_stack->size = root->size + 1;

    return new_stack;
}

struct stack_double *pop_d(struct stack_double *root) {
    struct stack_double *tmp = root->next;
    tmp->size = root->size - 1;
    free(root);

    return tmp;
}

void destroy_stack_d(struct stack_double *root) {
    struct stack_double* tmp;

    while (root != NULL) {
        tmp = root->next;
        free(root);
        root = tmp;
    }
}
