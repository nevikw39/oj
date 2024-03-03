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

#include "0019.h"

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
    int a[] = {1, 2, 3, 4, 5}, aa[] = {1, 2, 3, 5}, b[] = {1}, bb[] = {}, c[] = {1, 2}, cc[] = {1};
    struct ListNode *l_a = new_list(a, sizeof a / sizeof(int)),
                    *l_aa = new_list(aa, sizeof aa / sizeof(int)),
                    *l_b = new_list(b, sizeof b / sizeof(int)),
                    *l_bb = new_list(bb, sizeof bb / sizeof(int)),
                    *l_c = new_list(c, sizeof c / sizeof(int)),
                    *l_cc = new_list(cc, sizeof cc / sizeof(int));
    assert(cmp_list(removeNthFromEnd(l_a, 2), l_aa));
    assert(cmp_list(removeNthFromEnd(l_b, 1), l_bb));
    assert(cmp_list(removeNthFromEnd(l_c, 1), l_cc));
    free(l_a);
    free(l_aa);
    free(l_b);
    free(l_bb);
    free(l_c);
    free(l_cc);
    return 0;
}
