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

#include "0190.h"

int main()
{
    assert(reverseBits(43261596) == 964176192);
    assert(reverseBits(2147483644) == 1073741822);
    return 0;
}
