/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int *a, *b;

int cmp(const int *l, const int *r)
{
    if (a[*l] - b[*l] > a[*r] - b[*r])
        return 1;
    if (a[*l] - b[*l] == a[*r] - b[*r])
        return -1;
    return 0;
}

int static inline min(int x, int y)
{
    return y ^ ((x ^ y) & -(x < y));
}

int main()
{
    int n, k, *arr;
    scanf("%d%d", &n, &k);
    a = malloc(sizeof(int) * n);
    b = malloc(sizeof(int) * n);
    arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);
    for (int i = 0; i < n; i++)
        i[arr] = i;
    qsort(arr, n, sizeof(int), cmp);
    int64_t s = 0;
    for (int i = 0; i < k; i++)
        s += a[arr[i]];
    for (int i = k; i < n; i++)
        s += min(a[arr[i]], b[arr[i]]);
    printf("%" PRId64 "\n", s);
    free(a);
    free(b);
    free(arr);
    return 0;
}