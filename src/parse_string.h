#ifndef SRC_PARSE_STRING_H_
#define SRC_PARSE_STRING_H_

#include "list.h"
#include "token.h"

struct node* parse(char *str);
double parse_number(char *str, int *shift);
void fill_token(struct token *node, enum TYPE type, double value, enum OPERATOR o, int priority);

#endif  //  SRC_PARSE_STRING_H_
