#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<string> v;
    gp_hash_table<string, null_type> g;
    string s;
    while (cin >> s)
        g.insert(s), v.push_back(s);
    for (const auto &i : v)
    {
        int l = i.length();
        for (int j = 0; j < l - 1; j++)
        {
            string a = i.substr(0, j + 1), b = i.substr(j + 1, l - 1 - j);
            if (g.find(a) != g.end() && g.find(b) != g.end())
            {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}