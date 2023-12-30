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

#include "1897.h"

int main()
{
    char *a[] = {"abc", "aabc", "bc"}, *b[] = {"ab", "a"};
    printf("%d\n%d\n",
           makeEqual(a, sizeof a / sizeof(void *)),
           makeEqual(b, sizeof b / sizeof(void *)));
    return 0;
}
