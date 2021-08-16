#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
char inline f(int x)
{
    return x < 26 ? 'A' + x : 'a' + x - 26;
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    bool flag = false;
    int n;
    while (cin >> n)
    {
        if (flag)
            cout << '\n';
        else
            flag = true;
        cout << "2 " << n << ' ' << n << '\n';
        for (int i = 0; i < n; i++, cout << '\n')
            for (int j = 0; j < n; j++)
                cout << f(j);
        cout << '\n';
        for (int i = 0; i < n; i++, cout << '\n')
            for (int j = 0; j < n; j++)
                cout << f(i);
    }
    return 0;
}