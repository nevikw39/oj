/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inline static max(int l, int r)
{
    return l ^ ((l ^ r) & -(l < r));
}

int f(int n, int m, int *a, int r)
{
    int mm = 0;
    for (int i = 0; i < n; i++)
        mm += max(i[a] - i / r, 0);
    return mm >= m;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, *a, r = 0;
        scanf("%d%d", &n, &m);
        a = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        for (int jump = n >> 1; jump; jump >>= 1)
            while (r + jump <= n && !f(n, m, a, r + jump))
                r += jump;
        if (r < n)
            printf("%d\n", r + 1);
        else
            puts("-1");
    }
    return 0;
}