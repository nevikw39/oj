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

int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

int64_t *S;

int cmp(const int *const restrict l, const int *const restrict r) { return S[*l] < S[*r] ?: S[*l] == S[*r] ? 0 : -1; }

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n * m], p[n];
    int64_t s[n], sum = 0, ps = 0;
    S = s;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        s[i] = 0;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", a + i * m + j);
            s[i] += a[i * m + j];
        }
    }
    qsort(p, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum += (ps += a[p[i] * m + j]);
    printf("%" PRId64 "\n", sum);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
