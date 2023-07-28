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

#include "0486.h"

int main()
{
    int a[] = {1, 5, 2}, b[] = {1,5,233,7};
    printf("%d\n%d\n",
           PredictTheWinner(a, sizeof a / sizeof(int)),
           PredictTheWinner(b, sizeof b / sizeof(int)));
    return 0;
}
