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

#include "3133.h"

int main()
{
    assert(minEnd(3, 4) == 6);
    assert(minEnd(2, 7) == 15);
    return 0;
}
