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

int maxConsecutiveAnswers(char *answerKey, int k)
{
    int y = k, arr[2] = {};
    for (int i = 0; i < k; i++)
        ++arr[answerKey[i] == 'T'];
    for (int l = 0, r = k, n = strlen(answerKey); r < n; r++)
    {
        ++arr[answerKey[r] == 'T'];
        while (bwmin(*arr, 1[arr]) > k)
            --arr[answerKey[l++] == 'T'];
        y = bwmax(y, r - l + 1);
    }
    return y;
}
