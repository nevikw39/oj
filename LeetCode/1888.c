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

#include "1888.h"

int main()
{
    assert(minFlips("111000") == 2);
    assert(minFlips("010") == 0);
    assert(minFlips("1110") == 1);
    return 0;
}
