#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    map<int, map<int, int>> m;
    map<string, int> ma, mp;
    vector<string> va, vp;
    while (n--)
    {
        string a, p;
        int t;
        cin >> a >> t >> p;
        if (!ma.count(a))
        {
            ma[a] = va.size();
            va.push_back(a);
        }
        if (!mp.count(p))
        {
            mp[p] = vp.size();
            vp.push_back(p);
        }
        m[mp[p]][ma[a]] += t;
    }
    for (const auto &i : m)
    {
        cout << vp[i.first] << " :";
        for (auto jtr = i.second.begin(); jtr != i.second.end(); jtr++)
            cout << (jtr == i.second.begin() ? " " : ", ") << va[jtr->first] << ' ' << jtr->second;
        cout << '\n';
    }
    return 0;
}