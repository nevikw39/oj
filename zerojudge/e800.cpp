#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    __gnu_pbds::tree<pair<double, int>, string, greater<pair<double, int>>> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        int p, l, w, r;
        cin >> s >> p >> l >> w >> r;
        m.insert({{p * static_cast<double>(w) / l * r, i}, s});
    }
    for (const auto &i : m)
        cout << i.second << '\n';
    return 0;
}