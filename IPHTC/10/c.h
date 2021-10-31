#include <stdlib.h>

void build_tree(Node **now, int *arr, int l, int r)
{
    if (l > r)
    {
        *now = NULL;
        return;
    }
    int mid = l + r >> 1;
    *now = malloc(sizeof(Node));
    (*now)->level = arr[mid];
    build_tree(&(*now)->left_child, arr, l, mid - 1);
    build_tree(&(*now)->right_child, arr, mid + 1, r);
}

int query_heatstroke(Node *now, int x)
{
    if (!now)
        return 0;
    if (x == now->level)
        return 1;
    if (x < now->level)
        return query_heatstroke(now->left_child, x);
    return query_heatstroke(now->right_child, x);
}

void eat_rat(Node **root, int x)
{
    if (!*root)
        return;
    if (x < (*root)->level)
    {
        eat_rat(&(*root)->left_child, x);
        return;
    }
    if (x > (*root)->level)
    {
        eat_rat(&(*root)->right_child, x);
        return;
    }
    if (!(*root)->left_child)
    {
        Node *tmp = *root;
        *root = (*root)->right_child;
        free(tmp);
        return;
    }
    if (!(*root)->right_child)
    {
        Node *tmp = *root;
        *root = (*root)->left_child;
        free(tmp);
        return;
    }
    Node *cur = (*root)->right_child;
    while (cur && cur->left_child)
        cur = cur->left_child;
    (*root)->level = cur->level;
    eat_rat(&(*root)->right_child, cur->level);
}
