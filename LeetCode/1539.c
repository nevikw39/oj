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

#include "1539.h"

int main()
{
    int a[] = {2, 3, 4, 7, 11}, b[] = {1, 2, 3, 4}, c[] = {1, 2};
    printf("%d\n%d\n%d\n",
           findKthPositive(a, sizeof(a) / sizeof(int), 5),
           findKthPositive(b, sizeof(b) / sizeof(int), 2),
           findKthPositive(c, sizeof(c) / sizeof(int), 1));
    return 0;
}
