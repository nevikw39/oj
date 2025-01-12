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

#include "2116.h"

int main()
{
    assert(canBeValid("))()))", "010100") == true);
    assert(canBeValid("()()", "0000") == false);
    assert(canBeValid(")", "0") == true);
    return 0;
}
