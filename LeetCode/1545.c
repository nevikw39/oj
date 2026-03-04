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

#include "1545.h"

int main()
{
    assert(findKthBit(3, 1) == '0');
    assert(findKthBit(4, 11) == '1');
    return 0;
}
