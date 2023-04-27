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

#include "0319.h"

int main()
{
    printf("%d\n%d\n%d\n", bulbSwitch(3), bulbSwitch(0), bulbSwitch(1));
    return 0;
}
