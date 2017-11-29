#include <stdio.h>
#include <stdlib.h>

// Lösung zu Aufgabe a
typedef struct element *list;
typedef struct element { int value; list next; } element;

list cons(int v, list l) {
  list l1 = malloc(sizeof(*l));
  l1->value =v;
  l1->next = l;   // (*l1).next = l;
  return l1;
}

void printList(list l) {
  printf("[");
  while (l) {
    printf("%d", l->value);
    if (l->next) printf(", ");
    l = l->next;
  }
  printf("]\n");
}

int f(list l) {
  if (!l) return 1;
  int prev = l->value;
  l = l->next;

  while (l) {
    if (l->value - prev > 1 || l->value - prev < -1)
      return 0;
    prev = l->value;
    l = l->next;
  }

  return 1;
}

void test_a() {
  list l_true = cons(1, cons(2, cons(1, NULL)));
  list l_false = cons(1, cons(2, cons(4, NULL)));

  printf("l_true = ");
  printList(l_true);
  printf("f(l_true) = %d\n", f(l_true));

  printf("l_false = ");
  printList(l_false);
  printf("f(l_false) = %d\n", f(l_false));
}


// Lösung zu Aufgabe b
typedef struct node *tree;
typedef struct node { int key; tree left, right; } node;

tree cons_t(int v, tree left, tree right) {
  tree res = malloc(sizeof(node));
  res->key = v;
  res->left = left;
  res->right = right;

  return res;
}

void print_tree(tree t) {
  if (!t) {
    printf("NULL");
  } else {
    printf("%d(", t->key);
    print_tree(t->left);
    printf(", ");
    print_tree(t->right);
    printf(")");
  }
}

void defol(tree* p) {
  if (!p || !*p) return;
  if (!(*p)->left && !(*p)->right){
    free(*p);
    *p = NULL;
  } else {
    defol(&(*p)->left);
    defol(&(*p)->right);
  }
}

void test_b() {
  tree s = cons_t(2,
                cons_t(3,
                     cons_t(2, NULL, NULL),
                     cons_t(4, NULL, NULL)
                     ),
                cons_t(1, NULL, NULL)
                );

  print_tree(s); printf("\n");
  defol(&s);
  print_tree(s); printf("\n");
}


int main() {
  test_a();
  test_b();

  return 0;
}
