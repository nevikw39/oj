#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "0191.h"

int main()
{
    printf("%d\n%d\n%d\n", hammingWeight(0b1011), hammingWeight(0b10000000), hammingWeight(0b11111111111111111111111111111101));
    return 0;
}
