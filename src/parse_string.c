#include "parse_string.h"
#include "token.h"
#include "list.h"

#include <stdlib.h>
#include <string.h>

struct node* parse(char *str) {
    struct token node = {START, 0, NOTHING, 0};
    struct node *start = init_node(node);

    int shift;
    char *start_str = str;
    while (*start_str) {
        shift = 0;
        switch (*start_str) {
            case '+':
                fill_token(&node, OPERATOR, 0, PLUS, 2);
                add_node(start, node);
                break;
            case '-':
                fill_token(&node, OPERATOR, 0, MINUS, 2);
                add_node(start, node);
                break;
            case '*':
                fill_token(&node, OPERATOR, 0, MULTI, 3);
                add_node(start, node);
                break;
            case '/':
                fill_token(&node, OPERATOR, 0, DIV, 3);
                add_node(start, node);
                break;
            case '(':
                fill_token(&node, OPERATOR, 0, OPAREN, 1);
                add_node(start, node);
                break;
            case ')':
                fill_token(&node, OPERATOR, 0, IPAREN, 1);
                add_node(start, node);
                break;
        }
        if (*start_str >= '0' && *start_str <= '9') {
            node.type = NUMBER;
            fill_token(&node, NUMBER, parse_number(start_str, &shift), NOTHING, 0);
            add_node(start, node);
        } else if (*start_str == 's') {
            if (strncmp(start_str, "sin", 3) == 0) {
                shift = 2;
                fill_token(&node, OPERATOR, 0, SIN, 4);
                add_node(start, node);
            } else if (strncmp(start_str, "sqrt", 4) == 0) {
                shift = 3;
                fill_token(&node, OPERATOR, 0, SQRT, 4);
                add_node(start, node);
            }
        } else if (*start_str == 'c') {
            if (strncmp(start_str, "cos", 3) == 0) {
                shift = 2;
                fill_token(&node, OPERATOR, 0, COS, 4);
                add_node(start, node);
            } else if (strncmp(start_str, "ctg", 3) == 0) {
                shift = 2;
                fill_token(&node, OPERATOR, 0, CTG, 4);
                add_node(start, node);
            }
        } else if (*start_str == 't') {
            if (strncmp(start_str, "tan", 3) == 0) {
                shift = 2;
                fill_token(&node, OPERATOR, 0, TAN, 4);
                add_node(start, node);
            }
        } else if (*start_str == 'l') {
            if (strncmp(start_str, "ln", 2) == 0) {
                shift = 1;
                fill_token(&node, OPERATOR, 0, LN, 2);
                add_node(start, node);
            }
        } else if (*start_str == 'x') {
            fill_token(&node, VARIABLE, 0, NOTHING, 0);
            add_node(start, node);
        }
        start_str += shift + 1;
    }

    return start;
}

double parse_number(char *str, int *shift) {
    double number = 0;
    char *end_str = str;
    for (; *end_str >= '0' && *end_str <= '9'; end_str++, (*shift)++) {}
    char temp = *end_str;
    *end_str = '\0';
    number = atof(str);
    *end_str = temp;
    (*shift) -= 1;

    return number;
}

void fill_token(struct token *node, enum TYPE type, double value, enum OPERATOR o, int priority) {
    node->type = type;
    node->value = value;
    node->operator = o;
    node->priority = priority;
}
