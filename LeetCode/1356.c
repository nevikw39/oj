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

#include "1356.h"

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8}, brr[] = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1}, x;
    const int carr[] = {0, 1, 2, 4, 8, 3, 5, 6, 7}, cbrr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    assert(!memcmp(sortByBits(arr, sizeof arr / sizeof *arr, &x), carr, sizeof carr));
    assert(!memcmp(sortByBits(brr, sizeof brr / sizeof *brr, &x), cbrr, sizeof cbrr));
    return 0;
}
