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

#include "3666.h"

int main()
{
    assert(minOperations("110", 1) == 1);
    assert(minOperations("0101", 3) == 2);
    assert(minOperations("101", 2) == -1);
    return 0;
}
