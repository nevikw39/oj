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

#include "2466.h"

int main()
{
    printf("%d\n%d\n",
           countGoodStrings(2, 3, 1, 1),
           countGoodStrings(2, 3, 1, 2));
    return 0;
}
