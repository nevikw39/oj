#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1689.h"

int main()
{
    printf("%d\n%d\n%d\n", minPartitions("32"), minPartitions("82734"), minPartitions("27346209830709182346"));
    return 0;
}
