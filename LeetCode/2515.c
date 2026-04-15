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

#include "2515.h"

int main()
{
    const char *a[] = {"hello", "i", "am", "leetcode", "hello"}, *b[] = {"a", "b", "leetcode"}, *c[] = {"i", "eat", "leetcode"};
    assert(closestTarget(a, sizeof a / sizeof *a, "hello", 1) == 1);
    assert(closestTarget(b, sizeof b / sizeof *b, "leetcode", 0) == 1);
    assert(closestTarget(c, sizeof c / sizeof *c, "ate", 0) == -1);
    return 0;
}
