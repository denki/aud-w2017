#include<stdio.h>

int main() {
  int i, j, n;

  printf("n = ");
  scanf("%u", &n);

  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j)
      printf("%u\t", i * j);
    printf("\n");
  }

  return 0;
}
