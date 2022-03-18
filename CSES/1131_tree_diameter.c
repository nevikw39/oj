/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

#define N 200002

typedef struct _edge
{
    int v;
    struct _edge *next;
} edge;
edge *head[N];

void update(int *ptr, int x)
{
    if (*ptr < x)
        *ptr = x;
}

int *dfs(int u, int p)
{
    int *arr = (int *)malloc(sizeof(int) << 1);
    arr[0] = 0;
    arr[1] = 0;
    for (edge *ptr = head[u]; ptr; ptr = ptr->next)
    {
        if (ptr->v == p)
            continue;
        int *brr = dfs(ptr->v, u);
        update(arr, brr[0]);
        update(arr, arr[1] + 1 + brr[1]);
        update(arr + 1, 1 + brr[1]);
        free(brr);
    }
    return arr;
}

void free_list(edge *ptr)
{
    if (!ptr)
        return;
    free_list(ptr->next);
    free(ptr);
}

edge *new_adge(int v, edge *next)
{
    edge *y = (edge *)malloc(sizeof(edge));
    *y = (edge){.v = v, .next = next};
    return y;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        head[i] = NULL;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        head[u] = new_adge(v, head[u]);
        head[v] = new_adge(u, head[v]);
    }
    printf("%d\n", dfs(0, -1)[0]);
    for (int i = 0; i < n; i++)
        free_list(head[i]);
    return 0;
}