#include<stdio.h>

int main() {
  int n, i, acc;

  printf("n = ");
  scanf("%u", &n);

  acc = 1;

  for (i = 1; i <=n; ++i)
    acc = acc * i;

  printf("%u! = %u\n", n, acc);

  return 0;
}
