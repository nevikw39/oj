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

#include "0006.h"

int main()
{
    puts(convert("PAYPALISHIRING", 3));
    puts(convert("PAYPALISHIRING", 4));
    puts(convert("A", 1));
    return 0;
}
