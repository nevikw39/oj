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

#include "3223.h"

int main()
{
    assert(minimumLength("abaacbcbb") == 5);
    assert(minimumLength("aa") == 2);
}
