#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
using pci = pair<char, int>;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore(1, '\n');
    gp_hash_table<char, int> m;
    vector<pci> v;
    while (n--)
    {
        string s;
        getline(cin, s);
        s.erase(remove_if(s.begin(), s.end(), [](char x) { return !isalpha(x); }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        for (const char &c : s)
            m[c]++;
    }
    move(m.begin(), m.end(), back_inserter(v));
    sort(v.begin(), v.end(), [](pci a, pci b) { return a.second == b.second ? a.first < b.first : a.second > b.second; });
    for (const auto &i : v)
        cout << i.first << ' ' << i.second << endl;
    return 0;
}