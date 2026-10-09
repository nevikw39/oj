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

#include "1541.h"

int main()
{
    assert(minInsertions("(()))") == 1);
    assert(minInsertions("())") == 0);
    assert(minInsertions("))())(") == 3);
    return 0;
}
