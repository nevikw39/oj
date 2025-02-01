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

#include "3151.h"

int main()
{
    int a[] = {1}, b[] = {2, 1, 4}, c[] = {4, 3, 1, 6}; 
    assert(isArraySpecial(a, sizeof a / sizeof(int)) == true);
    assert(isArraySpecial(b, sizeof b / sizeof(int)) == true);
    assert(isArraySpecial(c, sizeof c / sizeof(int)) == false);
    return 0;
}
