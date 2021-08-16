#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q, t = 0;
    while (cin >> n >> q && n)
    {
        cout << "CASE# " << ++t << ":\n";
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        while (q--)
        {
            int tmp;
            cin >> tmp;
            auto it = lower_bound(v.begin(), v.end(), tmp);
            if (*it == tmp)
                cout << tmp << " found at " << it - v.begin() + 1 << '\n';
            else
                cout << tmp << " not found\n";
        }
    }
    return 0;
}