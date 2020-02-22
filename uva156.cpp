#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string str;
    set<string> s;
    map<string, string> m;
    while (cin >> str && str != "#")
    {
        string t = str;
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        sort(t.begin(), t.end());
        if (m.count(t))
            m[t] = "#";
        else
            m[t] = str;
    }
    vector<string> v;
    for (const auto &i : m)
        if (i.second != "#")
            v.push_back(i.second);
    sort(v.begin(), v.end());
    for (const auto &i : v)
        cout << i << '\n';
    return 0;
}