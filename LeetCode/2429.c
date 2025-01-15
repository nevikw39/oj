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

#include "2429.h"

int main()
{
    assert(minimizeXor(3, 5) == 3);
    assert(minimizeXor(1, 12) == 3);
    assert(minimizeXor(25, 72) == 24);
    return 0;
}
