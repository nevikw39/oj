#include <assert.h>
#include <ctype.h>
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

#include "1657.h"

int main()
{
    printf("%d\n%d\n%d\n%d\n",
           closeStrings("abc", "bca"),
           closeStrings("a", "aa"),
           closeStrings("cabbba", "abbccc"),
           closeStrings("uau", "ssx"));
    return 0;
}
