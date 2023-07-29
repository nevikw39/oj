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

#include "0808.h"

int main()
{
    printf("%lf\n%lf\n",
           soupServings(50),
           soupServings(100));
    return 0;
}
