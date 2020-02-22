#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    bool flag = false;
    while (cin >> n && n)
    {
        if (flag)
            cout.put('\n');
        else
            flag = true;
        bool r = false;
        for (int i = 1234; i * n <= 98765; i++)
        {
            bitset<10> bs;
            if (i < 10000)
                bs[0] = true;
            for (int j = i; j; j /= 10)
                bs[j % 10] = true;
            for (int j = i * n; j; j /= 10)
                bs[j % 10] = true;
            if (bs.count() != 10)
                continue;
            cout << setfill('0') << setw(5) << i * n << " / " << setfill('0') << setw(5) << i << " = " << n << '\n';
            r = true;
        }
        if (!r)
            cout << "There are no solutions for " << n << ".\n";
    }
    return 0;
}