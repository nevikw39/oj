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

#include "0953.h"

int main()
{
    char *a[] = {"hello", "leetcode"}, *b[] = {"word", "world", "row"}, *c[] = {"apple", "app"};
    printf("%d\n%d\n%d\n",
           isAlienSorted(a, 2, "hlabcdefgijkmnopqrstuvwxyz"),
           isAlienSorted(b, 3, "worldabcefghijkmnpqstuvxyz"),
           isAlienSorted(c, 2, "abcdefghijklmnopqrstuvwxyz"));
    return 0;
}
