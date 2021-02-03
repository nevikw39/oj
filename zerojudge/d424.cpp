#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    map<int, pair<vector<int>, vector<int>>> m;
    multiset<int> s{0};
    vector<pair<int, int>> v;
    int l, h, r;
    while (cin >> l >> h >> r)
    {
        m[l].first.push_back(h);
        m[r].second.push_back(h);
    }
    for (const auto &i : m)
    {
        for (const int &j : i.second.first)
            s.insert(j);
        for (const int &j : i.second.second)
            s.erase(s.find(j));
        int h = *s.rbegin();
        if (v.empty() || v.back().second != h)
            v.emplace_back(i.first, h);
    }
    for (int i = 0, l = v.size(); i < l; i++)
        cout << v[i].first << ' ' << v[i].second << " \n"[i + 1 == l];
    return 0;
}