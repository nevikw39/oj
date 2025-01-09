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

#include "2185.h"

int main()
{
    const char *const a[] = {"pay","attention","practice","attend"}, *const b[] = {"leetcode","win","loops","success"};
    assert(prefixCount(a, sizeof a / sizeof(char *), "at") == 2);
    assert(prefixCount(b, sizeof b / sizeof(char *), "code") == 0);
    return 0;
}
