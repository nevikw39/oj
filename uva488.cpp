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
    cin >> n;
    while (n--)
    {
        int a, f;
        cin >> a >> f;
        while (f--)
        {
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < i + 1; j++)
                    cout << i + 1;
                cout << '\n';
            }
            for (int i = a - 1; i; i--)
            {
                for (int j = 0; j < i; j++)
                    cout << i;
                cout << '\n';
            }
            if (n || f)
                cout << '\n';
        }
    }
    return 0;
}