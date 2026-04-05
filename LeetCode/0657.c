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

#include "0657.h"

int main()
{
    assert(judgeCircle("UD") == true);
    assert(judgeCircle("LL") == false);
    return 0;
}
