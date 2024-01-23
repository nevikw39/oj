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

#include "1239.h"

int main()
{
    char *a[] = {"un", "iq", "ue"}, *b[] = {"cha", "r", "act", "ers"}, *c[] = {"abcdefghijklmnopqrstuvwxyz"};
    printf("%d\n%d\n%d\n",
           maxLength(a, sizeof a / sizeof(char *)),
           maxLength(b, sizeof b / sizeof(char *)),
           maxLength(c, sizeof c / sizeof(char *)));
    return 0;
}
