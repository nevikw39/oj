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

#include "0231.h"

int main()
{
    printf("%d\n%d\n",
           isPowerOfTwo(1),
           isPowerOfTwo(16),
           isPowerOfTwo(3));
    return 0;
}
