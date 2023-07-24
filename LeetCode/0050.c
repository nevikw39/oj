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

#include "0050.h"

int main()
{
    printf("%lf\n%lf\n%lf\n%lf\n",
           myPow(2., 10),
           myPow(2.1, 3),
           myPow(2., -2),
           myPow(2., INT_MIN));
    return 0;
}
