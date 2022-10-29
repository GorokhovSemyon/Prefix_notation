#include <stdlib.h>
#include <stdio.h>

#include "list.h"

struct node *init_node(struct token data) {
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;

    return node;
}

struct node *add_node(struct node *root, struct token data) {
    struct node *proot = root;

    for (; proot->next != NULL; proot = proot->next) {}
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->next = proot->next;
    proot->next = node;
    return node;
}

void destroy_node(struct node *root) {
    struct node* tmp;

    while (root != NULL) {
        tmp = root->next;
        free(root);
        root = tmp;
    }
}
