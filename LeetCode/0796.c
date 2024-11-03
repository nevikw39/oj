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

#include "0796.h"

int main()
{
    assert(rotateString("abcde", "cdeab"));
    assert(!rotateString("abcde", "abced"));
    return 0;
}
