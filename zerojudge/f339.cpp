#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    uint64_t n, m;
    cin >> n >> m;
    vector<short> v(n);
    while (m--)
    {
        uint64_t s, e;
        cin >> s >> e;
        for (size_t i = s; i < e; i++)
            v[i] = 1;
    }
    for (size_t i = 0; i < n; i++)
    {
        if (v[i])
            continue;
        cout << i << ' ';
        while (!v[i] && i < n)
            i++;
        cout << i << '\n';
    }
    return 0;
}