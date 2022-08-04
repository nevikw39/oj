#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "0858.h"

int main()
{
    printf("%d\n%d\n", mirrorReflection(2, 1), mirrorReflection(3, 1));
    return 0;
}
