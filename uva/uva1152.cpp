#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    bool flag = false;
    int t;
    cin >> t;
    while (t--)
    {
        if (flag)
            cout << '\n';
        else
            flag = true;
        int n, r = 0;
        cin >> n;
        vector<int> a(n), b(n), c(n), d(n);
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        cc_hash_table<int, int> x;
        for (const int &i : a)
            for (const int &j : b)
                x[i + j]++;
        for (const int &i : c)
            for (const int &j : d)
                r += x[-i - j];
        cout << r << '\n';
    }
    return 0;
}