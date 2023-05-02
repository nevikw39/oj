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

#include "1822.h"

int main()
{
    int a[] = {-1, -2, -3, -4, 3, 2, 1}, b[] = {1, 5, 0, 2, -3}, c[] = {-1, 1, -1, 1, -1};
    printf("%d\n%d\n",
           arraySign(a, sizeof a / sizeof(int)),
           arraySign(b, sizeof b / sizeof(int)),
           arraySign(c, sizeof c / sizeof(int)));
    return 0;
}
