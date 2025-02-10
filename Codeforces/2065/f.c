/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

#define N ((int)5e5 + 5)

int vertex[N << 1], next[N << 1], tail, edges[N];

void add_edge(int u, int v)
{
    vertex[tail] = v;
    next[tail] = edges[u];
    edges[u] = tail++;
}

void solve()
{
    tail = 0;
    int n;
    scanf("%d", &n);
    memset(edges, -1, sizeof(int) * n);
    int a[n], cnt[n];
    char s[n + 1];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        --a[i];
        cnt[i] = 0;
        s[i] = '0';
    }
    s[n] = 0;
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        --u;
        --v;
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 0; i < n; i++)
    {
        ++cnt[a[i]];
        for (int j = edges[i]; ~j; j = next[j])
            if (++cnt[a[vertex[j]]] == 2)
                s[a[vertex[j]]] = '1';
        for (int j = edges[i]; ~j; j = next[j])
            --cnt[a[vertex[j]]];
        --cnt[a[i]];
    }
    puts(s);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
