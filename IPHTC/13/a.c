typedef struct _NODE
{
    int level;
    struct _NODE *left_child, *right_child;
} Node;

#include "a.h"
#include <stdio.h>
#include <string.h>
#define MAX_N 10004

int n, q;
int a[MAX_N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    Node *root = NULL;
    build_tree(&root, a, 0, n - 1);
    scanf("%d", &q);
    char op[20];
    while (q--)
    {
        int x;
        scanf("%s", op);
        scanf("%d", &x);
        if (strcmp(op, "heatstroke") == 0)
        {
            if (query_heatstroke(root, x) != 0)
            {
                puts("We might as well eat it.");
                eat_rat(&root, x);
            }
            else
                puts("No dinner tonight.");
        }
        else if (strcmp(op, "buy") == 0)
        {
            buy_rat(&root, x);
        }
    }
    return 0;
}
