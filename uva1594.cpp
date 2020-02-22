#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        for (int i = 0; i < 1000; i++)
        {
            vector<int> w(n);
            for (int j = 0; j < n; j++)
                w[j] = abs(v[j] - v[(j + 1) % n]);
            v = move(w);
        }
        cout << (all_of(v.begin(), v.end(), [](int x) { return !x; }) ? "ZERO\n" : "LOOP\n");
    }
    return 0;
}