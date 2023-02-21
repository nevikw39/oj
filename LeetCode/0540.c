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

#include "0540.h"

int main()
{
    int a[] = {1, 1, 2, 3, 3, 4, 4, 8, 8}, b[] = {3, 3, 7, 7, 10, 11, 11};
    printf("%d\n%d\n", singleNonDuplicate(a, sizeof(a) / sizeof(int)), singleNonDuplicate(b, sizeof(b) / sizeof(int)));
    return 0;
}
