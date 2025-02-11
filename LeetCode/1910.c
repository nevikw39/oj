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

#include "1910.h"

int main()
{
    assert(!strcmp(removeOccurrences("daabcbaabcbc", "abc"), "dab"));
    assert(!strcmp(removeOccurrences("axxxxyyyyb", "xy"), "ab"));
    return 0;
}
