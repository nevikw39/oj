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

#include "0518.h"

int main()
{
    int a[] = {1, 2, 5}, b[] = {2}, c[] = {10};
    printf("%d\n%d\n%d\n",
           change(5, a, sizeof a / sizeof(int)),
           change(3, b, sizeof b / sizeof(int)),
           change(10, c, sizeof c / sizeof(int)));
    return 0;
}
