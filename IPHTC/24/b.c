/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
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

static inline void swap(int *l, int *r) { *l ^= *r ^= *l ^= *r; }

int find(int *p, int x) { return p[x] != x ? p[x] = find(p, p[x]) : x; }

void unite(int *p, int *g, int *r, int x, int y)
{
    x = find(p, x);
    y = find(p, y);
    if (x == y)
        return;
    --*g;
    if (r[x] < r[y])
        swap(&x, &y);
    p[y] = x;
    if (r[x] == r[y])
        ++r[x];
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n][26], p[n], g = n, r[n];
        for (int i = 0; i < n; i++)
            p[i] = i;
        memset(r, 0, sizeof(int) * n);
        memset(arr, 0, sizeof(int) * n * 26);
        for (int i = 0; i < n; i++)
        {
            char str[1001];
            scanf("%s", str);
            for (char *ptr = str; *ptr; ptr++)
                ++arr[i][*ptr - 'a'];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 26; k++)
                    if (arr[i][k] && arr[j][k])
                    {
                        unite(p, &g, r, i, j);
                        break;
                    }
        printf("%d\n", g);
    }
    return 0;
}
