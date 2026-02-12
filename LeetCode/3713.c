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

#include "3713.h"

int main()
{
    assert(longestBalanced("abbac") == 4);
    assert(longestBalanced("zzabccy") == 3);
    assert(longestBalanced("aba") == 2);
    return 0;
}
