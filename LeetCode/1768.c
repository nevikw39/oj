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

#include "1768.h"

int main()
{
    puts(mergeAlternately("abc", "pqr"));
    puts(mergeAlternately("ab", "pqrs"));
    puts(mergeAlternately("abcd", "pq"));
    return 0;
}
