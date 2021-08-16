#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    uint_fast64_t m, n;
    cin >> m >> n;
    uint_fast64_t u = (1ULL << m) - 1;
    map<uint_fast64_t, int> st;
    while (n--)
    {
        string str;
        cin >> str;
        uint_fast64_t x = 0;
        for (const char &c : str)
            x |= 1ULL << (isupper(c) ? c - 'A' : c - 'a' + 26);
        st[x]++;
    }
    uint_fast64_t r = 0;
    for (const auto &i : st)
        r += st[u ^ i.first] * i.second;
    cout << (r >> 1) << '\n';
    return 0;
}