#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> v(n);
    vector<pair<int, int>> vp{{h, m}};
    for (int &i : v)
    {
        cin >> i;
        m += i;
        h += m / 60;
        m %= 60;
        h %= 24;
        vp.push_back({h, m});
    }
    int p;
    while (cin >> p && p)
        cout << setw(2) << setfill('0') << vp[p].first << ':' << setw(2) << setfill('0') << vp[p].second << '\n';
    return 0;
}
