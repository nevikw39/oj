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

inline int bwmin(int l, int r) { return r ^ ((l ^ r) & -(l < r)); }
inline int bwmax(int l, int r) { return l ^ ((l ^ r) & -(l < r)); }

int minTaps(int n, int *ranges, int rangesSize)
{
    int *arr = calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        int l = bwmax(0, i - ranges[i]), r = bwmin(n, i + ranges[i]);
        arr[l] = bwmax(arr[l], r);
    }
    int y = 0;
    for (int i = 0, cur = 0, nxt = 0; i <= n; nxt = bwmax(nxt, arr[i++]))
        if (nxt < i)
            return -1;
        else if (cur < i)
        {
            cur = nxt;
            ++y;
        }
    free(arr);
    return y;
}
