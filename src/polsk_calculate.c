#include "list.h"
#include "stack.h"
#include "polsk_calculate.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void l_r_in_stack(double* right, double* left, struct stack_double** stack);
void r_in_stack(double* right, struct stack_double** stack);

double polsk_calculate(struct node *root, double x) {
    struct node* tmp = root;
    struct stack_double* stack = init_stack_d();

    double result = 0;
    double right = 0;
    double left = 0;
    while (tmp != NULL) {
        if (tmp->data.type == VARIABLE) {
            stack = push_d(stack, x);
        }
        if (tmp->data.type == NUMBER) {
            stack = push_d(stack, tmp->data.value);
        }
        if (tmp->data.type == OPERATOR) {
            if (tmp->data.operator == '+') {
                l_r_in_stack(&right, &left, &stack);
                stack = push_d(stack, left + right);
            }
            if (tmp->data.operator == '-') {
                l_r_in_stack(&right, &left, &stack);
                stack = push_d(stack, left - right);
            }
            if (tmp->data.operator == '*') {
                l_r_in_stack(&right, &left, &stack);
                stack = push_d(stack, left * right);
            }
            if (tmp->data.operator == '/') {
                l_r_in_stack(&right, &left, &stack);
                stack = push_d(stack, left / right);
            }
            if (tmp->data.operator == 's') {
                r_in_stack(&right, &stack);
                stack = push_d(stack, sin(right));
            }
            if (tmp->data.operator == 'q') {
                r_in_stack(&right, &stack);
                stack = push_d(stack, sqrt(right));
            }
            if (tmp->data.operator == 'c') {
                r_in_stack(&right, &stack);
                stack = push_d(stack, cos(right));
            }
            if (tmp->data.operator == 'g') {
                r_in_stack(&right, &stack);
                stack = push_d(stack, 1/(tan(right)));
            }
            if (tmp->data.operator == 't') {
                r_in_stack(&right, &stack);
                stack = push_d(stack, tan(right));
            }
            if (tmp->data.operator == 'l') {
                r_in_stack(&right, &stack);
                stack = push_d(stack, log(right));
            }
        }
        tmp = tmp->next;
    }

    result = stack->data;
    destroy_stack_d(stack);
    return result;
}

void l_r_in_stack(double* right, double* left, struct stack_double** stack) {
    *right = (*(stack))->data;
    *stack = pop_d(*stack);
    *left = (*(stack))->data;
    *stack = pop_d(*stack);
}

void r_in_stack(double* right, struct stack_double** stack) {
    *right = (*(stack))->data;
    *stack = pop_d(*stack);
}
