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

#include "2616.h"

int main()
{
    int a[] = {10, 1, 2, 7, 1, 3}, b[] = {4, 2, 1, 2}, c[] = {4, 0, 2, 1, 2, 5, 5, 3}, d[] = {0, 5, 3, 4};
    printf("%d\n%d\n%d\n%d\n",
           minimizeMax(a, sizeof a / sizeof(int), 2),
           minimizeMax(b, sizeof b / sizeof(int), 1),
           minimizeMax(c, sizeof c / sizeof(int), 3),
           minimizeMax(d, sizeof d / sizeof(int), 0));
    return 0;
}
