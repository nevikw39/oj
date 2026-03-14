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

int main()
{
    int n, l, r;
    scanf("%d%d%d\n", &n, &l, &r);
    char s[n + 1];
    scanf("%s", s);
    int ps[26][n];
    for (int k = 0; k < 26; k++)
        memset(k[ps], 0, sizeof(int) * n);
    for (int j = 0; j < n; j++)
        ps[j[s] - 'a'][j] = 1;
    for (int k = 0; k < 26; k++)
        for (int j = 1; j < n; j++)
            ps[k][j] += ps[k][j - 1];
    int64_t sum = 0;
    for (int j = 0; j < n; j++)
        if (j >= l)
            sum += ps[j[s] - 'a'][j - l] - (j > r ? ps[j[s] - 'a'][j - r - 1] : 0);
    printf("%" PRId64 "\n", sum);
    return 0;
}
