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

inline int64_t bwmin(int l, int64_t r) { return r ^ ((l ^ r) & -(l < r)); }

bool f(int n, int *batteries, int batteriesSize, int64_t target_time)
{
    int64_t avail_time = 0;
    while (batteriesSize--)
        avail_time += bwmin(*batteries++, target_time);
    return avail_time >= n * target_time;
}

long long maxRunTime(int n, int *batteries, int batteriesSize)
{
    int64_t time = 0, sum = 0;
    for (int *ptr = batteries; ptr < batteries + batteriesSize; ptr++)
        sum += *ptr;
    if (sum == n)
        return 1;
    for (int64_t jump = sum / n >> 1; jump; jump >>= 1)
        while (time + jump <= sum / n && f(n, batteries, batteriesSize, time + jump))
            time += jump;
    return time;
}
