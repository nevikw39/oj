#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    gp_hash_table<int, int> times, ord;
    while (n--)
    {
        int r;
        cin >> r;
        times[r]++;
        ord[r] = min(ord[r] ?: INT_MAX, 1001 - n);
    }
    cout << times.size() << '\n';
    vector<pair<pair<int, int>, int>> v;
    for (const auto &i : times)
        v.push_back({{i.second, ord[i.first]}, i.first});
    sort(v.begin(), v.end());
    int x = v.back().first.first;
    if (x == 1)
        cout << "NO\n";
    else
        for (const auto &i : v)
            if (i.first.first == x)
                cout << i.second << ' ';
    return 0;
}