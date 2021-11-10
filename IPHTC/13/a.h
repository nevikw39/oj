#include <stdlib.h>
#include <time.h>

typedef struct _treap
{
    struct _treap *l, *r;
    int pri, key;
} treap;

treap *merge(treap *a, treap *b)
{
    if (!a || !b)
        return a ?: b;
    if (a->pri > b->pri)
    {
        a->r = merge(a->r, b);
        return a;
    }
    b->l = merge(a, b->l);
    return b;
}

void split(treap *t, int k, treap **a, treap **b)
{
    if (!t)
        *a = *b = NULL;
    else if (t->key <= k)
    {
        *a = t;
        split(t->r, k, &((*a)->r), b);
    }
    else
    {
        *b = t;
        split(t->l, k, a, &((*b)->l));
    }
}

treap *deleteTreap(treap *t)
{
    if (!t)
        return NULL;
    treap *tmp = merge(t->l, t->r);
    free(t);
    return tmp;
}

treap *newTreap(int k)
{
    treap *t = malloc(sizeof(treap));
    t->l = t->r = NULL;
    t->pri = rand();
    t->key = k;
    return t;
}

treap *insert(treap *t, int k)
{
    treap *a = NULL, *b = NULL;
    split(t, k, &a, &b);
    return merge(merge(a, newTreap(k)), b);
}

treap *root;

void build_tree(Node **_, int *arr, int l, int r)
{
    srand(time(NULL));
    root = NULL;
    for (int i = l; i <= r; i++)
        root = insert(root, arr[i]);
}

int query_heatstroke(Node *now, int x)
{
    treap *a, *b;
    split(root, x - 1, &a, &root);
    split(root, x, &root, &b);
    int y = root && root->key == x;
    root = merge(a, merge(root, b));
    return y;
}

void eat_rat(Node **_, int x)
{
    treap *a, *b, *c;
    split(root, x - 1, &a, &b);
    split(b, x, &b, &c);
    root = merge(a, merge(deleteTreap(b), c));
}

void buy_rat(Node **_, int x)
{
    root = insert(root, x);
}
