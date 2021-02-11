#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using pps = pair<pair<char, char>, string>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pps> v(n);
    for (auto &i : v)
    {
        string id, s;
        cin >> id >> s;
        i = {{id.back(), id.front()}, s};
    }
    stable_sort(v.begin(), v.end(), [](pps l, pps r) { return l.first < r.first; });
    for (const auto &i : v)
        cout << i.first.first << ':' << i.second << '\n';
    return 0;
}