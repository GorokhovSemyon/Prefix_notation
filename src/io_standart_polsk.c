#include "list.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

struct node* io_standart_polsk(struct node* input) {
    struct node* tmp = input;
    struct node* result = NULL;
    struct stack* current_stack = init_stack();
    while (tmp != NULL) {
        if (tmp->data.type == NUMBER) {
            if (result == NULL) {
                result = init_node(tmp->data);
            } else {
                add_node(result, tmp->data);
            }
        }

        if (tmp->data.type == OPERATOR) {
            if (current_stack->size == 0 || tmp->data.operator == OPAREN) {
                current_stack = push(current_stack, tmp->data);
            } else if (tmp->data.priority == current_stack->data.priority) {
                current_stack = push(current_stack, tmp->data);
            } else if (tmp->data.operator == IPAREN) {
                while (current_stack->size > 0 && current_stack->data.operator != OPAREN) {
                    add_node(result, current_stack->data);
                    current_stack = pop(current_stack);
                }
                current_stack = pop(current_stack);
            } else {
                while (current_stack->data.priority >= tmp->data.priority) {
                    add_node(result, current_stack->data);
                    current_stack = pop(current_stack);
                }
                current_stack = push(current_stack, tmp->data);
            }
        }

        if (tmp->data.type == VARIABLE) {
            if (result == NULL) {
                result = init_node(tmp->data);
            } else {
                add_node(result, tmp->data);
            }
        }
        tmp = tmp->next;
    }

    while (current_stack->size > 0) {
        add_node(result, current_stack->data);
        current_stack = pop(current_stack);
    }

    destroy_node(input);
    destroy_stack(current_stack);
    return result;
}
