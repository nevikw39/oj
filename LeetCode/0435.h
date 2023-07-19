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

int cmp(const int *const *const l, const int *const *const r) { return 1[*l] - 1[*r]; }

int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
    qsort(intervals, intervalsSize, sizeof(int *), cmp);
    int y = 0;
    for (int i = INT_MIN; intervalsSize--; intervals++)
        if (i <= **intervals)
            i = 1[*intervals];
        else
            ++y;
    return y;
}
