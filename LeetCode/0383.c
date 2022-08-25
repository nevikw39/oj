#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "0383.h"

int main()
{
    printf("%d\n%d\n%d\n", canConstruct("a", "b"), canConstruct("aa", "ab"), canConstruct("aa", "aab"));
    return 0;
}
