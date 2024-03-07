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

struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *tortoise = head, *hare = head;
    while (hare && hare->next)
    {
        hare = hare->next->next;
        tortoise = tortoise->next;
    }
    return tortoise;
}
