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

#define N 100000

typedef struct _edge
{
    int v, w;
    struct _edge *next;
} edge;
edge *head[N], *tail[N];

void update(int *ptr1, int *ptr2, int x)
{
    if (*ptr1 < x)
    {
        *ptr2 = *ptr1;
        *ptr1 = x;
    }
    else if (*ptr2 < x && x < *ptr1)
        *ptr2 = x;
}

int *dfs(int u, int p)
{
    int *arr = malloc(sizeof(int) << 2);
    arr[0] = arr[2] = 0;
    arr[1] = arr[3] = INT_MIN;
    for (edge *ptr = head[u]; ptr; ptr = ptr->next)
    {
        if (ptr->v == p)
            continue;
        int *brr = dfs(ptr->v, u);
        update(arr, arr + 1, brr[0]);
        update(arr, arr + 1, brr[1]);
        update(arr, arr + 1, arr[2] + ptr->w + brr[3]);
        update(arr, arr + 1, arr[2] + ptr->w + brr[2]);
        update(arr, arr + 1, arr[3] + ptr->w + brr[2]);
        update(arr + 2, arr + 3, ptr->w + brr[2]);
        update(arr + 2, arr + 3, ptr->w + brr[3]);
        free(brr);
    }
    return arr;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        tail[i] = head[i] = NULL;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (head[u] && tail[u])
        {
            tail[u] = tail[u]->next = malloc(sizeof(edge));
            *tail[u] = (edge){.v = v, .w = w, .next = NULL};
        }
        else
        {
            head[u] = tail[u] = malloc(sizeof(edge));
            *tail[u] = (edge){.v = v, .w = w, .next = NULL};
        }
        if (head[v] && tail[v])
        {
            tail[v] = tail[v]->next = malloc(sizeof(edge));
            *tail[v] = (edge){.v = u, .w = w, .next = NULL};
        }
        else
        {
            head[v] = tail[v] = malloc(sizeof(edge));
            *tail[v] = (edge){.v = u, .w = w, .next = NULL};
        }
    }
    printf("%d\n", dfs(0, -1)[1]);
    return 0;
}