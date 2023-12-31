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

#include "1624.h"

int main()
{
    printf("%d\n%d\n%d\n%d\n",
           maxLengthBetweenEqualCharacters("aa"),
           maxLengthBetweenEqualCharacters("abca"),
           maxLengthBetweenEqualCharacters("cbzxy"),
           maxLengthBetweenEqualCharacters("mgntdygtxrvxjnwksqhxuxtrv"));
    return 0;
}
