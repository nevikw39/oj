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

int maxScoreSightseeingPair(int *values, int valuesSize)
{
    int d = 0, p = *values;
    for (int i = 1; i < valuesSize; i++)
    {
        d = bwmax(d, p + values[i] - i);
        p = bwmax(p, values[i] + i);
    }
    return d;
}
