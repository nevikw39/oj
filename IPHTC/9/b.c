#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int val;
    struct _node *l, *r;
} node;

int n, pre[10], post[10], i, cnt;

node *build(int l, int r)
{
    if (i >= n || l > r)
        return NULL;
    node *root = malloc(sizeof(node));
    root->val = pre[i];
    root->l = root->r = NULL;
    int mid = i++;
    while (mid < n && pre[mid] != post[r - 1])
        ++mid;
    if (mid < n)
    {
        int x = l + mid - i;
        root->l = build(l, x);
        root->r = build(x + 1, r - 1);
    }
    if (root->l != NULL ^ root->r != NULL)
        ++cnt;
    return root;
}

int main()
{
    while (~scanf("%d", &n))
    {
        i = cnt = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", pre + i);
        for (int i = 0; i < n; i++)
            scanf("%d", post + i);
        build(0, n - 1);
        printf("%d\n", 1 << cnt);
    }
    return 0;
}
