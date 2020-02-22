#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    bool flag = true;
    while (getline(cin, s))
    {
        if (flag)
            flag = false;
        else
            cout << '\n';
        tree<char, int> m;
        vector<pair<char, int>> v;
        for (const char &c : s)
            m[c]++;
        move(m.begin(), m.end(), back_inserter(v));
        sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) { return a.second == b.second ? a.first > b.first : a.second < b.second; });
        for (const auto &i : v)
            cout << (short)i.first << ' ' << i.second << '\n';
    }
    return 0;
}