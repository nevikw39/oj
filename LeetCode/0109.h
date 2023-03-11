/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

struct TreeNode *f(struct ListNode *head, struct ListNode *tail)
{
    if (head == tail)
        return NULL;
    struct ListNode *mid = head, *ptr = head;
    while (ptr != tail && ptr->next != tail)
    {
        mid = mid->next;
        ptr = ptr->next->next;
    }
    struct TreeNode *y = malloc(sizeof(struct TreeNode));
    y->val = mid->val;
    y->left = f(head, mid);
    y->right = f(mid->next, tail);
    return y;
}

struct TreeNode *sortedListToBST(struct ListNode *head) { return f(head, NULL); }
