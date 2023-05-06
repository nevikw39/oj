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

inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }

void solve()
{
    int n, a = INT_MAX, b = INT_MAX, ab = INT_MAX;
    scanf("%d", &n);
    while (n--)
    {
        int m;
        char s[3];
        scanf("%d%s", &m, s);
        switch (s[0] - '0' << 1 | s[1] - '0')
        {
        case 0b01:
            a = bwmin(a, m);
            break;
        case 0b10:
            b = bwmin(b, m);
            break;
        case 0b11:
            ab = bwmin(ab, m);
        }
    }
    int r = bwmin(a != INT_MAX && b != INT_MAX ? a + b : INT_MAX, ab);
    printf("%d\n", r != INT_MAX ? r : -1);
}

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
        solve();
    return 0;
}
