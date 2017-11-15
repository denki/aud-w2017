#include <stdio.h>

void swapCool(int* a, int* b) {
  if (*a % 2 != 0) (*b)++;

  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void swap(int* a, int* b) {
  int tmp;

  if (*a % 2 != 0) (*b)++;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int a, b;
  a = 1;
  b = 2;

  printf("%d, %d\n", a, b);

  swapCool(&a, &b);

  printf("%d, %d\n", a, b);
}
