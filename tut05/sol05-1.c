#include <stdio.h>

int fib1(int f1, int f2, int i, int n) {
  if (i == n) return f1 + f2;
  return fib1(f2, f1 + f2, i + 1, n);
}

int fib(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib1(0, 1, 2, n);
}

int g(int n) {
  if (n == 0) return 0;
  return n - g(g(n - 1));
}

int m(int);

int f(int n) {
  if (n == 0) return 1;
  return n - m(f(n - 1));
}

int m(int n) {
  if (n == 0) return 0;
  return n - f(m(n - 1));
}

int main() {
  printf("fib(%d) = %d\n", 0, fib(0));
  printf("G(%d) = %d\n", 100, g(100));
  printf("F(%d) = %d\n", 5, f(5));

  return 0;
}
