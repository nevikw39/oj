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

#include "0201.h"

int main()
{
    printf("%d\n%d\n%d\n",
           rangeBitwiseAnd(5, 7),
           rangeBitwiseAnd(0, 0),
           rangeBitwiseAnd(1, 2147483647));
    return 0;
}
