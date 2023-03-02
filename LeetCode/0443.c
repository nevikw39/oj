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

#include "0443.h"

int main()
{
    char a[] = "aabbccc", b[] = "a", c[] = "abbbbbbbbbbbb";
    printf("%d\n%d\n%d\n",
           compress(a, 7),
           compress(b, 1),
           compress(c, 13));
    return 0;
}
