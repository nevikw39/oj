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
    int n, k;
    int64_t m;
    scanf("%d%d%" PRId64 "", &n, &k, &m);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    int64_t sum = 0, cnt = 0;
    for (int l = 0, r = 0; l < n; l++)
    {
        while (r < n && (r - l < k || sum < m))
            sum += a[r++];
        if (r - l >= k && sum >= m)
            cnt += n - r + 1;
        sum -= l[a];
    }
    printf("%" PRId64 "\n", cnt);
    return 0;
}
