/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <assert.h>
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
    int n, cnt = 0;
    scanf("%d", &n);
    int a[n], ps[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        ps[i] = (i ? ps[i - 1] : 0) + a[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            const int sum = ps[i] - (j ? ps[j - 1] : 0);
            bool flag = true;
            for (int k = j; k <= i && flag; k++)
                if (!(sum % a[k]))
                    flag = false;
            if (flag)
                ++cnt;
        }
    printf("%d\n", cnt);
    return 0;
}
