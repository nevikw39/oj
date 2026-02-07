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

#include "1653.h"

int main()
{
    assert(minimumDeletions("aababbab") == 2);
    assert(minimumDeletions("bbaaaaabb") == 2);
    return 0;
}
