#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    set<pair<int, int>> s;
    while (n--)
    {
        int v, w;
        cin >> v >> w;
        if (v > w)
            swap(v, w);
        if (v == w || s.count({v, w}))
        {
            cout << "Yes\n";
            return 0;
        }
        s.emplace(v, w);
    }
    cout << "yes\n";
    return 0;
}