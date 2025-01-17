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

#include "2683.h"

int main()
{
    int a[] = {1, 1, 0}, b[] = {1, 1}, c[] = {1, 0}; 
    assert(doesValidArrayExist(a, sizeof a / sizeof(int)) == true);
    assert(doesValidArrayExist(b, sizeof b / sizeof(int)) == true);
    assert(doesValidArrayExist(c, sizeof c / sizeof(int)) == false);
    return 0;
}
