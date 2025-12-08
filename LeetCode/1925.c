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

#include "1925.h"

int main()
{
    assert(countTriples(5) == 2);
    assert(countTriples(10) == 4);
    assert(countTriples(12) == 4);
    return 0;
}
