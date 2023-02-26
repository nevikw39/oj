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

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include "0226.h"

int main()
{
    struct TreeNode arr[3];
    memset(arr, 0, sizeof(arr));
    arr->left = arr + 1;
    arr->right = arr + 2;
    arr->val = 2;
    arr[1].val = 1;
    arr[2].val = 3;
    invertTree(arr);
    printf("%d %d %d\n", arr->val, arr[1].val, arr[2].val);
    return 0;
}
