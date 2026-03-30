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

#include "2839.h"

int main()
{
    assert(canBeEqual("abcd", "cdab") == true);
    assert(canBeEqual("abcd", "dacb") == false);
    assert(checkStrings("abcdba", "cabdab") == true);
    assert(checkStrings("abe", "bea") == false);
    return 0;
}
