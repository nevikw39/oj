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
    struct ListNode *head, **ptr = &head;
    for (; list1 && list2; ptr = &(*ptr)->next)
        if (list1->val < list2->val)
        {
            *ptr = list1;
            list1 = list1->next;
        }
        else
        {
            *ptr = list2;
            list2 = list2->next;
        }
    *ptr = list1 ?: list2;
    return head;
}
