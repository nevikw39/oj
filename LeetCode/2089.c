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

#include "2089.h"

int main()
{
    int a[] = {1, 2, 5, 2, 3}, b[] = {1, 2, 5, 2, 3}, c[] = {1, 2, 5, 2, 3}, null;
    const int ca[] = {1, 2}, cb[] = {3}, cc[] = {4};
    assert(!memcmp(targetIndices(a, sizeof a / sizeof *a, 2, &null), ca, sizeof(ca)));
    assert(!memcmp(targetIndices(b, sizeof b / sizeof *b, 3, &null), cb, sizeof(cb)));
    assert(!memcmp(targetIndices(c, sizeof c / sizeof *c, 5, &null), cc, sizeof(cc)));
    return 0;
}
