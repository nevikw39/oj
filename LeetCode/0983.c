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

#include "0983.h"

int main()
{
    int a0[] = {1, 4, 6, 7, 8, 20}, a1[] = {2, 7, 15}, b0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, b1[] = {2, 7, 15};
    printf("%d\n%d\n", mincostTickets(a0, sizeof(a0) / sizeof(int), a1, 3), mincostTickets(b0, sizeof(b0) / sizeof(int), b1, 3));
    return 0;
}
