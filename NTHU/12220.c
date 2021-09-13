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
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int main()
{
    int n, k, q;
    int64_t *a;
    scanf("%d%d%d", &n, &k, &q);
    a = malloc(sizeof(int64_t) * n);
    for (int i = 0; i < n; i++)
        scanf("%" SCNd64, a + i);
    while (q--)
    {
        int64_t f;
        int i = ~0;
        scanf("%" SCNd64, &f);
        for (int jump = n >> 1; jump; jump >>= 1)
            while (i + jump < n && a[i + jump] < f)
                i += jump;
        if (i + 1 >= n)
            puts("gan ni nya sai bau");
        else if (i + 1 < k && a[i + 1] == a[k])
            puts("1");
        else
            printf("%d\n", (i + 1 - k + n) % n + 1);
    }
    free(a);
    return 0;
}