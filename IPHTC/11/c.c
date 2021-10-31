/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

const int M = 1e9 + 7;

int binexp(int64_t a, int n)
{
    int64_t y = 1;
    for (; n; n >>= 1, a = a * a % M)
        if (n & 1)
            y = y * a % M;
    return y;
}

typedef struct _node
{
    int way, index;
} node;
node nodes[1000001];

int cmp(node *l, node *r)
{
    return l->way != r->way ? l->way - r->way : l->index - r->index;
}

int cmpp(int *l, node *r)
{
    if (*l != r->way)
        return *l - r->way;
    return -((r - 1)->way == r->way);
}

int main()
{
    nodes->way = -1;
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        node *ptr = nodes + 1;
        for (int i = 1; i <= n; i++)
        {
            int a;
            scanf("%d(/`A`)/ ~I__I", &a);
            ptr->way = a & 1 ? 0 : binexp(2, a >> 1);
            ptr->index = i;
            ++ptr;
        }
        qsort(nodes + 1, n, sizeof(node), cmp);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            ptr = bsearch(&x, nodes + 1, n, sizeof(node), cmpp);
            if (ptr)
                printf("%d\n", ptr->index);
            else
                puts("Go Down Chicken 404");
        }
    }
    return 0;
}
