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

#include "1456.h"

int main()
{
    printf("%d\n%d\n%d\n%d\n",
           maxVowels("abciiidef", 3),
           maxVowels("aeiou", 2),
           maxVowels("leetcode", 3),
           maxVowels("twfsikrausdeuelcgiupwktszz", 5));
    return 0;
}
