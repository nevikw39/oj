#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
vector<int> s, l;
vector<string> v;
vector<vector<int>> d, ded;
gp_hash_table<string, int> m;
int inline foo(const string &x)
{
    if (m.find(x) != m.end())
        return m[x];
    s.push_back(0);
    v.push_back(x);
    d.emplace_back();
    ded.emplace_back();
    return m[x] = v.size() - 1;
}
void install(int x, bool flag)
{
    if (s[x])
        return;
    for (const int &i : d[x])
        install(i, false);
    cout << "   Installing " << v[x] << '\n';
    s[x] = flag + 1;
    l.push_back(x);
}
bool inline isneeded(int x)
{
    for (const int &i : ded[x])
        if (s[i])
            return true;
    return false;
}
void remove(int x, bool flag)
{
    if (!(flag || s[x] == 1) || isneeded(x))
        return;
    s[x] = 0;
    l.erase(remove(l.begin(), l.end(), x), l.end());
    cout << "   Removing " << v[x] << '\n';
    for (const int &i : d[x])
        remove(i, false);
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string str;
    while (getline(cin, str))
    {
        cout << str << '\n';
        stringstream ss(str);
        ss >> str;
        if (str == "DEPEND")
        {
            ss >> str;
            int x = foo(str);
            while (ss >> str)
            {
                int y = foo(str);
                d[x].push_back(y);
                ded[y].push_back(x);
            }
        }
        else if (str == "INSTALL")
        {
            ss >> str;
            int x = foo(str);
            if (s[x])
            {
                cout << "   " << str << " is already installed.\n";
                continue;
            }
            install(x, true);
        }
        else if (str == "REMOVE")
        {
            ss >> str;
            int x = foo(str);
            if (!s[x])
                cout << "   " << str << " is not installed.\n";
            else if (isneeded(x))
                cout << "   " << str << " is still needed.\n";
            else
                remove(x, true);
        }
        else if (str == "LIST")
            for (const int &i : l)
                cout << "   " << v[i] << '\n';
    }
    return 0;
}