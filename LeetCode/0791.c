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

#include "0791.h"

int main()
{
    puts(customSortString("cba", "abcd"));
    puts(customSortString("bcafg", "abcd"));
    return 0;
}
