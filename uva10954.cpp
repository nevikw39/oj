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
    long long n;
    while (cin >> n && n)
    {
        __gnu_pbds::priority_queue<int, greater<int>> q;
        while (n--)
        {
            int t;
            cin >> t;
            q.push(t);
        }
        int r = 0;
        for (;;)
        {
            int a = q.top(), b;
            q.pop();
            b = q.top();
            q.pop();
            r += a + b;
            if (q.empty())
                break;
            q.push(a + b);
        }
        cout << r << '\n';
    }
    return 0;
}