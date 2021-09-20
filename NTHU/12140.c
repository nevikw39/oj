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

int main()
{
    char S[1002], s[1002];
    int t, N, n, *ps;
    scanf("%s%s%d", S + 1, s + 1, &t);
    N = strlen(S + 1);
    n = strlen(s + 1);
    ps = malloc(sizeof(int) * (N - n + 2));
    *ps = 0;
    for (int i = 1; i <= N - n + 1; i++)
    {
        i[ps] = ps[i - 1];
        if (strncmp(S + i, s + 1, n) == 0)
            ++ps[i];
    }
    while (t--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", (r - n + 1 >= l - 1 ? ps[r - n + 1] - ps[l - 1] : 0));
    }
    free(ps);
    return 0;
}