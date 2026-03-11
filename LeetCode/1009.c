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

#include "1009.h"

int main()
{
    assert(bitwiseComplement(5) == 2);
    assert(bitwiseComplement(7) == 0);
    assert(bitwiseComplement(10) == 5);
    assert(bitwiseComplement(0) == 1);
    return 0;
}
