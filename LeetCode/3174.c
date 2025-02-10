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

#include "1790.h"

int main()
{
    assert(areAlmostEqual("bank", "kanb") == true);
    assert(areAlmostEqual("attack", "defend") == false);
    assert(areAlmostEqual("kelb", "kelb") == true);
    return 0;
}
