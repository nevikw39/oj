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

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *head = NULL, **ptr = &head;
    for (struct ListNode **cur = NULL; list1 && list2; *cur = (*cur)->next, ptr = &(*ptr)->next)
    {
        cur = list1->val < list2->val ? &list1 : &list2;
        *ptr = *cur;
    }
    *ptr = (uintptr_t) list1 | (uintptr_t) list2;
    return head;
}
