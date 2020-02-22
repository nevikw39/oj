#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string a, b;
    while (cin >> a >> b)
    {
        unordered_map<char, int> ma, mb;
        for (const char &c : a)
            ma[c]++;
        for (const char &c : b)
            mb[c]++;
        multiset<int> sa, sb;
        for (const auto &i : ma)
            sa.insert(i.second);
        for (const auto &i : mb)
            sb.insert(i.second);
        cout << (sa == sb ? "YES\n" : "NO\n");
    }
    return 0;
}