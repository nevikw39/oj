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

#include "3783.h"

int main()
{
    assert(mirrorDistance(25) == 27);
    assert(mirrorDistance(10) == 9);
    assert(mirrorDistance(7) == 0);
    return 0;
}
