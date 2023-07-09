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

int largestVariance(char *s)
{
    int y = 0;
    for (char i = 'a'; i <= 'z'; i++)
        for (char j = 'a'; j <= 'z'; j++)
            if (i != j)
            {
                int a = 0, b = 0;
                bool flag = false;
                for (char *ptr = s; *ptr; ptr++)
                {
                    if (*ptr == i)
                        ++a;
                    else if (*ptr == j)
                        ++b;
                    if (b > 0)
                        y = bwmax(y, a - b);
                    else if (flag)
                        y = bwmax(y, a - 1);
                    if (a < b)
                    {
                        a = b = 0;
                        flag = true;
                    }
                }
            }
    return y;
}
