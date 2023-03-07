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

inline int64_t bwmax(int64_t l, int r) { return l ^ ((l ^ r) & -(l < r)); }

bool f(int *time, int timeSize, int totalTrips, int64_t y)
{
    int64_t cnt = 0;
    while (timeSize--)
        cnt += y / *time++;
    return cnt < totalTrips;
}

long long minimumTime(int *time, int timeSize, int totalTrips)
{
    int64_t n = INT64_MIN, y = 0;
    for (int i = 0; i < timeSize; i++)
        n = bwmax(n, i[time]);
    n *= totalTrips;
    for (int64_t jump = n; jump; jump >>= 1)
        while (y + jump < n && f(time, timeSize, totalTrips, y + jump))
            y += jump;
    return y + 1;
}
