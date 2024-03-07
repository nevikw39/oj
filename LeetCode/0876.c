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

struct ListNode
{
    int val;
    struct ListNode *next;
};

#include "0876.h"

struct ListNode *new_list(const int *const restrict arr, int n)
{
    if (!n)
        return NULL;
    struct ListNode *y = malloc(sizeof(struct ListNode));
    y->val = *arr;
    y->next = new_list(arr + 1, n - 1);
    return y;
}

bool cmp_list(const struct ListNode *const restrict lhs, const struct ListNode *const restrict rhs)
{
    if (!lhs && !rhs)
        return true;
    if (!lhs ^ !rhs)
        return false;
    return lhs->val == rhs->val && cmp_list(lhs->next, rhs->next);
}

void del_list(const struct ListNode *const restrict head)
{
    if (!head)
        return;
    del_list(head->next);
    free(head);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5}, b[] = {1, 2, 3, 4, 5, 6};
    struct ListNode *l_a = new_list(a, sizeof a / sizeof(int)),
                    *l_b = new_list(b, sizeof b / sizeof(int));
    printf("%d\n", middleNode(l_a)->val);
    printf("%d\n", middleNode(l_b)->val);
    free(l_a);
    free(l_b);
    return 0;
}
