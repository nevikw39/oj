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
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        int *arr = malloc(sizeof(int) * (n + 1));
        for (int *ptr = arr + 1; ptr <= arr + n; ptr++)
            scanf("%d", ptr);
        while (q--)
        {
            int a, r = 0;
            scanf("%d", &a);
            for (int jump = n >> 1; jump; jump >>= 1)
                while (r + jump <= n && arr[r + jump] < a)
                    r += jump;
            if (r + 1 > n || arr[r + 1] != a)
                puts("Break your bridge!");
            else
                printf("%d\n", r + 1);
        }
        free(arr);
    }
    return 0;
}
