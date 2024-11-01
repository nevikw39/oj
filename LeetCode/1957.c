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

#include "1957.h"

int main()
{
    char a[] = "leeetcode", b[] = "aaabaaaa", c[] = "aab";
    assert(!strcmp(makeFancyString(a), "leetcode"));
    assert(!strcmp(makeFancyString(b), "aabaa"));
    assert(!strcmp(makeFancyString(c), "aab"));
    return 0;
}
