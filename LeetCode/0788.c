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

#include "0788.h"

int main()
{
    assert(rotatedDigits(10) == 4);
    assert(rotatedDigits(1) == 0);
    assert(rotatedDigits(2) == 1);
    return 0;
}
