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

#include "1704.h"

int main()
{
    printf("%d\n%d\n",
           halvesAreAlike("book"),
           halvesAreAlike("textbook"),
           halvesAreAlike("AbCdEfGh"));
    return 0;
}
