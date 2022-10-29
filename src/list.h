#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include "token.h"

struct node {
    struct token data;
    struct node *next;
};

struct node *init_node(struct token data);
struct node *add_node(struct node* root, struct token data);
struct node *remove_node(struct node* root);
void destroy_node();

#endif  //  SRC_LIST_H_
