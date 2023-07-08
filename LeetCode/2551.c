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

#include "2551.h"

int main()
{
    int a[] = {1, 3, 5, 1}, b[] = {1, 3};
    printf("%d\n%d\n",
           putMarbles(a, sizeof a / sizeof(int), 2),
           putMarbles(b, sizeof b / sizeof(int), 2));
    return 0;
}
