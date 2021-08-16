#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int d, i, k = 1;
        cin >> d >> i;
        for (int _ = 1; _ < d; _++)
            if (i & 1)
            {
                k <<= 1;
                i = (i + 1) >> 1;
            }
            else
            {
                k = k << 1 | 1;
                i >>= 1;
            }
        cout << k << '\n';
    }
    return 0;
}