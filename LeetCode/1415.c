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

#include "1415.h"

int main()
{
    assert(!strcmp(getHappyString(1, 3), "c"));
    assert(!strcmp(getHappyString(1, 4), ""));
    assert(!strcmp(getHappyString(3, 9), "cab"));
    assert(!strcmp(getHappyString(10, 100), "abacbabacb"));
    return 0;
}
