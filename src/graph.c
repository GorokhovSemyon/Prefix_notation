#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "polsk_calculate.h"
#include "parse_string.h"
#include "stack.h"
#include "list.h"
#include "token.h"
#include "io_standart_polsk.h"

void print(struct token *token);
void print_str(char *str);
void fill_string();
struct node* parse(char *str);
double parse_number(char *str, int *shift);
void draw(char matrix[][80], struct node* root);

int main() {
    fill_string();

    return 0;
}

void fill_string() {
    char matrix[25][80];
    char str[101];
    scanf("%100s", str);
    struct node *start = parse(str);
    start = io_standart_polsk(start);
    draw(matrix, start);

    destroy_node(start);
}

void draw(char matrix[][80], struct node* root) {
  for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 80; j++) {
          matrix[i][j] = '.';
      }
  }

  double x, y;
    for (int i = 0; i < 25; i++) {
      for (int j = 0 ; j < 80; j++) {
        x = j * M_PI / 20;
        y = polsk_calculate(root, x);
          if (fabs(i - 12 * ( 1 + y) ) < fabs((i + 1) - 12 * (1 + y)) &&
          fabs(i - 12 *  (1 + y)) < fabs((i - 1) - 12 * (1 + y)) &&
          fabs(x * 20 / M_PI - j) < fabs(x * 20 / M_PI - j + 1) &&
          fabs(x * 20 / M_PI - j) < fabs(x * 20 / M_PI - j - 1)) {
            matrix[i][j] = '*';
          }
      }
    }

    for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 80; j++) {
        printf("%c", matrix[i][j]);
      }
      printf("\n");
    }
}
