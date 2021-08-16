#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    tree<int, int, greater<int>> t;
    int n;
    cin >> n;
    while (n--)
    {
        int p, q;
        cin >> p >> q;
        t[p] += q;
    }
    cin >> n;
    while (n--)
    {
        int p, q;
        cin >> p >> q;
        t[p] += q;
    }
    t.erase_if([](const auto &x) { return !x.second; });
    if (t.empty())
        cout << "NULL!\n";
    else
        for (const auto &i : t)
            cout << i.first << ':' << i.second << '\n';
    return 0;
}