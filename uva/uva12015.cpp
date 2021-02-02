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
    for (int i = 0; i < t;)
    {
        vector<pair<string, int>> v;
        for (int _ = 10; _; _--)
        {
            int n;
            string s;
            cin >> s >> n;
            v.push_back({s, n});
        }
        stable_sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) { return a.second > b.second; });
        cout << "Case #" << ++i << ":\n";
        for (const auto &j : v)
        {
            if (j.second != v.front().second)
                break;
            cout << j.first << '\n';
        }
    }
    return 0;
}