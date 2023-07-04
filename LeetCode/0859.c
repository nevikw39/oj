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

#include "0859.h"

int main()
{
    puts(buddyStrings("ab", "ba") ? "true" : "false");
    puts(buddyStrings("ab", "ab") ? "true" : "false");
    puts(buddyStrings("aa", "aa") ? "true" : "false");
    puts(buddyStrings("abcaa", "abcbb") ? "true" : "false");
    return 0;
}
