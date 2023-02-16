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

struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *l = NULL, **ptr1 = &head, **ptr2 = &l;
    for (struct ListNode *cur = head; cur; cur = cur->next)
        if (cur->val < x)
        {
            *ptr1 = cur;
            ptr1 = &(*ptr1)->next;
        }
        else
        {
            *ptr2 = cur;
            ptr2 = &(*ptr2)->next;
        }
    *ptr1 = l;
    *ptr2 = NULL;
    return head;
}
