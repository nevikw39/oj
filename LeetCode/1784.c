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

#include "1784.h"

int main()
{
    assert(checkOnesSegment("1001") == true);
    assert(checkOnesSegment("110") == false);
    return 0;
}
