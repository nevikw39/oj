/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
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
    int n, k, *arr, x = 0, p = 0;
    scanf("%d%d", &n, &k);
    arr = malloc(sizeof(int) * (n + 1));
    *arr = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", arr + i);
    while (arr[x] + k < arr[n])
    {
        int y = x;
        for (int jump = n >> 1; jump; jump >>= 1)
            while (y + jump < n && arr[y + jump] <= x[arr] + k)
                y += jump;
        if (x == y)
        {
            puts("The Legend Falls.");
            return 0;
        }
        x = y;
        ++p;
    }
    printf("%d\n", p);
    free(arr);
    return 0;
}