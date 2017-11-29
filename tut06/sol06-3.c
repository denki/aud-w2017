#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree;
typedef struct node { int key; tree left, right; } node;

tree cons(int v, tree left, tree right) {
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

int count(int key, tree t) {
  if (!t) return 0;
  if (key == t->key)
    return 1 + count(key, t->left) + count(key, t->right);
  else
    return     count(key, t->left) + count(key, t->right);
}

tree baz(tree s, tree t) {
  if (!s) return NULL;
  return cons(count(s->key, t), baz(s->left, t), baz(s->right, t));
}

int leafprod(tree t) {
  if (!t) return 1;
  return t->key * leafprod(t->left) * leafprod(t->right);
}

int main() {
  tree s = cons(2,
                cons(3,
                     cons(2, NULL, NULL),
                     cons(4, NULL, NULL)
                     ),
                cons(1, NULL, NULL)
                );
  tree t = cons(2,
                cons(2, NULL, NULL),
                cons(3, NULL, NULL)
                );

  print_tree(s); printf("\n");
  print_tree(baz(s, t)); printf("\n");
  printf("leafprod(s) = %d\n", leafprod(s));
  return 0;
}
