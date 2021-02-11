#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    gp_hash_table<string, tree<string, null_type>> ht;
    int n;
    cin >> n;
    while (n--)
    {
        string f, s;
        cin >> f >> s;
        ht[s].insert(f);
    }
    string c;
    cin >> c;
    if (ht[c].empty())
        cout << "No\n";
    else
        for (const auto &i : ht[c])
            cout << i << '\n';
    return 0;
}