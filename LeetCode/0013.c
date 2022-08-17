#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "0013.h"

int main()
{
    printf("%d\n%d\n%d\n", romanToInt("III"), romanToInt("LVIII"), romanToInt("MCMXCIV"));
    return 0;
}
