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

#include "2147.h"

int main()
{
    assert(numberOfWays("SSPPSPS") == 3);
    assert(numberOfWays("PPSPSP") == 1);
    assert(numberOfWays("S") == 0);
    return 0;
}
