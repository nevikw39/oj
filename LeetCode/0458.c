#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "0458.h"

int main()
{
    printf("%d\n%d\n%d\n", poorPigs(1000, 15, 60), poorPigs(4, 15, 15), poorPigs(4, 15, 30));
    return 0;
}
