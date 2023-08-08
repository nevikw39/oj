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

#include "0033.h"

int main()
{
    int a[] = {4, 5, 6, 7, 0, 1, 2}, b[] = {4, 5, 6, 7, 0, 1, 2}, c[] = {1}, d[] = {3, 1};
    printf("%d\n%d\n%d\n%d\n",
           search(a, sizeof a / sizeof(int), 0),
           search(b, sizeof b / sizeof(int), 3),
           search(c, sizeof c / sizeof(int), 0),
           search(d, sizeof d / sizeof(int), 3));
    return 0;
}
