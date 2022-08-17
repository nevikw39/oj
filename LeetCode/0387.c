#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "0387.h"

int main()
{
    printf("%d\n%d\n%d\n", firstUniqChar("leetcode"), firstUniqChar("loveleetcode"), firstUniqChar("aabb"));
    return 0;
}
