#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r = 0;
    cin >> n;
    vector<pair<int, int>> v[6];
    while (n--)
    {
        int d, s, t;
        cin >> d >> s >> t;
        v[d].push_back({s, t});
    }
    for (auto &i : v)
    {
        if (i.empty())
            continue;
        sort(i.begin(), i.end(), [](pair<int, int> l, pair<int, int> r) { return l.second < r.second; });
        int tmp = -1;
        for (const auto &j : i)
            if (tmp <= j.first)
            {
                r++;
                tmp = j.second;
            }
    }
    cout << r;
    return 0;
}