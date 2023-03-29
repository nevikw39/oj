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

inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }
int cmp(int *l, int *r) { return *r - *l; }

int maxSatisfaction(int *satisfaction, int satisfactionSize)
{
    qsort(satisfaction, satisfactionSize, sizeof(int), cmp);
    int y = 0, pre = 0, sum = 0;
    while (satisfactionSize--)
        y = bwmax(y, pre += (sum += *satisfaction++));
    return y;
}
