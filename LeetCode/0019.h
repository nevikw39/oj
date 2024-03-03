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

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *ptr = head, *qtr = head;
    while (n--)
        ptr = ptr->next;
    if (!ptr)
        return head->next;
    while (ptr->next)
    {
        ptr = ptr->next;
        qtr = qtr->next;
    }
    ptr = qtr->next->next;
    free(qtr->next);
    qtr->next = ptr;
    return head;
}